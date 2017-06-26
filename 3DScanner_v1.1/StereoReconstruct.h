#ifndef STEREORECONSTRUCT_H
#define STEREORECONSTRUCT_H
#include<opencv2\ocl\ocl.hpp>
#include <opencv2/highgui/highgui.hpp>
#include"OpenCLClass.h"
#include "vtkObject.h"
using namespace cv;
struct p3{
	double x;
	double y;
	double z;
};
class StereoReconstruct
{
public:
	static StereoReconstruct*GetInstance();
	~StereoReconstruct();
	void SetReconstructarguments();
	void SetReconstructarguments(std::string filename);
	void StereoRecnstOpenCLUseBuf(OpenCLClass *stereomatchApp);
	void StereoRecnstOpenCLUseImage(OpenCLClass *stereomatchApp);
	void Triangulation();
	void NormalizePixel();
	void CompDistortionOulu();
	void setInputOpenCLObject(OpenCLClass* OclObject);
	vector<p3*>& getPoint3Vector()const;
	void releaseVector();
private:
		StereoReconstruct();
		static 	StereoReconstruct* Instance;
	Mat pointout;
	//
	vector<p3*> pout;
	//Stereo matched coordinates
	Mat xL;
	Mat yL;
	Mat xR;
	Mat yR;
	//Reconstruct arguments
	Mat Ml;
	Mat Mr;
	Mat kl;
	Mat kr;
	Mat R;
	Mat T;
};
#endif