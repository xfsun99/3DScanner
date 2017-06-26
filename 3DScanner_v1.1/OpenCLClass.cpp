#include"OpenCLClass.h"
//#define USEIMAGE

OpenCLClass*OpenCLClass::Instance=NULL;

OpenCLClass* OpenCLClass::GetInstance()
{
	if(Instance==NULL)
	{
		Instance=new OpenCLClass;
	}
	return Instance;
}
OpenCLClass::OpenCLClass()
{
	Instance=this;
	validDeviceID=false;
	validPlatformID=false;
	objectHasInitialed=false;
	RunOpenCLInitialInDefault();
	grid=5;
}
OpenCLClass::~OpenCLClass()
{	
	if(objectHasInitialed)
	{
		clReleaseMemObject(imgL);
		clReleaseMemObject(imgR);
		clReleaseMemObject(fm);
		clReleaseMemObject(LRxyOut);
		clReleaseCommandQueue(commandQueue);
		clReleaseContext(context);
		clReleaseProgram(program);
		clReleaseKernel(gd_kernel);
	}
	delete Instance;
}
void OpenCLClass::getOpenCVPreprocessObject(OpenCVPreprocessClass* Object)
{
	inputImagePreprocess=Object;
}
bool OpenCLClass::DoesOpenCLOperateSuccess()
{
	if(status==CL_SUCCESS)
		return true;
	return false;
}
bool OpenCLClass::GetPlatforms()
{	
	if ((clGetPlatformIDs(0, NULL, &num_platforms)) == CL_SUCCESS)                   
    {                         
		std::cout<<"Number of OpenCL platforms available in the system:"<<num_platforms<<std::endl;  
		GetPlatformIDs();
		return true;
    }
	std::cout<<"Get Number of available OpenCL platforms failured!"<<std::endl;
	return false;
}
int OpenCLClass::GetNumOfPlatforms()
{
	return num_platforms;
}
bool OpenCLClass::GetPlatformIDs()
{
	cl_platform_id *platforms;
	platforms=new cl_platform_id[num_platforms];
    if(clGetPlatformIDs(num_platforms, platforms, NULL) != CL_SUCCESS)           
    {                                                                            
		std::cout<<"Error in call to clGetPlatformIDs"<<std::endl;
		return false;
    }
	char buf[100];
	if(!paltfInfo.empty())
	{
		paltfInfo.erase(paltfInfo.begin(),paltfInfo.end());
	}
	for(int i=0;i<num_platforms;i++)
	{
		PlatformInfo *new_PlatfInfo=new PlatformInfo;
		new_PlatfInfo->platformid=platforms[i];
		clGetPlatformInfo(platforms[i],CL_PLATFORM_NAME,sizeof(buf),&buf,NULL);
		new_PlatfInfo->platformName=buf;
		paltfInfo.push_back(new_PlatfInfo);
	}
	validPlatformID=true;
	return true;
}
bool OpenCLClass::GetDeviceIDs(cl_platform_id platformid)
{
	cl_uint          num_devices;
	platformSelected=platformid;
    if(clGetDeviceIDs (platformid, CL_DEVICE_TYPE_ALL, 0, NULL, &num_devices)==CL_SUCCESS)
	{
		if(!deviceInfo.empty())
		{
			deviceInfo.erase(deviceInfo.begin(),deviceInfo.end());
		}
		cl_device_id    *devices;
		char buf[100];
		devices = (cl_device_id *)malloc(sizeof(cl_device_id) * num_devices);
        clGetDeviceIDs (platformid, CL_DEVICE_TYPE_ALL, num_devices, devices, &num_devices);
		for(int i=0;i<num_devices;i++)
		{
			DeviceInfo *new_device=new DeviceInfo;
			new_device->DeviceID=devices[i];
			clGetDeviceInfo(devices[i], CL_DEVICE_NAME, sizeof(buf), &buf, NULL);
			new_device->DeviceName=buf;
			deviceInfo.push_back(new_device);
		}
		return true;
	}
	return false;
}
std::string OpenCLClass::InitializeOpenCL(cl_device_id device)
{
	deviceSelected=device;
    //Create an execution context for the selected platform and device.
	cl_context_properties cps[3] ={CL_CONTEXT_PLATFORM,(cl_context_properties)platformSelected,0};
    context = clCreateContextFromType(cps,
									CL_DEVICE_TYPE_ALL,
									NULL,
									NULL,
									&status);
	if(status!=CL_SUCCESS) return "clCreateContextFromType Failed!";
    // Create command queue
    commandQueue = clCreateCommandQueue(context,
                                        device,
                                        0,
                                        &status);
	if(status!=CL_SUCCESS)return "clCreateCommandQueue Failed!";
	//program OpenCL kernel
	return ProgramOpenCLKernel();
}

