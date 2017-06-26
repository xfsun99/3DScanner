#ifndef _actor_H
#define _actor_H
#include <vtkActor.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
struct actorStructSate
{
	bool isSelected;
	bool isVisable;
};
class actor
{
public:
	actor();
	~actor();
	actorStructSate actorSate;
	void setPolyData(vtkSmartPointer<vtkPolyData> polydata);
	//void setMap(vtkSmartPointer<vtkDataSetMapper> map);
	void setActorName(std::string name);
	//get actor struct name
	std::string getActorName()const;
	//get get the pointer of state vector
	std::vector<vtkPolyData*>* getDataStateVector()const;
	//get current state index in sate vector
	int* getCurrentState()const;
	//add a state 
	void addSate(vtkPolyData*state);
	//get polyData in actor struct
	vtkSmartPointer<vtkPolyData> getPolyData() const;
	//get map
	vtkSmartPointer<vtkPolyDataMapper> getMap() const;
	//get actor 
	vtkSmartPointer<vtkActor>		getActor() const;

private:
		vtkSmartPointer<vtkPolyData> m_PolyData;
		vtkSmartPointer<vtkPolyDataMapper> m_map;
		vtkSmartPointer<vtkActor>		m_actor;
		std::string actorName;
		std::vector<vtkPolyData*>* dataStateVector;
		int *currentStateInStateVector;
};

#endif