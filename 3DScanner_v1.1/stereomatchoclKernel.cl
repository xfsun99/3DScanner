#define maxsad 999999

#define maxdisp 500
#define mindisp 80
#define rad 13
__kernel void test_kernel_buffer(__global uchar *imgL,__global uchar *imgR,__global int *dispx,
								 __global int *dispy,int offset_wl,int offset_hl,int offset_wr,
								 int offset_hr,int wrd,int wld,int grid)
{
	int iw=get_global_id(0)*grid+rad;
	int ih=get_global_id(1)*grid+rad;
	int id=ih*wld+iw;
	int gob_wl=offset_wl+iw;
	int gob_hl=offset_hl+ih;

	float3 F[3];


	F[0]=(float3)(7.5275281649955183e-010, -2.2720845271822748e-008,-2.6912302382428198e-004);
	F[1]=(float3)(2.1327468501094878e-007,2.0259750865541328e-007, -6.6918147149967369e-002);
	F[2]=(float3)( 2.9387988621421457e-004, 6.6604104776593440e-002, 1.);

	//F[0]=(float3)(2.0927344418688545e-009, 1.2017372389495388e-006,-9.6388001255068539e-004);
	//F[1]=(float3)(2.6936878202182016e-007, 5.9920465690256945e-008, -1.1602633233009087e-001);
	//F[2]=(float3)( -1.6206874295243174e-005, 1.1500969023984821e-001, 1.0 );

	float3 temp;
	float D[3];
	temp=F[0]*(float3)((float)gob_wl,(float)gob_hl,1.0);
	D[0]=temp.x+temp.y+temp.z;
	temp=F[1]*(float3)((float)gob_wl,(float)gob_hl,1.0);
	D[1]=temp.x+temp.y+temp.z;
	temp=F[2]*(float3)((float)gob_wl,(float)gob_hl,1.0);
	D[2]=temp.x+temp.y+temp.z;

    uchar PL[2*rad+1][2*rad+1];
    int i,j,corrx,corry,corrxr,corryr,dis,rmx,rmy;
    for(i=-rad;i<rad;i++)
	{
		corrx=iw+i;
		//#pragma unroll
		for(j=-rad;j<rad;j++)
		{				
			corry=ih+j;	
			id=corry*wld+corrx;
			PL[i+rad][j+rad]=imgL[id];
		}
	}
    int w;
    int sadvalue;
    int minsadvalue=maxsad;
    for(w=max(gob_wl-mindisp-offset_wr,0);w>rad;--w)//max(iw-maxdisp,0)
	{
		sadvalue=0;
        corryr=(-D[0]*(w+offset_wr)-D[2])/D[1]-offset_hr;
		for(i=-rad;i<rad;i++)
		{
			corrxr=w+i;			
			//#pragma unroll
			for(j=-rad;j<rad;j++)
			{				
               id=(corryr+j)*wrd+corrxr;
				sadvalue += abs((int)PL[i+rad][j+rad]-(int)imgR[id]);
			}
		}
		sadvalue=sadvalue/121;
		if(sadvalue<minsadvalue)
		{
			minsadvalue=sadvalue;
			rmx=w+offset_wr;
			rmy=corryr+offset_hr;
		}
	}
	id=ih*wld+iw;
	if(sadvalue<300)
	{		
		dispx[id]=rmx;
		dispy[id]=rmy;
	}
	else
	{
		dispx[id]=0;
		dispy[id]=0;

	}
}
__kernel void test_kernel_image(__read_only image2d_t imgL,__read_only image2d_t imgR,
								__global float *FM,__global float *LRxyOut,
								int start_w,int start_h,int boundl,sampler_t image_sampler,int grid)
{
	int gw=get_global_size(0);
	int gh=get_global_size(1);
	int iw0=get_global_id(0);
	int ih0=get_global_id(1);
	float4 pixelValueL,pixelValueR;
	float PL[2*rad+1][2*rad+1];
	float4 computedFilter=0.0f;
	int i,j,corrx,corry,w,corrxr,corryr,dis,rmx,rmy;
	float minsadvalue=maxsad;
	float3 F[3];

	F[0]=(float3)(FM[0], FM[1],FM[2]);
	F[1]=(float3)(FM[3], FM[4],FM[5]);
	F[2]=(float3)(FM[6], FM[7],FM[8]);

	int iw,ih;
	iw=iw0*grid+rad+start_w;
	ih=ih0*grid+rad+start_h;
	float3 temp;
	float D[3];
	temp=F[0]*(float3)((float)iw,(float)ih,1.0);
	D[0]=temp.x+temp.y+temp.z;
	temp=F[1]*(float3)((float)iw,(float)ih,1.0);
	D[1]=temp.x+temp.y+temp.z;
	temp=F[2]*(float3)((float)iw,(float)ih,1.0);
	D[2]=temp.x+temp.y+temp.z;
	pixelValueL=read_imagef(imgL,image_sampler,(int2)(iw,ih));
	if(pixelValueL.x>0){
	for(i=-rad;i<rad;i++)
	{
		corrx=iw+i;
		//#pragma unroll
		for(j=-rad;j<rad;j++)
		{				
			corry=ih+j;	
			pixelValueL=read_imagef(imgL,image_sampler,(int2)(corrx,corry));
			PL[i+rad][j+rad]=pixelValueL.x;
		}
	}
	for(w=max(iw-mindisp,0);w>boundl;--w)//max(iw-maxdisp,0)
	{
        corryr=(-D[0]*w-D[2])/D[1];    
        pixelValueR=read_imagef(imgR,image_sampler,(int2)(w,corryr));
        if(pixelValueR.x>0){
		for(i=-rad;i<rad;i++)
		{
			corrxr=w+i;			
			//#pragma unroll
			for(j=-rad;j<rad;j++)
			{				
				pixelValueR=read_imagef(imgR,image_sampler,(int2)(corrxr,corryr+j));
				computedFilter.x += fabs(PL[i+rad][j+rad]-pixelValueR.x);
			}
		}
		computedFilter.x=computedFilter.x/121;
		if(computedFilter.x<minsadvalue)
		{
			minsadvalue=computedFilter.x;
			rmx=w;
			rmy=corryr;
		}
		}
	}
	computedFilter=(float4)(rmx,rmy,0,0);
	LRxyOut[ih0*gw+iw0]=iw;
	LRxyOut[gw*gh+ih0*gw+iw0]=ih;
	LRxyOut[2*gw*gh+ih0*gw+iw0]=rmx;
	LRxyOut[3*gw*gh+ih0*gw+iw0]=(-D[0]*rmx-D[2])/D[1];
	//computedFilter = a*pixelValueL+pixelValueR*(1-a);
	//computedFilter = max(pixelValueL,pixelValueR);
	//write_imagef(oimage, (int2)(iw, ih), computedFilter);
	}
}
