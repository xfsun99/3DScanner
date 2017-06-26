#include "actor.h"
actor::actor()
{
	m_PolyData =vtkPolyData::New();
	m_map =vtkPolyDataMapper::New();
	m_actor =vtkActor::New();
	m_map->SetInputData(m_PolyData);
	m_actor->SetMapper(m_map);
	dataStateVector=new std::vector<vtkPolyData*>;
	currentStateInStateVector=new int(0);
	actorSate.isSelected=false;
	actorSate.isVisable=true;
}
actor::~actor()
{
	m_PolyData->Delete();
	m_map->Delete();
	m_actor->Delete();
	delete currentStateInStateVector;
	for(int i=0;i<dataStateVector->size();i++)
	{
		dataStateVector->at(i)->Delete();
	}
}
void actor::setPolyData(vtkSmartPointer<vtkPolyData> polydata)
{
}
void actor::setActorName(std::string name)
{
	actorName=name;
}
std::string actor::getActorName()const
{
	return actorName;
}
vtkSmartPointer<vtkPolyData> actor::getPolyData() const
{
	return m_PolyData;
}
vtkSmartPointer<vtkPolyDataMapper> actor::getMap() const
{
	return m_map;
}
vtkSmartPointer<vtkActor> actor::getActor() const
{
	return m_actor;
}
std::vector<vtkPolyData*>* actor::getDataStateVector()const
{
	return dataStateVector;
}
int* actor::getCurrentState()const
{
	return currentStateInStateVector;
}
void actor::addSate(vtkPolyData*state)
{
	*currentStateInStateVector=dataStateVector->size();
	dataStateVector->push_back(state);
}