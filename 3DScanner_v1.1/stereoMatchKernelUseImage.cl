#define maxsad 999999
#define maxdisp 200
#define mindisp 80
#define rad 10
__kernel void test_kernel_image(__read_only image2d_t imgL,__read_only image2d_t imgR,
								__write_only image2d_t oimage,__global float *LRxyOut,
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
	//F[0]=(float3)( 1.7123198015685324e-009, 1.1321560960528495e-007,-4.4225278451588061e-004);
	//F[1]=(float3)(1.5147010422577803e-007,2.2117948547055852e-007, -6.6608051662709486e-002);
	//F[2]=(float3)( 4.1654236203389846e-004, 6.6230116984000151e-002, 1.0 );

	F[0]=(float3)(2.0927344418688545e-009, 1.2017372389495388e-006,-9.6388001255068539e-004);
	F[1]=(float3)(2.6936878202182016e-007, 5.9920465690256945e-008, -1.1602633233009087e-001);
	F[2]=(float3)( -1.6206874295243174e-005, 1.1500969023984821e-001, 1.0 );
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
	write_imagef(oimage, (int2)(iw, ih), computedFilter);
	}
}