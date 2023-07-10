#include <QApplication>
#include <QWidget>
#include "../FluentUiControl/FluMainWidget.h"
#include "../FluentUiControl/FluSampleCard.h"
#include "../FluentUiUtils/FluentUiLogUtils.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	FluentUiLogUtils::init();
	LogDebug << "called!";

	FluMainWidget w;
	w.show();
	
	return app.exec();
}