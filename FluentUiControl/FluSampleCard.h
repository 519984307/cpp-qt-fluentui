#pragma once

#include "FluDef.h"
#include "FluImgWidget.h"
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

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
public:
	FluSampleCard(QWidget* parent = nullptr, QPixmap img = QPixmap(), QString title = "", QString content = "", QString routeKey = "", int index = -1)
		: QWidget(parent), m_routeKey(routeKey), m_index(index)
	{
		m_imgWidget = new FluImgWidget(this, img);
		m_titleLabel = new QLabel(title);
		m_contentLabel = new QLabel(content);

		m_imgWidget->setFixedSize(48, 48);
		setFixedSize(360, 90);
	}

};

