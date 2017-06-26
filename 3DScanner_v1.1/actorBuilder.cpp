#include"actorBuilder.h"
#include <vtkVertexGlyphFilter.h>
#include <vtkSphereSource.h>
//pointCloudActorBuilder
pointCloudActorBuilder::pointCloudActorBuilder()
{
	pointCloudActor=new actor;
}
pointCloudActorBuilder::~pointCloudActorBuilder()
{
	delete pointCloudActor;
}
void pointCloudActorBuilder::buildPointCloudActor(std::string actorName="PointCloud")
{
	if(actorName=="")
		actorName="PointCloud";
	pointCloudActor->setActorName(actorName);
	StereoReconstruct*instance=StereoReconstruct::GetInstance();
	build(instance->getPoint3Vector());
}
void pointCloudActorBuilder::build(vector<p3*>&pout)
{
	double arr[3];
    vtkSmartPointer<vtkPoints> points = vtkPoints::New();
	for(int n=0;n<pout.size();n++)
	{
		arr[0]=pout[n]->x;
		arr[1]=pout[n]->y;
		arr[2]=pout[n]->z;
		points->InsertPoint(n,arr[0],arr[1],arr[2]);
	}
	vtkSmartPointer<vtkPolyData> temp = 
	vtkSmartPointer<vtkPolyData>::New();
	temp->SetPoints(points);

	vtkSmartPointer<vtkVertexGlyphFilter> vertexFilter = 
	vtkSmartPointer<vtkVertexGlyphFilter>::New();
#if VTK_MAJOR_VERSION <= 5
  vertexFilter->SetInputConnection(temp->GetProducerPort());
#else
  vertexFilter->SetInputData(temp);
#endif
  vertexFilter->Update();
  pointCloudActor->getPolyData()->ShallowCopy(vertexFilter->GetOutput());
}
actor* pointCloudActorBuilder::getActor()const
{
	return pointCloudActor;
}
//sphereActorBuilder
sphereActorBuilder::sphereActorBuilder()
{
	sphereActor=new actor;
}
sphereActorBuilder::~sphereActorBuilder()
{
	delete sphereActor;
}
void sphereActorBuilder::buildSphereActor(std::string actorName="sphere")
{
	if(actorName=="")
		actorName="sphere";
	sphereActor->setActorName(actorName);
	build();
}
void sphereActorBuilder::build()
{
	vtkSmartPointer<vtkSphereSource> source =
	vtkSmartPointer<vtkSphereSource>::New();
	source->SetRadius(10);
    source->SetCenter(50, 50, 0);
    source->SetPhiResolution(11);
    source->SetThetaResolution(21);
	sphereActor->getMap()->SetInputConnection(source->GetOutputPort());
}
actor* sphereActorBuilder::getActor()const
{
	return sphereActor;
}