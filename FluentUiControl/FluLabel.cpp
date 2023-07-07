#include "FluDef.h"
#include "FluLabel.h"

FluLabel::FluLabel(QWidget *parent)
	: QLabel(parent)
{
	FluSetNameAndStypeSheet(FluLabel);
}

FluLabel::~FluLabel()
{
}
