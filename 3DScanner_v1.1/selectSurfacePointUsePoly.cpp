#include "selectSurfacePointUsePoly.h"
#include "vtkDisplayClass.h"
#include <vtkCommand.h>
#include "selectToolBarImple.h"
#include"normalInteractorStyle.h"
selectSurfacePointUsePoly*selectSurfacePointUsePoly::Instance=NULL;

selectSurfacePointUsePoly::selectSurfacePointUsePoly()
{
	Instance=this;
	actor =vtkSmartPointer<vtkActor>::New();
	mapper =vtkSmartPointer<vtkDataSetMapper>::New();

	actor->SetMapper(mapper);
	//selected is empty at begining
	selectedIsEmpty=true;

	selector = vtkSmartPointer<vtkOpenGLHardwareSelector>::New();
	extractSelection =vtkSmartPointer<vtkExtractSelection>::New();
	glyphFilter =vtkSmartPointer<vtkVertexGlyphFilter>::New();
	selectedData=vtkPolyData::New();

	vtkDisplayClass*instance=vtkDisplayClass::getInstance();
	Renderer=instance->getRender();
	this->SetCurrentRenderer(Renderer);
	this->win=instance->getRenderWindow();
} 
selectSurfacePointUsePoly::~selectSurfacePointUsePoly()
{
	actor->Delete();
	mapper->Delete();
	selector->Delete();
	extractSelection->Delete();
	glyphFilter->Delete();
	selectedData->Delete();
	delete Instance;
}
void selectSurfacePointUsePoly::setData(vtkPolyData* DataToSelect)
{
	Data=DataToSelect;
}
selectSurfacePointUsePoly*selectSurfacePointUsePoly::getInstance()
{
	if(Instance==NULL)
	{
	Instance=new selectSurfacePointUsePoly;
	}
	return Instance;
}
void selectSurfacePointUsePoly::setSlecterFieldAssociation(int FieldAssociation)
{
	selector->SetFieldAssociation(FieldAssociation);
}
void selectSurfacePointUsePoly::OnLeftButtonUp()
{
	//selected is empty at begining
	selectedIsEmpty=true;
	vtkInteractorStyleDrawPolygon::OnLeftButtonUp();
    // Get the poly points
	std::vector<vtkVector2i> v=this->GetPolygonPoints();
	vtkIdType count=v.size();
	int *polygonPoints=new int[2*count];
	for(int i=0;i<count;i=i+1)
	{
		polygonPoints[2*i]=v[i].GetX();
		polygonPoints[2*i+1]=v[i].GetY();
	}
	selector->SetRenderer(Renderer);
	int* temp = this->Interactor->GetRenderWindow()->GetSize();
    unsigned int windowSize[4];
    windowSize[0] = temp[2];
    windowSize[1] = temp[3];
    windowSize[2] = temp[0];
    windowSize[3] = temp[1];
	//set select boundary in the render window
    selector->SetArea(windowSize);	
	//CaptureBuffers must be called first
	if(selector->CaptureBuffers())
	{
		selector->Modified();
		vtkSelection* selection =selector->GeneratePolygonSelection(polygonPoints, 2*count);
		if(selection!=NULL&& selection->GetNumberOfNodes())
		{
			//selected is not empty
			selectedIsEmpty=false;
		#if VTK_MAJOR_VERSION <= 5
			extractSelection->SetInput(0, this->Data);
			extractSelection->SetInput(1, selection);
		#else
			extractSelection->SetInputData(0, this->Data);
			extractSelection->SetInputData(1, selection);
		#endif
			extractSelection->Update();
					
			glyphFilter->SetInputConnection(extractSelection->GetOutputPort());
			glyphFilter->Update();	
			selectedData->DeepCopy(glyphFilter->GetOutput());
			//set mapper input
			mapper->SetInputConnection(extractSelection->GetOutputPort());
			//set actor property
			actor->GetProperty()->SetColor(1,0,0);
			actor->GetProperty()->SetPointSize(3);
			//render the actor
			this->Renderer->AddActor(actor);
		}	
	}	
	this->win->Render();
	selectToolBarImple::PolySelectActionDoneSlot();
}
vtkPolyData*selectSurfacePointUsePoly::getSelectedData()
{
	return selectedData;
}
vtkIdTypeArray* selectSurfacePointUsePoly::getSelectedIds()
{
	return vtkIdTypeArray::SafeDownCast(selectedData->GetPointData()->GetArray("vtkOriginalPointIds"));
}
vtkPolyData* selectSurfacePointUsePoly::getDataSelectedFrom()
{
	return Data;
}
//call befor delete or save action
bool selectSurfacePointUsePoly::isSelecteEmpty()
{
	return selectedIsEmpty;
}
//call after delete or save action
void selectSurfacePointUsePoly::requireReselect()
{
	selectedIsEmpty=true;
}
//called after delete action
void selectSurfacePointUsePoly::removeActor()
{
		this->Renderer->RemoveActor(actor);
}
void selectSurfacePointUsePoly::display()
{
		this->win->Render();
}