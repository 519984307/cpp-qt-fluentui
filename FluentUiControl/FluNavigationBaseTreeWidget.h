#pragma once

#include "FluNavigationWidget.h"

class FluNavigationBaseTreeWidget : public FluNavigationWidget 
{
	Q_OBJECT
public:
	virtual void addChild() = 0;
	virtual void insertChild(int index, FluNavigationWidget* widget) = 0;
	virtual void removeChild(FluNavigationWidget* widget) = 0;
	virtual bool isRoot() = 0;
	virtual bool isLeaf() = 0;
	virtual void setExpanded() = 0;
	virtual QVector<FluNavigationWidget*> childItems() = 0;
};

