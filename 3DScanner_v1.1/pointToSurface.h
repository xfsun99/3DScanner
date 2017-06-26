#ifndef _pointToSurface_H
#define _pointToSurface_H
#include "ui_pointCloudEditToolBar.h"
#include "ui_PointToSurfaceDocWidget.h"
#include <QtWidgets>
class pointToSurface:public QObject
{
	Q_OBJECT
public:
	pointToSurface(QMainWindow& mainWindow,Ui::pointCloudEditToolBar *toolbar);
	~pointToSurface();
signals:
	void setUndoEnabled(bool);
	void setPointToSurfaceChecked(bool);
private slots:
	void pointtosurface();
	void pointToSurfaceSlot();
	void onCancelClickedSlot();

	void AlphasliderMoveSlot(double);
	void AlphaboxValueChangeSlot(int);


private:
	QDockWidget* PointToSurfaceDocWidget;
	Ui::PointToSurfaceDocWidget PointToSurfaceDocWidget_ui;
};

#endif