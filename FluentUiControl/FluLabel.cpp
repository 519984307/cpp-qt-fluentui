#include "FluDef.h"
#include "FluLabel.h"

FluLabel::FluLabel(QWidget *parent)
	: QLabel(parent)
{
	FluSetProperty(FluLabel);
}

FluLabel::~FluLabel()
{
}
