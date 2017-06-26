#ifndef OPENCVPREPROCESSCLASS_H
#define OPENCVPREPROCESSCLASS_H
#include<iostream>
#include<opencv2\ocl\ocl.hpp>
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

class OpenCVPreprocessClass{
public:
	static OpenCVPreprocessClass*GetInstance();
	~OpenCVPreprocessClass();
	vector<Rect> TargetAreaExt(Mat* img_gray);
	vector<Rect>*GetLeftTargetArea();
	vector<Rect>*GetRightTargetArea();
	void ReadRawImage();
	void ReadRawImage(string leftImgName,string rightImgName);
	void LoadLeftImg(string leftImgName);
	void LoadRightImg(string rightImgName);
	void LoadLRImage(Mat* LeftImg,Mat* RightImg);
	vector<Rect> retl;
	vector<Rect> retr;
	Mat imgLin;
	Mat imgRin;
	Mat imgLinImg;
	Mat imgRinImg;
	Mat imgl;
	Mat	imgr;

private:
	OpenCVPreprocessClass();
	static OpenCVPreprocessClass* Instance;
};

#endif