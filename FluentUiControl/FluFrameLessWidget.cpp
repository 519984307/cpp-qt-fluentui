#include "FluFrameLessWidget.h"

FluFrameLessWidget::FluFrameLessWidget(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
}

FluFrameLessWidget::~FluFrameLessWidget()
{

}
