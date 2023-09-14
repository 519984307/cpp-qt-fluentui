#include <QApplication>
#include <QWidget>
#include "ButtonDemo.h"
#include "../FluentUiControl/FluCenterLabelWidget.h"
#include "../FluentUiUtils/FluentUiLogUtils.h"
#include "ApiTest_QCursor.h"
#include "FluToolTipDemo.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	//QWidget widget;
	//widget.show();

	//ButtonDemo buttonDemo;
	//buttonDemo.show();

	FluentUiLogUtils::init();

	//FluCenterLabelWidget widget(nullptr, "TempText");
	//widget.show();

	//ApiTest_QCursor apiTest_Qcursor;
	//apiTest_Qcursor.show();

	FluToolTipDemo demo;
	demo.show();

	return app.exec();
}