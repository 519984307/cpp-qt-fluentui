#pragma once

#include <QVBoxLayout>
#include <QLayoutItem>
#include <QWidget>

class FluNavigationItemLayout : public QVBoxLayout 
{
	Q_OBJECT
public:
	void setGeometry(const QRect& rect)
	{
		QVBoxLayout::setGeometry(rect);
		for (int i = 0; i < count(); i++)
		{
			QLayoutItem* item = itemAt(i);
			if (item->widget()->metaObject()->className() == "FluNavigationSeparator")
			{
				item->widget()->setGeometry(0, geometry().y(), geometry().width(), geometry().height());
			}
		}
	}
};

