#include <QApplication>
#include <QWidget>
#include "../FluentUiControl/FluMainWidget.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	//QWidget w;
	//w.show();

	FluMainWidget w;
	w.show();

	

	return app.exec();
}