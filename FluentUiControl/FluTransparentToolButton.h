#pragma once

#include <QToolButton>
#include <QPainter>
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"

class FluTransparentToolButton : public QToolButton
{
	//Q_OBJECT
public:
	FluTransparentToolButton(QWidget* parent = nullptr, QPixmap icon = QPixmap()) : QToolButton(parent), m_icon(icon)
	{
		QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluTransparentToolButton.qss");
		setStyleSheet(qss);
		setText("FluTransparentToolButton");


	}

protected:
	void paintEvent(QPaintEvent* event) override
	{
		QToolButton::paintEvent(event);

		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

		int iconW = iconSize().width();
		int iconH = iconSize().height();

		int wndW = width();
		int wndH = height();

		QRect iconRect = QRect( (wndW - iconW) / 2, (wndH - iconH) / 2, iconW, iconH);
		painter.drawPixmap(iconRect, m_icon);

	}
private:
	QPixmap m_icon;
};

