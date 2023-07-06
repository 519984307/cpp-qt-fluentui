#include "FluDef.h"
#include "FluWidget.h"
#include <QPainter>

FluWidget::FluWidget(QWidget *parent)
	: QWidget(parent)
{
	FluSetObjectName(FluWidget);
	m_backgroundImg = nullptr;
}

FluWidget::~FluWidget()
{
}

void FluWidget::paintEvent(QPaintEvent* event)
{
	QWidget::paintEvent(event);
	QPainter painter(this);
	if (m_backgroundImg != nullptr)
	{
		m_backgroundImg->scaled(rect().width(), rect().height());
		painter.drawPixmap(rect(), (*m_backgroundImg));
	}
}

void FluWidget::resizeEvent(QResizeEvent* event)
{

}
