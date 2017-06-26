#include"normalInteractorStyle.h"

normalInteractorStyle*normalInteractorStyle::Instance=NULL;
normalInteractorStyle::normalInteractorStyle()
{
	Instance=this;
}
normalInteractorStyle*normalInteractorStyle::getInstance()
{
	if(Instance==NULL)
	{
		Instance=new normalInteractorStyle;
	}
	return Instance;
}