#pragma once

#include "FluNavigationWidget.h"
#include <QPaintEvent>
#include <QPainter>
#include "../FluentUiUtils/FluentUiThemeUtils.h"

class FluNavigationSeparator : public FluNavigationWidget
{
public:
	FluNavigationSeparator(QWidget* parent = nullptr) : FluNavigationWidget(parent, false)
	{
		setCompacted(true);
	}

	void setCompacted(bool bCompacted)
	{
		if (bCompacted)
		{
			setFixedSize(48, 3);
		}
		else
		{
			setFixedSize(312 + 10, 3);
		}
		update();
	}

	//bool getDarkMode()
	//{
	//	return m_bDarkMode;
	//}

	//void setDarkMode(bool bDarkMode)
	//{
	//	m_bDarkMode = bDarkMode;
	//}
protected:
	void paintEvent(QPaintEvent* event)
	{
		QPainter painter(this);
		QColor bgColor = QColor(0, 0, 0, 15);
		if (FluentUiThemeUtils::getInstance()->getDarkMode() == FluentUiThemeUtilsDarkMode::Dark)
		{
			bgColor = QColor(255, 255, 255, 15);
		}

		QPen pen = QPen(bgColor);
		pen.setCosmetic(true); // 此处是否可以去掉
		painter.setPen(pen);
		painter.drawLine(0, 1, width(), 1);
	}
private:
	//bool m_bDarkMode;
};

