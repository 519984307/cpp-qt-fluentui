#include <QApplication>
#include <QWidget>
#include "../FluentUiControl/FluFrameLessWidget.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	//QWidget w;
	//w.show();

	FluFrameLessWidget w;
	w.show();

	

	return app.exec();
}