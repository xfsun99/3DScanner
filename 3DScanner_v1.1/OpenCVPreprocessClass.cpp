#include "OpenCVPreprocessClass.h"

OpenCVPreprocessClass*OpenCVPreprocessClass::Instance=NULL;

OpenCVPreprocessClass*OpenCVPreprocessClass::GetInstance()
{
	if(Instance==NULL)
	{
		Instance=new OpenCVPreprocessClass;
	}
	return Instance;
}
OpenCVPreprocessClass::OpenCVPreprocessClass()
{
	Instance=this;
}

OpenCVPreprocessClass::~OpenCVPreprocessClass()
{
	delete Instance;
}
vector<Rect> OpenCVPreprocessClass::TargetAreaExt(Mat* img_gray)
{
	Mat tmp=*img_gray;
	Mat dst;
	int kernel_size = 3;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	pyrDown( tmp, dst, Size( tmp.cols/2, tmp.rows/2 ) );
	tmp=dst;
	pyrDown( tmp, dst, Size( tmp.cols/2, tmp.rows/2 ) );
	/// Apply Laplace function
	Mat abs_dst;
	Laplacian( dst, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT );
	/// Show what you got
	GaussianBlur( dst, dst, Size(5,5), 2, 2, BORDER_DEFAULT );
	convertScaleAbs( dst, abs_dst );
	double ma,mi;
	minMaxLoc(abs_dst,&mi,&ma,0,0,Mat());
	Mat thimg=abs_dst>ma/8;

	Mat element = getStructuringElement( 2, Size( 21, 21), Point( 10, 10 ) );
	/// Apply the specified morphology operation
	morphologyEx( thimg, dst, 3, element );//close
	morphologyEx( dst, dst, 2, element );//open

	tmp=dst;
	pyrUp( tmp, dst, Size( tmp.cols*2, tmp.rows*2 ) );
	tmp=dst;
	pyrUp( tmp, dst, Size( tmp.cols*2, tmp.rows*2 ) );
	dst=dst>0;
	Mat d=*img_gray;
	d=d&dst;
	//imshow("dst",dst);

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	/// Detect edges using Threshold
	/// Find contours
	findContours( dst, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	/// Approximate contours to polygons + get bounding rects and circles
	vector<vector<Point> > contours_poly( contours.size() );
	vector<Rect> boundRect( contours.size() );
	Rect rectToReturn;
	int maxArea=0;
	for( int i = 0; i < contours.size(); i++ )
	{ 
		approxPolyDP( Mat(contours[i]), contours_poly[i], 6, true );
		boundRect[i] = boundingRect( Mat(contours_poly[i]) );
		if(boundRect[i].area()>maxArea)
		{
			rectToReturn=boundRect[i];
			maxArea=boundRect[i].area();
		}
	}
	boundRect[0]=rectToReturn;
	return boundRect;
}
void OpenCVPreprocessClass::ReadRawImage( )
{
	Mat imgInl,imgInr;
	imgInl=imread("D:\\0709\\fl2.bmp");
	if (imgInl.empty())
	{
		printf("can't open left image!\n");
		return;
	}
	imgInr=imread("D:\\0709\\fr2.bmp");
	if (imgInr.empty())
	{
		printf("can't open right image!\n");
		return;
	}
	if(imgInl.channels()==3)
	cvtColor(imgInl,imgl,CV_BGR2GRAY);
	if(imgInr.channels()==3)
	cvtColor(imgInr,imgr,CV_BGR2GRAY);
	
	retl=TargetAreaExt(&imgl);
	retr=TargetAreaExt(&imgr);
	cout<<retl[0].tl()<<","<<retl[0].br()<<endl;
	cout<<retl[0].width<<"*"<<retl[0].height<<endl;
	cout<<retr[0].tl()<<","<<retr[0].br()<<endl;

	//imshow("L",imgl);
	//imshow("R",imgr);
	imgl.convertTo(imgLinImg,CV_32F);
	imgr.convertTo(imgRinImg,CV_32F);
	Mat ml(imgl,retl[0]);
	Mat mr(imgr,retr[0]);
	ml.convertTo(imgLin,CV_8U);
	mr.convertTo(imgRin,CV_8U);
}
void OpenCVPreprocessClass::ReadRawImage(string leftImgName,string rightImgName)
{
	Mat imgInl,imgInr;
	imgInl=imread(leftImgName);
	if (imgInl.empty())
	{
		printf("can't open left image!\n");
		return;
	}
	imgInr=imread(rightImgName);
	if (imgInr.empty())
	{
		printf("can't open right image!\n");
		return;
	}
	if(imgInl.channels()==3)
		cvtColor(imgInl,imgl,CV_BGR2GRAY);
	if(imgInr.channels()==3)
		cvtColor(imgInr,imgr,CV_BGR2GRAY);
	retl=TargetAreaExt(&imgl);
	retr=TargetAreaExt(&imgr);
	cout<<retl[0].tl()<<","<<retl[0].br()<<endl;
	cout<<retl[0].width<<"*"<<retl[0].height<<endl;
	cout<<retr[0].tl()<<","<<retr[0].br()<<endl;

	imshow("L",imgl);
	imshow("R",imgr);
	imgl.convertTo(imgLinImg,CV_32F);
	imgr.convertTo(imgRinImg,CV_32F);
	Mat ml(imgl,retl[0]);
	Mat mr(imgr,retr[0]);
	ml.convertTo(imgLin,CV_8U);
	mr.convertTo(imgRin,CV_8U);
}
void OpenCVPreprocessClass::LoadLeftImg(string leftImgName)
{
	Mat imgInl;
	imgInl=imread(leftImgName);
	if (imgInl.empty())
	{
		printf("can't open left image!\n");
		return;
	}
	if(imgInl.channels()==3)
		cvtColor(imgInl,imgl,CV_BGR2GRAY);
	else
		imgl=imgInl;
	retl=TargetAreaExt(&imgl);
	imshow("L",imgl);
	imgl.convertTo(imgLinImg,CV_32F);
	Mat ml(imgl,retl[0]);
	ml.convertTo(imgLin,CV_8U);
}
void OpenCVPreprocessClass::LoadRightImg(string rightImgName)
{
	Mat	imgInr;
	imgInr=imread(rightImgName);
	if (imgInr.empty())
	{
		printf("can't open right image!\n");
		return;
	}
	if(imgInr.channels()==3)
		cvtColor(imgInr,imgr,CV_BGR2GRAY);
	else 
		imgr=imgInr;

	retr=TargetAreaExt(&imgr);

	imshow("R",imgr);
	imgr.convertTo(imgRinImg,CV_32F);
	Mat mr(imgr,retr[0]);
	mr.convertTo(imgRin,CV_8U);
}
void OpenCVPreprocessClass::LoadLRImage(Mat* LeftImg,Mat* RightImg)
{
	if (LeftImg->empty())
	{
		printf("Left image is empty!\n");
		return;
	}
	if (RightImg->empty())
	{
		printf("Right image is empty!\n");
		return;
	}
	if(LeftImg->channels()==3)
		cvtColor(*LeftImg,imgl,CV_BGR2GRAY);
	else 
		imgl=*LeftImg;
	if(RightImg->channels()==3)
		cvtColor(*RightImg,imgr,CV_BGR2GRAY);
	else
		*RightImg=imgr;
	retl=TargetAreaExt(&imgl);
	retr=TargetAreaExt(&imgr);

	imgl.convertTo(imgLinImg,CV_32F);
	imgr.convertTo(imgRinImg,CV_32F);
	Mat ml(imgl,retl[0]);
	Mat mr(imgr,retr[0]);
	imshow("L",ml);
	waitKey(10);
	imshow("R",mr);
	waitKey(10);
	ml.convertTo(imgLin,CV_8U);
	mr.convertTo(imgRin,CV_8U);
}
vector<Rect>* OpenCVPreprocessClass::GetLeftTargetArea()
{
	return &retl;
}
vector<Rect>* OpenCVPreprocessClass::GetRightTargetArea()
{
	return &retr;
}