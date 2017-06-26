#ifndef OPENCLCLASS_H
#define OPENCLCLASS_H
#include<CL/cl.h>
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include "OpenCVPreprocessClass.h"
#include "vtkObject.h"

struct DeviceInfo
{
    cl_device_id DeviceID;
    std::string DeviceName;
};
struct PlatformInfo
{
    cl_platform_id platformid;
    std::string platformName;
};

class OpenCLClass{
public:
	// Get the global instace for the OpenCLClass.
	static OpenCLClass*GetInstance();

	~OpenCLClass();
	bool		GetPlatforms();
	int			GetNumOfPlatforms();
	bool		GetPlatformIDs();
	bool		GetDeviceIDs(cl_platform_id platformid);
	std::string	InitializeOpenCL(cl_device_id device);
	bool		convertToString(const char *filename,std::string& s);
	bool		DoesOpenCLOperateSuccess();
	std::string ProgramOpenCLKernel();
	std::string CreateOpenCLKernelForBuffer();
	std::string CreateOpenCLKernelForImage();
	std::string LoadDataToGPUUseBuffer();
	std::string LoadDataToGPUUseImage();
	std::string RunGPUKernelUseBuffer();
	std::string RunGPUKernelUseImage();
	std::string RunOpenCLInDefault();
	void		RunOpenCLInitialInDefault();
	void		getOpenCVPreprocessObject(OpenCVPreprocessClass* Object);


	std::vector<PlatformInfo*>	paltfInfo;
	std::vector<DeviceInfo*>	deviceInfo;

	int			matched_point_num;
	int			glob_w;
	int			glob_h;
	int			offset_lw;
	int			offset_lh;
	int			grid;
	int			rad;

	float fmtemp[9];
	Mat dispImageMat;
	Mat dispxImageMat;
	Mat dispyImageMat;
	Mat xycorMat;
	std::string errorMessage;

	cl_mem dispImagex,dispImagey;
private:
	OpenCLClass();
	static OpenCLClass*			Instance;
	cl_uint						num_platforms;
	cl_platform_id              platformSelected; 
    cl_device_type              deviceType;
    cl_device_id                deviceSelected;
    cl_context                  context;
    cl_command_queue            commandQueue;
    cl_program                  program;
    cl_kernel                   gd_kernel;
	cl_int						status;
	bool						validPlatformID;
	bool						validDeviceID;
	bool						objectHasInitialed;
    size_t						gwsize[3];// OpenCL global work size
    cl_mem                      imgL,imgR,LRxyOut,fm;
	OpenCVPreprocessClass*		inputImagePreprocess;
};

#endif