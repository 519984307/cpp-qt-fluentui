#pragma once

#include "FluNavigationWidget.h"
#include "../FluentUiUtils/FluentUiThemeUtils.h"
#include <QPainter>
#include <QMargins>

class FluNavigationPushButton : public FluNavigationWidget
{
	Q_OBJECT
public:
	FluNavigationPushButton(QWidget* parent = nullptr, QPixmap icon = QPixmap(), QString text = "", bool bSelectable = false) :
		FluNavigationWidget(parent, bSelectable)
	{
		m_icon = icon;
		m_text = text;
		setStyleSheet("NavigationPushButton{font: 14px 'Segoe UI', 'Microsoft YaHei'}");
	}

	QString getText()
	{
		return m_text;
	}

	void setText(QString text)
	{
		m_text = text;
		update();
	}

	QPixmap getIcon()
	{
		return m_icon;
	}

	void setIcon(QPixmap icon)
	{
		m_icon = icon;
		update();
	}

	QMargins _margins()
	{
		return QMargins(0, 0, 0, 0);
	}

	bool _canDrawIndicator()
	{
		return getSelected();
	}

protected:
	void paintEvent(QPaintEvent* event) override
	{
		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
		painter.setPen(Qt::NoPen);

		if(!getPressed())
			painter.setOpacity(0.4);
		if (getPressed())
			painter.setOpacity(0.7);

		QColor normalCorlor = QColor(0, 0, 0, 6);
		QColor enterColor = QColor(0, 0, 0, 10);
		QColor fontColor = QColor(0, 0, 0);
		if (m_bDarkMode)
		{
			normalCorlor = QColor(255, 255, 255, 6);
			enterColor = QColor(255, 255, 255, 10);
			fontColor = QColor(255, 255, 255);
		}

		if (getSelected())
		{
			// 绘制背景
			painter.setBrush(normalCorlor);
			if (getEnter())
			{
				painter.setBrush(enterColor);
			}

			// 绘制竖线
			painter.drawRoundedRect(rect(), 5, 5);
			painter.setBrush(m_themeColor);
			painter.drawRoundedRect(0, 10, 3, 16, 1.5, 1.5);
		}

		if (!getSelected() && getEnter() && isEnabled())
		{
			painter.setBrush(enterColor);
			painter.drawRoundedRect(rect(), 5, 5);
		}

		painter.drawPixmap(QRect(11, 10, 16, 16), m_icon);
		if (!getCompacted())
		{
			painter.setFont(FluNavigationPushButton::font());
			painter.setPen(fontColor);
			painter.drawText(QRect(44, 0, width() - 57, height()), Qt::AlignVCenter, getText());
		}
	}

private:
	QPixmap m_icon;
	QString m_text;
	QColor m_themeColor;
	bool m_bDarkMode;
};

