#pragma once

#include "FluNavigationWidget.h"
#include <QWidget>
#include <QPainter>

class FluNavigationAvatarWidget : public FluNavigationWidget
{
public:
	FluNavigationAvatarWidget(QWidget* parent) : FluNavigationWidget(parent)
	{

	}
protected:
	void paintEvent(QPaintEvent* event)
	{
		QPainter painter(this);
	}
public:
	void setAvatar(QPixmap icon)
	{
		m_icon = icon;
	}
private:
	QPixmap m_icon;
};

