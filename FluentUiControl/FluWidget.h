#pragma once

#include <QWidget>
#include <QEvent>
#include <QPixmap>
#include "FluentUiControlGlobal.h"

class FLUENTUICONTROL_EXPORT FluWidget : public QWidget
{
	Q_OBJECT

public:
	FluWidget(QWidget *parent = nullptr);
	~FluWidget();

	void setBackgrondImg(QPixmap backgroundImg)
	{
		m_backgroundImg = new QPixmap(backgroundImg);
	}

	QPixmap* getBackgrondImg()
	{
		return m_backgroundImg;
	}

protected:
	void paintEvent(QPaintEvent* event) override;
	void resizeEvent(QResizeEvent* event) override;
protected:
	QPixmap *m_backgroundImg;
};
