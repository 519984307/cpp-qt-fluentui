#pragma once

#include "FluDef.h"
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "FluFlowLayout.h"

class FluSampleCardView : public QWidget
{
	Q_OBJECT
	FluSetPropertyP(QLabel, titleLabel);
	FluSetPropertyP(QVBoxLayout, vLayout);
	FluSetPropertyP(FluFlowLayout, flowLayout);
public:
	FluSampleCardView(QWidget* parent = nullptr, QString title = "");
protected:
	void resizeEvent(QResizeEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
public:
	void addSampleCard(QPixmap img, QString title, QString content, QString routeKey, int index);
};

