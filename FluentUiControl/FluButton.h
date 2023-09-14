#pragma once

#include <QPushButton>
#include <QIcon>
#include <QApplication>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"

class FluPushButton : public QPushButton
{
	//Q_OBJECT
public:
	FluPushButton(QWidget* parent) : QPushButton(parent)
	{
		m_isPressed = false;
		m_isHover = false;
		setIconSize(QSize(16, 16));
		setIcon(QIcon());

		setFont();

		//_postInit();

		QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluPushButton.qss");
		setStyleSheet(qss);
	}

	FluPushButton(QString text, QWidget* parent = nullptr, QIcon icon = QIcon())
		: FluPushButton(parent)
	{
		setText(text);
		setIcon(icon);
	}

	//void _postInit()
	//{

	//}

	void setIcon(QIcon icon)
	{
		setProperty("hasIcon", !icon.isNull());
		setStyle(QApplication::style());
		m_icon = icon;
		update();
	}

	QIcon getIcon()
	{
		return m_icon;
	}

	void setFont(int fontSize = 14, QFont::Weight weight = QFont::Normal)
	{
		QPushButton::setFont(getFont(fontSize, weight));
	}

	QFont getFont(int fontSize = 14, QFont::Weight weight = QFont::Normal)
	{
		QFont font;
		font.setFamilies({ "Segoe UI", "Microsoft YaHei" });
		font.setPixelSize(fontSize);
		font.setWeight(weight);
		return font;
	}

	void mousePressEvent(QMouseEvent* e)
	{
		m_isPressed = true;
		QPushButton::mousePressEvent(e);
	}

	void mouseReleaseEvent(QMouseEvent* e)
	{
		m_isPressed = false;
		QPushButton::mouseReleaseEvent(e);
	}

	void enterEvent(QEnterEvent* event)
	{
		m_isHover = true;
		update();
	}

	void leaveEvent(QEvent* event)
	{
		m_isHover = false;
		update();
	}

	void paintEvent(QPaintEvent* event)
	{
		QPushButton::paintEvent(event);
		if (m_icon.isNull())
			return;

		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

		if (!isEnabled())
			painter.setOpacity(0.3628);
		else
			painter.setOpacity(0.786);

		int iconW = iconSize().width();
		int iconH = iconSize().height();


		int minW = minimumSizeHint().width();
		int y = (height() - iconH) / 2;
		int x = 12;
		if (minW > 0)
			x = 12 + (width() - minW) / 2;

		QPixmap pixmap = m_icon.pixmap(iconW, iconH);
		painter.drawPixmap(x, y, pixmap);
	}
private:
	bool m_isPressed;
	bool m_isHover;
	QIcon m_icon;
};

