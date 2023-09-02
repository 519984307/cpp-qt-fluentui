#pragma once

#include "FluNavigationWidget.h"
#include <QWidget>
#include <QPainter>
#include "../FluentUiUtils/FluentUiThemeUtils.h"

class FluNavigationAvatarWidget : public FluNavigationWidget
{
	Q_OBJECT
public:
	FluNavigationAvatarWidget(QWidget* parent) : FluNavigationWidget(parent)
	{

	}
protected:
	void paintEvent(QPaintEvent* event) override
	{
		QPainter painter(this);
		// 绘制头像更加平滑
		painter.setRenderHints(QPainter::SmoothPixmapTransform | QPainter::Antialiasing);
		painter.setPen(Qt::NoPen);
		if (getPressed())
			painter.setOpacity(0.7);
		if (getEnter())
		{
			// 绘制背景颜色
			if (FluentUiThemeUtils::getInstance()->getDarkMode() == FluentUiThemeUtilsDarkMode::Dark)
			{
				QColor bgColor = QColor(255, 255, 255, 10);
				painter.setBrush(bgColor);
				painter.drawRoundedRect(rect(), 5, 5);
			}

			if (FluentUiThemeUtils::getInstance()->getDarkMode() == FluentUiThemeUtilsDarkMode::Light)
			{
				QColor bgColor = QColor(0, 0, 0, 10);
				painter.setBrush(bgColor);
				painter.drawRoundedRect(rect(), 5, 5);
			}
		}

		// 绘制头像
		painter.setBrush(QBrush(m_avatar));
		painter.translate(8, 6);
		painter.drawEllipse(0, 0, 24, 24);
		painter.translate(-8, -6);

		if (!getCompacted())
		{
			if (FluentUiThemeUtils::getInstance()->getDarkMode() == FluentUiThemeUtilsDarkMode::Dark)
			{
				painter.setPen(Qt::white);
				painter.setFont(font());
				painter.drawText(44, 0, 255, 36, Qt::AlignVCenter, getName());
			}

			if (FluentUiThemeUtils::getInstance()->getDarkMode() == FluentUiThemeUtilsDarkMode::Light)
			{
				painter.setPen(Qt::black);
				painter.setFont(font());
				painter.drawText(44, 0, 255, 36, Qt::AlignVCenter, getName());
			}
		}
	}
public:
	QString getName()
	{
		return m_name;
	}

	void setName(QString name)
	{
		m_name = name;
		update();
	}

	QPixmap getAvatar()
	{
		return m_avatar;
	}

	void setAvatar(QPixmap avatar)
	{
		// 保持长宽比，并使得图像平滑
		m_avatar =  avatar.scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	}
private:
	QString m_name;
	QPixmap m_avatar;
};

