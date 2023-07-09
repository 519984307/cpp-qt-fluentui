#pragma once

#include <QScrollArea>
#include <QWidget>
#include <QPixmap>
#include <QString>
#include "FluLinkCardWidget.h"

class FluLinkCardView : public QScrollArea
{
	Q_OBJECT
	FluSetPropertyP(QWidget, view);
	FluSetPropertyP(QHBoxLayout, hLayout);
public:
	FluLinkCardView(QWidget* parent = nullptr);
	void addCard(QPixmap img, QString title, QString content, QString url);
};

