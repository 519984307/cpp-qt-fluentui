#pragma once

#include "FluDef.h"
#include "FluImgWidget.h"
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMouseEvent>

class FluSampleCard : public QWidget
{
	Q_OBJECT

		FluSetPropertyN(QString, routeKey);
	FluSetPropertyN(int, index);
	FluSetPropertyP(FluImgWidget, imgWidget);
	FluSetPropertyP(QLabel, titleLabel);
	FluSetPropertyP(QLabel, contentLabel);
	FluSetPropertyP(QVBoxLayout, vLayout);
	FluSetPropertyP(QHBoxLayout, hLayout);

signals:
	void swithSampleCard(QString m_routeKey, int m_index);
public:
	FluSampleCard(QWidget* parent = nullptr, QPixmap img = QPixmap(), QString title = "", QString content = "", QString routeKey = "", int index = -1);
protected:
	void mouseReleaseEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
};