std::string OpenCLClass::ProgramOpenCLKernel()
{
	const char* filname="stereomatchoclKernel.cl";
	//Convert kernel file to string
	std::string sourceStr;
	status=convertToString(filname,sourceStr);
	if(status!=CL_SUCCESS)return "convertToString Failed";
	//Program the kernel file
	const char* source=sourceStr.c_str();
	size_t sourceSize[]={strlen(source)};
	program=clCreateProgramWithSource(context,1,&source,sourceSize,&status);
	if(status!=CL_SUCCESS)	return "clCreateProgramWithSource Failed!";
    //Build the program
	status = clBuildProgram(program, 1, &deviceSelected, NULL, NULL, NULL);
	if(status!=CL_SUCCESS)	return "clBuildProgram Failed!";
	//Create OpenCL kernel
	return "OpenCL device initialize successed!";
}
//
bool OpenCLClass::convertToString(const char *filename,std::string& s)
{
	size_t size;
	char* str;
	std::fstream f(filename,(std::fstream::in | std::fstream::binary));
	if(f.is_open())
	{
		size_t fileSize;
		f.seekg(0,std::fstream::end);
		size=fileSize=(size_t)f.tellg();
		f.seekg(0,std::fstream::beg);
		str=new char[size+1];
		if(!str)
		{
			f.close();
			return NULL;
		}
		f.read(str,fileSize);
		f.close();
		str[size]='\0';
		s=str;
		delete[] str;
		return 0;
	}
	return 1;
}
std::string OpenCLClass::CreateOpenCLKernelForBuffer()
{
	gd_kernel = clCreateKernel(program,"test_kernel_buffer", &status);
	if(status!=CL_SUCCESS) return "Create test_kernel_buffer failed!";
	return "OpenCL CreateOpenCLKernelForBuffer successed!";
}
std::string OpenCLClass::CreateOpenCLKernelForImage()
{
	gd_kernel = clCreateKernel(program,"test_kernel_image", &status);
	if(status!=CL_SUCCESS) return "Create test_kernel_image failed!";
	validDeviceID=true;
	return "OpenCL CreateOpenCLKernelForImage successed!";
}
void OpenCLClass::RunOpenCLInitialInDefault()
{
	string message;
	cl_platform_id * platforms = NULL;
	if ((clGetPlatformIDs(0, NULL, &num_platforms)) == CL_SUCCESS)                   
	{                         
		platforms=new cl_platform_id[num_platforms];
		status=clGetPlatformIDs(num_platforms, platforms, NULL);
		if(status!= CL_SUCCESS)           
		{                                                                            
			delete[] platforms; 
			errorMessage="Error in call to clGetPlatformIDs!";
			return;
		}                                                                            
	}
	platformSelected=platforms[1];
	delete[] platforms;                                                         
	validPlatformID=true;
	//Get the first available device
	status = clGetDeviceIDs (platformSelected, CL_DEVICE_TYPE_GPU, 1, &deviceSelected, NULL);
	if(status!=CL_SUCCESS)
	{
		errorMessage="clGetDeviceIDs error in RunOpenCLInDefault()!";
		return;
	}
	//Create an execution context for the selected platform and device.
	cl_context_properties cps[3] =
	{
		CL_CONTEXT_PLATFORM,
		(cl_context_properties)platformSelected,
		0
	};
	context = clCreateContextFromType(cps,CL_DEVICE_TYPE_GPU,NULL,NULL,&status);
	// Create command queue
	commandQueue = clCreateCommandQueue(context,deviceSelected,0,&status);
	if(status!=CL_SUCCESS)
	{errorMessage= "commandQueue error in RunOpenCLInDefault()!";return;}
	message=ProgramOpenCLKernel();
	if(status!=CL_SUCCESS){errorMessage=message; return;}
	message=CreateOpenCLKernelForImage();
	objectHasInitialed=true;
	if(status!=CL_SUCCESS){errorMessage=message; return;}
}
std::string OpenCLClass::RunOpenCLInDefault()
{
	//RunOpenCLInitialInDefault();
	return LoadDataToGPUUseImage();
}
std::string OpenCLClass::LoadDataToGPUUseBuffer()
{
	int deviceWidthL = inputImagePreprocess->retl[0].width;
	int deviceHeightL = inputImagePreprocess->retl[0].height;
	// Size of the input and output images on the device
	int deviceDataSizeL = deviceHeightL*deviceWidthL*sizeof(uchar);

	int deviceWidthR = inputImagePreprocess->retr[0].width;
	int deviceHeightR = inputImagePreprocess->retr[0].height;
	// Size of the input and output images on the device
	int deviceDataSizeR = deviceHeightR *deviceWidthR*sizeof(uchar);
	//create buffer
	imgL= clCreateBuffer(context, CL_MEM_READ_ONLY,deviceDataSizeL, NULL, &status);
	imgR = clCreateBuffer(context, CL_MEM_READ_ONLY,deviceDataSizeR, NULL, &status);
	if(status!=CL_SUCCESS)return"clCreateBuffer failed!";

    dispImagex = clCreateBuffer(context, CL_MEM_WRITE_ONLY,deviceHeightL*deviceWidthL*sizeof(int), NULL, &status);
	dispImagey = clCreateBuffer(context, CL_MEM_WRITE_ONLY,deviceHeightL*deviceWidthL*sizeof(int), NULL, &status);
	if(status!=CL_SUCCESS)return"clCreateBuffer failed!";

	size_t buffer_origin[3] = {0,0,0};
	size_t host_originL[3] = {inputImagePreprocess->retl[0].tl().x,inputImagePreprocess->retl[0].tl().y,0};
	size_t region[3] = {deviceWidthL*sizeof(uchar),deviceHeightL, 1};

	status=clEnqueueWriteBuffer(commandQueue,imgL,CL_TRUE,
		0,//offset
		deviceDataSizeL,//cb
		inputImagePreprocess->imgLin.data,
		0,
		0,
		0);
	status=clEnqueueWriteBuffer(commandQueue,imgR,CL_TRUE,
		0,//offset
		deviceDataSizeR,//cb
		inputImagePreprocess->imgRin.data,
		0,
		0,
		0);
	if(status!=CL_SUCCESS)return"clEnqueueWriteBuffer failed!";

	return "clEnqueueWriteBuffer successed!";
}
std::string OpenCLClass::RunGPUKernelUseBuffer()
{
	cl_event	wlist;
    cl_int status;
	int rad=5;
	int offset_hl=inputImagePreprocess->retl[0].tl().y;
	int offset_wl=inputImagePreprocess->retl[0].tl().x;
	int offset_hr=inputImagePreprocess->retr[0].tl().y;
	int offset_wr=inputImagePreprocess->retr[0].tl().x;
	int wrd=inputImagePreprocess->retr[0].width;
	int wld=inputImagePreprocess->retl[0].width;
	gwsize[0] =(inputImagePreprocess->retl[0].width-2*rad)/grid;
	gwsize[1] = (inputImagePreprocess->retl[0].height-2*rad)/grid;
	gwsize[2] = 1;
	matched_point_num=gwsize[0]*gwsize[1];
	glob_w=gwsize[0];
	glob_h=gwsize[1];
	offset_lw=offset_wl;
	offset_lh=offset_hl;
	status = clSetKernelArg(gd_kernel, 0, sizeof(cl_mem), (void*)&imgL);
	status = clSetKernelArg(gd_kernel, 1, sizeof(cl_mem), (void*)&imgR);
    status = clSetKernelArg(gd_kernel, 2, sizeof(cl_mem), (void*)&dispImagex);
    status = clSetKernelArg(gd_kernel, 3, sizeof(cl_mem), (void*)&dispImagey);
    status = clSetKernelArg(gd_kernel, 4, sizeof(int), (void*)&offset_wl);
    status = clSetKernelArg(gd_kernel, 5, sizeof(int), (void*)&offset_hl);
	status = clSetKernelArg(gd_kernel, 6, sizeof(int), (void*)&offset_wr);
    status = clSetKernelArg(gd_kernel, 7, sizeof(int), (void*)&offset_hr);
	status = clSetKernelArg(gd_kernel, 8, sizeof(int), (void*)&grid);
    status = clEnqueueNDRangeKernel(
                        commandQueue,
                        gd_kernel,
                        3,
                        NULL,
                        gwsize,
                        0,
                        0,
                        NULL,
                        &wlist);
	if(status!=CL_SUCCESS)return"clEnqueueNDRangeKernel Failed!";

    clWaitForEvents(1, &wlist);
	clReleaseEvent(wlist);
	int deviceWidthL = inputImagePreprocess->retl[0].width;
	int deviceHeightL = inputImagePreprocess->retl[0].height;
	// Size of the input and output images on the device
	int deviceDataSizeL = deviceHeightL*deviceWidthL*sizeof(int);

	dispxImageMat.create(inputImagePreprocess->imgLin.rows,inputImagePreprocess->imgLin.cols,CV_32S);//(deviceHeightL,deviceWidthL,CV_8U);
	dispyImageMat.create(inputImagePreprocess->imgLin.rows,inputImagePreprocess->imgLin.cols,CV_32S);
	status = clEnqueueReadBuffer(commandQueue, dispImagex, CL_TRUE, 0,deviceDataSizeL,dispxImageMat.data, 0, 0, 0);
	if(status!=CL_SUCCESS)return"clEnqueueReadBuffer Failed!";
	status = clEnqueueReadBuffer(commandQueue, dispImagey, CL_TRUE, 0,deviceDataSizeL,dispyImageMat.data, 0, 0, 0);
	if(status!=CL_SUCCESS)return"clEnqueueReadBuffer Failed!";
	//Mat imgout;
	//dispxImageMat.convertTo(imgout,CV_8U);
	//imshow("imgoutdispx",imgout);
	return "clEnqueueNDRangeKernel successed!";
}
std::string OpenCLClass::LoadDataToGPUUseImage()
{
	cl_image_format image_format;
    image_format.image_channel_data_type = CL_FLOAT;//CL_UNSIGNED_INT8;//
    image_format.image_channel_order = CL_R;

    imgL = clCreateImage2D(
        context,
        CL_MEM_READ_ONLY,
        &image_format,
        inputImagePreprocess->imgLinImg.cols, inputImagePreprocess->imgLinImg.rows, 0, 	
        NULL,
        &status);
	if(status!=CL_SUCCESS)return"clCreateImage2D Failed!";
	imgR = clCreateImage2D(
        context,
        CL_MEM_READ_ONLY,
        &image_format,
        inputImagePreprocess->imgLinImg.cols, inputImagePreprocess->imgLinImg.rows, 0, 	
        NULL,
        &status);
	if(status!=CL_SUCCESS)return"clCreateImage2D Failed!";

	int FMdataSize = 3*3*sizeof(float);
	fm= clCreateBuffer(context, CL_MEM_READ_ONLY,FMdataSize, NULL, &status);
	if(status!=CL_SUCCESS)return"clCreateBuffer for fm Failed!";

    size_t origin[3];
    size_t region[3];
    origin[0] = origin[1] = origin[2] = 0;
    region[0] = inputImagePreprocess->imgLinImg.cols; region[1] = inputImagePreprocess->imgLinImg.rows; region[2] = 1;

	status = clEnqueueWriteImage(commandQueue, imgR, CL_TRUE, origin, region, 0, 0, inputImagePreprocess->imgRinImg.data, 0, NULL, NULL);

	status = clEnqueueWriteImage(commandQueue, imgL, CL_TRUE, origin, region, 0, 0, inputImagePreprocess->imgLinImg.data, 0, NULL, NULL);
	if(status!=CL_SUCCESS)return"clEnqueueWriteImage Failed!";

	Mat FM;
	FileStorage fs;
	if(fs.open("arg.txt", FileStorage::READ))
	{
		fs["FM"]>>FM;
	}
	fs.release();
	for(int i=0;i<FM.rows;i++)
	{
		fmtemp[3*i]=(float)FM.at<double>(i,0);
		fmtemp[3*i+1]=(float)FM.at<double>(i,1);
		fmtemp[3*i+2]=(float)FM.at<double>(i,2);
	}
	status=clEnqueueWriteBuffer(commandQueue,fm,CL_TRUE,
									0,//offset
									FMdataSize,//cb
									&fmtemp,
									0,
									0,
									0);
	return RunGPUKernelUseImage();
}
std::string OpenCLClass::RunGPUKernelUseImage()
{
	cl_event	wlist;
    cl_int status;
	cl_sampler sampler = clCreateSampler (context,
					CL_FALSE,
					CL_ADDRESS_CLAMP_TO_EDGE,
					CL_FILTER_NEAREST,
					&status);
	int rad=13;
	int h=inputImagePreprocess->retl[0].height;
	int w=inputImagePreprocess->retl[0].width;
	int start_w=inputImagePreprocess->retl[0].tl().x;
	int start_h=inputImagePreprocess->retl[0].tl().y;
	int boundl=inputImagePreprocess->retr[0].tl().x;
	gwsize[0] =(int)(w-2*rad)/grid;
	gwsize[1] =(int)(h-2*rad)/grid;
	gwsize[2] = 1;
	glob_w=gwsize[0];
	glob_h=gwsize[1];
	offset_lw=start_w;
	offset_lh=start_h;
	matched_point_num=gwsize[0]*gwsize[1];
	int LRxyOutsize=4*gwsize[0]*gwsize[1]*sizeof(float);
	LRxyOut = clCreateBuffer(context, CL_MEM_WRITE_ONLY,LRxyOutsize, NULL, &status);

    status = clSetKernelArg(gd_kernel, 0, sizeof(cl_mem), (void*)&imgL);
	status = clSetKernelArg(gd_kernel, 1, sizeof(cl_mem), (void*)&imgR);
    status = clSetKernelArg(gd_kernel, 2, sizeof(cl_mem), (void*)&fm);
    status = clSetKernelArg(gd_kernel, 3, sizeof(cl_mem), (void*)&LRxyOut);
	status = clSetKernelArg(gd_kernel, 4, sizeof(int), (void*)&start_w);
	status = clSetKernelArg(gd_kernel, 5, sizeof(int), (void*)&start_h);
	status = clSetKernelArg(gd_kernel, 6, sizeof(int), (void*)&boundl);
    status = clSetKernelArg(gd_kernel, 7, sizeof(cl_sampler), (void*)&sampler);
    status = clSetKernelArg(gd_kernel, 8, sizeof(int), (void*)&grid);

    status = clEnqueueNDRangeKernel(
                        commandQueue,
                        gd_kernel,
                        3,
                        NULL,
                        gwsize,
                        0,
                        0,
                        NULL,
                        &wlist);
	if(status!=CL_SUCCESS)return"clEnqueueNDRangeKernel Failed!";
    clWaitForEvents(1, &wlist);
	clReleaseEvent(wlist);
	clReleaseSampler(sampler);

	xycorMat.create(4,gwsize[0]*gwsize[1],CV_32F);
	status = clEnqueueReadBuffer(commandQueue, LRxyOut, CL_TRUE, 0,LRxyOutsize, xycorMat.data, 0, NULL, NULL);
	//clEnqueueReadImage(commandQueue,
	if(status!=CL_SUCCESS)return"clEnqueueReadBuffer Failed!";
	return "clEnqueueNDRangeKernel successed!";
}