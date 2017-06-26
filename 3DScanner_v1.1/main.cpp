#include "scanner.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	scanner w;
	w.show();
	return a.exec();
}
