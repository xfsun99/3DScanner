#include "vtkPointCloudProcess.h"
#include "vtkSimplePointsWriter.h"
#include "vtkPolyData.h"
#include "vtkSTLWriter.h"
#include <vtkSmartPointer.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkOctreePointLocator.h>
#include <vtkDelaunay2D.h>
#include <vtkSmoothPolyDataFilter.h>
#include "vtkDisplayClass.h"
#include <vtkElevationFilter.h>
#include <vtkPointData.h>
#include <vtkCellArray.h>
#include <vtkUnsignedCharArray.h>
vtkPointCloudProcess::vtkPointCloudProcess()
{
}
vtkPointCloudProcess::~vtkPointCloudProcess()
{
}
void vtkPointCloudProcess::pointCloudFilter(double rad)
{
	vtkSmartPointer<vtkOctreePointLocator> pointTree =
	vtkSmartPointer<vtkOctreePointLocator>::New();
	pointTree->SetDataSet(PolyData);  
	pointTree->BuildLocator(); 
	vtkIdType k=PolyData->GetNumberOfPoints();
	double testPoint[3] = {0.0, 0.0, 0.0};  
	vtkSmartPointer<vtkIdList> result =  vtkSmartPointer<vtkIdList>::New();
	vtkSmartPointer<vtkPoints> outlinepoints=vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkPoints> inlinepoints=vtkSmartPointer<vtkPoints>::New();
	for(vtkIdType i = 0; i < k; i++)
	{
		PolyData->GetPoint(i, testPoint);	  
		pointTree->FindPointsWithinRadius(rad, testPoint, result);
		//pointTree->f
		if(result->GetNumberOfIds()<10)
		{
			outlinepoints->InsertNextPoint(testPoint);
		}
		else 
		{
			double inlinepoint[3];
			double diskernel=0;
			double dist=0;
			double sigema=2*0.8;
			for(int j=0;j<result->GetNumberOfIds();j++)
			{
				PolyData->GetPoint(result->GetId(j),inlinepoint);
				dist=(testPoint[0]-inlinepoint[0])*(testPoint[0]-inlinepoint[0])+
					(testPoint[1]-inlinepoint[1])*(testPoint[1]-inlinepoint[1])+
					(testPoint[2]-inlinepoint[2])*(testPoint[2]-inlinepoint[2]);
				dist=dist/sigema;
				diskernel+=exp(-dist);
				dist=0;
			}

			if(diskernel>3.21)
			inlinepoints->InsertNextPoint(testPoint);
		}
	}
	vtkSmartPointer<vtkPolyData> temp = 
	vtkSmartPointer<vtkPolyData>::New();
	temp->SetPoints(inlinepoints);
	vtkSmartPointer<vtkVertexGlyphFilter> vertexFilter = 
	vtkSmartPointer<vtkVertexGlyphFilter>::New();
	vertexFilter->SetInputData(temp);
	vertexFilter->Update();
	PolyData->ShallowCopy(vertexFilter->GetOutput());
}
void vtkPointCloudProcess::constructSurfaceFormPoints()
{
// Triangulate the grid points
  vtkSmartPointer<vtkDelaunay2D> delaunay =
    vtkSmartPointer<vtkDelaunay2D>::New();
#if VTK_MAJOR_VERSION <= 5
  delaunay->SetInput(polydata);
#else
  delaunay->SetInputData(PolyData);
#endif

	delaunay->SetAlpha(10);
	delaunay->Update();

	vtkSmartPointer<vtkSmoothPolyDataFilter> smoothFilter =
	vtkSmartPointer<vtkSmoothPolyDataFilter>::New();
	smoothFilter->SetInputConnection(delaunay->GetOutputPort());
	smoothFilter->SetNumberOfIterations(800);
	smoothFilter->SetFeatureEdgeSmoothing(0);
	smoothFilter->Update();

//Create a smoothedActor
    vtkSmartPointer<vtkPolyDataMapper> smoothMapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  smoothMapper->SetInputConnection(smoothFilter->GetOutputPort());
  vtkSmartPointer<vtkActor> smoothedActor =
    vtkSmartPointer<vtkActor>::New();
  smoothedActor->SetMapper(smoothMapper);

}