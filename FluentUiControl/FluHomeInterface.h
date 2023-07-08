#pragma once

#include "FluDef.h"
#include <QScrollArea>
#include <QVBoxLayout>

class FluHomeInterface : public QScrollArea
{
	Q_OBJECT

	FluSetPropertyP(QWidget,view);
	FluSetPropertyP(QVBoxLayout, vLayout);
public:
	FluHomeInterface(QWidget* parent = nullptr) : QScrollArea(parent)
	{

	}


};

