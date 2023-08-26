#include <QApplication>
#include <QWidget>
#include "ButtonDemo.hpp"
#include "../FluentUiControl/FluCenterLabelWidget.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	//QWidget widget;
	//widget.show();

	//ButtonDemo buttonDemo;
	//buttonDemo.show();

	FluCenterLabelWidget widget(nullptr, "TempText");
	widget.show();

	return app.exec();
}