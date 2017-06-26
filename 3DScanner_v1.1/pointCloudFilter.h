#ifndef _pointCloudFilter_H
#define _pointCloudFilter_H

#include "ui_pointCloudEditToolBar.h"
#include "ui_PointCloudFilterDocWidget.h"
#include <QtWidgets>
class pointCloudFilter:public QObject
{
	Q_OBJECT
public:
	pointCloudFilter(QMainWindow& mainWindow,Ui::pointCloudEditToolBar *toolbar);
	~pointCloudFilter();
signals:
	void setUndoEnabled(bool);
	void setPointCloudFilterChecked(bool);
private slots:
	void pointcloudFilter();
	void pointClouFilterSlot();

	void onCancelClickedSlot();

	void RadsliderMoveSlot(double);
	void RadboxValueChangeSlot(int);

	void SigmasliderMoveSlot(double);
	void SigmaboxValueChangeSlot(int);

	void ThrdsliderMoveSlot(double);
	void ThrdboxValueChangeSlot(int);

private:
	QDockWidget* pointCloudFilterDockWidget;
	Ui::PointCloudFilter PointCloudFilterDocWidget_ui;
};

#endif