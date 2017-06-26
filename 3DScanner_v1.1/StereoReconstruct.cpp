#include"StereoReconstruct.h"
#include "opencv2/imgproc/imgproc.hpp"
StereoReconstruct*StereoReconstruct::Instance=NULL;

StereoReconstruct*StereoReconstruct::GetInstance()
{
	if(Instance==NULL)
	{
		Instance=new StereoReconstruct;
	}
	return Instance;
}
StereoReconstruct::StereoReconstruct()
{
	Instance=this;
	SetReconstructarguments();
}
StereoReconstruct::~StereoReconstruct()
{
	releaseVector();
}
void StereoReconstruct::releaseVector()
{
	//	delete pout;
	p3* temp;
	for(int i=0;i<pout.size();i++)
	{
		temp=pout.at(i);
		delete temp;
	}
	vector<p3*> emptyVector;
	pout.swap(emptyVector);
}
void StereoReconstruct::SetReconstructarguments(std::string filename)
{
	FileStorage fs;
	if(fs.open(filename, FileStorage::READ))
	{
		fs["Ml"]>>Ml;
		fs["Mr"]>>Mr;
		fs["kl"]>>kl;
		fs["kr"]>>kr;
		fs["R"]>>R;
		fs["T"]>>T;
	}
}
void StereoReconstruct::SetReconstructarguments()
{
	FileStorage fs;
	if(fs.open("arg.txt", FileStorage::READ))
	{
		fs["Ml"]>>Ml;
		fs["Mr"]>>Mr;
		fs["kl"]>>kl;
		fs["kr"]>>kr;
		fs["R"]>>R;
		fs["T"]>>T;
	}
}
void StereoReconstruct::StereoRecnstOpenCLUseBuf(OpenCLClass *stereomatchApp)
{
	xL.create(1,stereomatchApp->matched_point_num,CV_32S);
	xR.create(1,stereomatchApp->matched_point_num,CV_32S);
	yL.create(1,stereomatchApp->matched_point_num,CV_32S);
	yR.create(1,stereomatchApp->matched_point_num,CV_32S);

	for(int i=0;i<stereomatchApp->glob_h;i++)
	{
		for(int j=0;j<stereomatchApp->glob_w;j++)
		{
			xL.at<int>(0,i*stereomatchApp->glob_w+j)=j*stereomatchApp->grid+stereomatchApp->rad+stereomatchApp->offset_lw;
			xR.at<int>(0,i*stereomatchApp->glob_w+j)=stereomatchApp->dispxImageMat.at<int>(stereomatchApp->grid*i+stereomatchApp->rad,stereomatchApp->grid*j+stereomatchApp->rad);
			yL.at<int>(0,i*stereomatchApp->glob_w+j)=i*stereomatchApp->grid+stereomatchApp->rad+stereomatchApp->offset_lh;
			yR.at<int>(0,i*stereomatchApp->glob_w+j)=stereomatchApp->dispyImageMat.at<int>(stereomatchApp->grid*i+stereomatchApp->rad,stereomatchApp->grid*j+stereomatchApp->rad);
		}
	}

	Triangulation();
}
void StereoReconstruct::StereoRecnstOpenCLUseImage(OpenCLClass *stereomatchApp)
{
	xL.create(1,stereomatchApp->xycorMat.cols,stereomatchApp->xycorMat.type());
	xR.create(1,stereomatchApp->xycorMat.cols,stereomatchApp->xycorMat.type());
	yL.create(1,stereomatchApp->xycorMat.cols,stereomatchApp->xycorMat.type());
	yR.create(1,stereomatchApp->xycorMat.cols,stereomatchApp->xycorMat.type());

	stereomatchApp->xycorMat.row(0).copyTo(xL.row(0));
	stereomatchApp->xycorMat.row(1).copyTo(yL.row(0));
	stereomatchApp->xycorMat.row(2).copyTo(xR.row(0));
	stereomatchApp->xycorMat.row(3).copyTo(yR.row(0));

	Mat dispMat(stereomatchApp->glob_h,stereomatchApp->glob_w,stereomatchApp->xycorMat.type());
	Mat dispMat1(stereomatchApp->glob_h,stereomatchApp->glob_w,stereomatchApp->xycorMat.type());

	dispMat.data=xR.data;
	//medianBlur(dispMat,dispMat,5);
	//bilateralFilter(dispMat,dispMat1,3,130,130);
	//xR.data=dispMat1.data;
	//GaussianBlur(dispMat,dispMat,Size(3,3), 0, 0);
	Triangulation();
}
vector<p3*>& StereoReconstruct::getPoint3Vector()const
{
	return (vector<p3*>&)pout;
}
void StereoReconstruct::Triangulation()
{
	NormalizePixel();
	//distortion
	CompDistortionOulu();
	Mat U;
	Mat PL,PR;
	PL.create(2,xL.cols,xL.type());
	xL.copyTo(PL.row(0));
	yL.copyTo(PL.row(1));
	PL.resize(3,1);
	PR.create(2,xR.cols,xR.type());
	xR.copyTo(PR.row(0));
	yR.copyTo(PR.row(1));
	PR.resize(3,1);
	U=R*PL;
	double ul,vl,ur,vr,t1,t2,t3;
	t1=T.at<double>(0);
	t2=T.at<double>(1);
	t3=T.at<double>(2);

	double A,B,C,D,E,DD;
	double u,v,w;
	double zl,zr;
	double xl,yl;
	double xr1,yr1,zr1;
	double xr2,yr2,zr2;
	releaseVector();
	for(int i=0;i<U.cols;i++)
	{
		ul=xL.at<double>(0,i);
		vl=yL.at<double>(0,i);
		ur=xR.at<double>(0,i);
		vr=yR.at<double>(0,i);

		u=U.at<double>(0,i);
		v=U.at<double>(1,i);
		w=U.at<double>(2,i);

		A=ul*ul+vl*vl+1;
		B=u*ur+v*vr+w;
		C=u*t1+v*t2+w*t3;
		D=ur*ur+vr*vr+1;
		E=ur*t1+vr*t2+t3;

		DD=A*D-B*B;

		zl=(B*E-C*D)/DD;
		zr=(A*E-B*C)/DD;

		xl=ul*zl;
		yl=vl*zl;

		xr1=ur*zr-t1;
		yr1=vr*zr-t2;
		zr1=zr-t3;

		xr2=xr1*R.at<double>(0,0)+yr1*R.at<double>(1,0)+zr1*R.at<double>(2,0);
		yr2=xr1*R.at<double>(0,1)+yr1*R.at<double>(1,1)+zr1*R.at<double>(2,1);
		zr2=xr1*R.at<double>(0,2)+yr1*R.at<double>(1,2)+zr1*R.at<double>(2,2);
		double zout=(zl+zr2)/2;
		if(zout>200 && zout<500)
		{
			p3 *ptemp=new p3;
			ptemp->x=(xl+xr2)/2;
			ptemp->y=(yl+yr2)/2;
			ptemp->z=zout;
			pout.push_back(ptemp);
		}
	}	
}
void StereoReconstruct::NormalizePixel()
{
	double fcleft1=Ml.at<double>(0,0);
	double fcleft2=Ml.at<double>(1,1);
	double ccleft1=Ml.at<double>(0,2);
	double ccleft2=Ml.at<double>(1,2);
	double fcright1=Mr.at<double>(0,0);
	double fcright2=Mr.at<double>(1,1);
	double ccright1=Mr.at<double>(0,2);
	double ccright2=Mr.at<double>(1,2);
	double a,b;
	a=1/fcleft1;
	b=-ccleft1/fcleft1;
	xL.convertTo(xL,CV_64F,a,b);
	a=1/fcleft2;
	b=-ccleft2/fcleft2;
	yL.convertTo(yL,CV_64F,a,b);

	a=1/fcright1;
	b=-ccright1/fcright1;
	xR.convertTo(xR,CV_64F,a,b);
	a=1/fcright2;
	b=-ccright2/fcright2;
	yR.convertTo(yR,CV_64F,a,b);
}
void StereoReconstruct::CompDistortionOulu()
{
	double k1,k2,k3,p1,p2;
	k1=kl.at<double>(0);
	k2=kl.at<double>(1);
	k3=kl.at<double>(4);
	p1=kl.at<double>(2);
	p2=kl.at<double>(3);
	int PointNum=xL.cols;
	int i;
	double x,y,xd,yd;
	for(i=0;i<PointNum;i++)
	{
		xd=xL.at<double>(0,i);
		yd=yL.at<double>(0,i);
		x=xd;
		y=yd;
		int j;
		double r_2,k_radial,delta_x,delta_y;
		for(j=0;j<20;j++)
		{
			r_2=x*x+y*y;
			k_radial=1 + k1 * r_2 + k2 * r_2* r_2 + k3 * r_2* r_2* r_2;
			delta_x=2*p1*x*y + p2*(r_2 + 2*x*x);
			delta_y=p1*(r_2+2*y*y)+2*p2*x*y;
			x=(xd-delta_x)/k_radial;
			y=(yd-delta_y)/k_radial;
		}
		xL.at<double>(0,i)=x;
		yL.at<double>(0,i)=y;
	}
	k1=kr.at<double>(0);
	k2=kr.at<double>(1);
	k3=kr.at<double>(4);
	p1=kr.at<double>(2);
	p2=kr.at<double>(3);
	for(i=0;i<PointNum;i++)
	{
		xd=xR.at<double>(0,i);
		yd=yR.at<double>(0,i);
		x=xd;
		y=yd;
		int j;
		double r_2,k_radial,delta_x,delta_y;
		for(j=0;j<20;j++)
		{
			r_2=x*x+y*y;
			k_radial=1 + k1 * r_2 + k2 * r_2* r_2 + k3 * r_2* r_2* r_2;
			delta_x=2*p1*x*y + p2*(r_2 + 2*x*x);
			delta_y=p1*(r_2+2*y*y)+2*p2*x*y;
			x=(xd-delta_x)/k_radial;
			y=(yd-delta_y)/k_radial;
		}
		xR.at<double>(0,i)=x;
		yR.at<double>(0,i)=y;
	}
}