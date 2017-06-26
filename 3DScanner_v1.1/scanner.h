#ifndef SCANNER_H
#define SCANNER_H
#include <QtWidgets/QMainWindow>
#include "ui_scanner.h"
#include "OpenCVPreprocessClass.h"
#include "OpenCLClass.h"
#include "StereoReconstruct.h"
class scanner : public QMainWindow
{
	Q_OBJECT
public:
	scanner(QWidget *parent = 0);
	~scanner();
	public slots:
		void onStereoReconstruct();
private:
	Ui::scannerClass		ui;
};
#endif
