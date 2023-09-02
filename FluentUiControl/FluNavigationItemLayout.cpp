#include "FluNavigationItemLayout.h"

FluNavigationItemLayout::FluNavigationItemLayout(QWidget* parent /*= nullptr*/) : QVBoxLayout(parent)
{

}

void FluNavigationItemLayout::setGeometry(const QRect& rect)
{
	QVBoxLayout::setGeometry(rect);
	for (int i = 0; i < count(); i++)
	{
		QLayoutItem* item = itemAt(i);
		if (item->widget() && item->widget()->metaObject()->className() == "FluNavigationSeparator")
		{
			QRect itemGeometry =  item->geometry();
			item->widget()->setGeometry(0, itemGeometry.y(), itemGeometry.width(), itemGeometry.height());
		}
	}
}
