#ifndef _selectSurfacePointUsePoly_H
#define _selectSurfacePointUsePoly_H

#include <vtkInteractorStyleDrawPolygon.h>
#include <vtkPolyData.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkDataSetMapper.h>
#include <vtkOpenGLHardwareSelector.h>
#include <vtkExtractSelection.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleDrawPolygon.h>
#include <vtkRendererCollection.h>
#include <vtkSelection.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkIdTypeArray.h>
#include <vtkPointData.h>
#include <vtkProperty.h>

class selectSurfacePointUsePoly: public vtkInteractorStyleDrawPolygon 
{
	vtkTypeMacro(selectSurfacePointUsePoly, vtkInteractorStyleDrawPolygon);	
public:
	static selectSurfacePointUsePoly* getInstance();
	//overwrite the OnLeftButtonUp action
	virtual void OnLeftButtonUp();
	//set input data to be selected
	void setData(vtkPolyData* DataToSelect);
	//disconstruct function
	~selectSurfacePointUsePoly();
	//set FieldAssociation, select point select mode or cell select mode,
	//FieldAssociation=vtkDataObject::FIELD_ASSOCIATION_POINTS
	//or vtkDataObject::FIELD_ASSOCIATION_CELLS.
	void setSlecterFieldAssociation(int FieldAssociation=vtkDataObject::FIELD_ASSOCIATION_POINTS);
	//get selected data set in vtkPolyData* type 
	vtkPolyData*getSelectedData();
	//get selected data ids in vtkIdTypeArray* type
	vtkIdTypeArray* getSelectedIds();
	//get the data be selected from
	vtkPolyData* getDataSelectedFrom();
	//get if selected id empty or not
	bool isSelecteEmpty();
	//void require reselect action,this function just set the selectedIsEmpty=true
	void requireReselect();
	//remove actor,this is used for deleteaction
	void removeActor();
	//update display window after every action
	void display();

private :
	static selectSurfacePointUsePoly* Instance;
	selectSurfacePointUsePoly();
	//actor for selected part to render
	vtkSmartPointer<vtkActor> actor;
	//mapper for selected part to render
	vtkSmartPointer<vtkDataSetMapper> mapper;
	//hardware selector 
	vtkSmartPointer<vtkOpenGLHardwareSelector> selector;
	//extract selection
	vtkSmartPointer<vtkExtractSelection> extractSelection;
	//render for selected part,the same as the render in vtkDisplayClass
	vtkSmartPointer<vtkRenderer> Renderer;
	//the render window, there is only a render window in a project
	vtkSmartPointer<vtkRenderWindow> win;
	//the data to be selected form
	vtkSmartPointer<vtkPolyData> Data;
	//selected data
	vtkSmartPointer<vtkPolyData> selectedData;
	//vtkVertexGlyphFilter
	vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter;
	//selected result is empty or not
	bool selectedIsEmpty;
};
#endif