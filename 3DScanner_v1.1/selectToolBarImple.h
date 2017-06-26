#ifndef _selectToolBarImple_H
#define _selectToolBarImple_H
#include <QObject>
#include <QAction>
#include "ui_selectToolBar.h"
#include <vtkEventQtSlotConnect.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkVertexGlyphFilter.h>
class selectToolBarImple:public QObject
{
	Q_OBJECT
public:

	selectToolBarImple(Ui::selectToolbar* selecttoolbar);
	~selectToolBarImple();
	//the slot of signal PolySelectActionDoneSignal from class selectSurfacePointUsePoly ,
	//when select done the signal emit,the icon state is changge in this slot
	static void PolySelectActionDoneSlot();
signals:
	//change redo and undo icon state
	void setRedoEnabled(bool);
	void setUndoEnabled(bool);
	private slots:
		//the reaction of PolySelectSurfacePoint
		void PolySelectSurfacePointSlot();
		//the reaction of PolySelectSurfaceCell
		void PolySelectSurfaceCellSlot();
		//the reaction of SelectPointOn
		void SelectPointOnSlot();
		//the reaction of SelectPointThroug
		void SelectPointThrougSlot();
		//the reaction of SelectCellOn
		void SelectCellOnSlot();
		//the reaction of SelectCellThroug
		void SelectCellThrougSlot();
		//the reaction of saveSelectedPart
		void SaveSelectedPartSlot();
		//the reaction of deleteSelectedPart
		void deleteSlectedPartSlot();
private:
	//next three menber are use for point to polydata transition
	vtkSmartPointer<vtkPolyData> temp;
	vtkSmartPointer<vtkPolyData> tempOfSourceData;
	vtkSmartPointer<vtkVertexGlyphFilter> vertexFilter;
	//record the current display datasource index in datavector
	int *undoAndRedoCount;
};

#endif