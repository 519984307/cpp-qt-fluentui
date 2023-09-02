#pragma once

#include <QVBoxLayout>
#include <QLayoutItem>
#include <QWidget>

class FluNavigationItemLayout : public QVBoxLayout 
{
	Q_OBJECT
public:
	FluNavigationItemLayout(QWidget* parent = nullptr);
public:
	void setGeometry(const QRect& rect);
};

