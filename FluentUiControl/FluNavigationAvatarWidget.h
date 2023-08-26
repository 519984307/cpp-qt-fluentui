#pragma once

#include "FluNavigationWidget.h"
#include <QWidget>
#include <QPainter>

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
		painter.setRenderHints(QPainter::SmoothPixmapTransform | QPainter::Antialiasing);

		painter.setPen(Qt::NoPen);

		if (getPressed())
			painter.setOpacity(0.7);

		if (getEnter())
		{
			
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
		m_avatar =  avatar.scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	}
private:
	QString m_name;
	QPixmap m_avatar;
};

