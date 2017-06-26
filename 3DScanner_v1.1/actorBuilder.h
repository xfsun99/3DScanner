#ifndef _actorBuilder_H
#define _actorBuilder_H
#include "actor.h"
#include "StereoReconstruct.h"
class actorBuilder
{
public:
	virtual void buildPointCloudActor(std::string actorName)=0;
	virtual void buildSphereActor(std::string actorName)=0;
	virtual actor* getActor()const=0;
};

class pointCloudActorBuilder:public actorBuilder
{
public:
	pointCloudActorBuilder();
	virtual ~pointCloudActorBuilder();
	void buildPointCloudActor(std::string actorName);
	void buildSphereActor(std::string actorName){}
	void build(vector<p3*>&pout);
	void build();
	actor* getActor()const;
private:
	actor* pointCloudActor;
};

class sphereActorBuilder:public actorBuilder
{
public:
	sphereActorBuilder();
	virtual ~sphereActorBuilder();
	void buildSphereActor(std::string actorName);
	void buildPointCloudActor(std::string actorName){}
	void build();
	actor* getActor() const;
private:
	actor* sphereActor;
};
#endif