#ifndef _SaveDataReaction_H
#define _SaveDataReaction_H
#include <QObject>
#include <QAction>
#include <vtkSmartPointer.h>
#include <vtkSimplePointsWriter.h>
#include <vtkSTLWriter.h>
class SaveDataReaction:public QObject
{
	Q_OBJECT
public: 
	SaveDataReaction(QAction* action);
	~SaveDataReaction();
	void savestlData(std::string filename);
	void saveSampleData(std::string filename);
	private slots:
		void saveData();
		void setActionEnable(bool);
private:
	vtkSmartPointer<vtkSimplePointsWriter> sampleWriter;
	vtkSmartPointer<vtkSTLWriter> stlWriter;
	QAction *m_action;

};

#endif