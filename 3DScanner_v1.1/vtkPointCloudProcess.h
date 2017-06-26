#ifndef VTK_DISPLAY_POINT_CLOUD_H
#define VTK_DISPLAY_POINT_CLOUD_H
#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)
#include <vtkPoints.h>
#include <vtkPointSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkConeSource.h>
#include <vtkSphereSource.h>
#include "vtkPolyVertex.h"
#include "vtkUnstructuredGrid.h"
#include "vtkDataSetMapper.h"
#include "vtkActor.h"
#include "vtkProperty.h"
#include <vtkInteractorStyleTrackballCamera.h>
#include "opencv2/highgui/highgui.hpp"
#include "StereoReconstruct.h"
using namespace cv;

class vtkPointCloudProcess:public vtkObject
{
public:
	static vtkPointCloudProcess *New()
    {
    return new vtkPointCloudProcess;
    }
	vtkPointCloudProcess();
	~vtkPointCloudProcess();
	void pointCloudFilter(double rad);
	void constructSurfaceFormPoints();
private:
	vtkSmartPointer<vtkPolyData> PolyData;
};

#endif