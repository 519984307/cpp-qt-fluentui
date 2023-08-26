#pragma once

#include "FluNavigationBaseTreeWidget.h"

class FluNavigationTreeWidget : public FluNavigationBaseTreeWidget
{
public:
	FluNavigationTreeWidget(QWidget* parent, QPixmap icon, QString text, bool isSelectable)
	{

	}
private:
	QVector<FluNavigationTreeWidget*> m_treeWidgets;
};

