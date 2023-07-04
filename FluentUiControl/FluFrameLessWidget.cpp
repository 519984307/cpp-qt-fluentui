#include "FluFrameLessWidget.h"
#include <QMouseEvent>

FluFrameLessWidget::FluFrameLessWidget(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
	m_bMouseLeftBtnPress = false;
	m_mouseLeftBtnPressPoint = QPoint(0, 0);
}

FluFrameLessWidget::~FluFrameLessWidget()
{

}

void FluFrameLessWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (!m_bMouseLeftBtnPress)
	{
		return;
	}

	move(event->pos() - m_mouseLeftBtnPressPoint + pos());
}

void FluFrameLessWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
	{
		return;
	}

	m_bMouseLeftBtnPress = true;
	m_mouseLeftBtnPressPoint = event->pos();
}

void FluFrameLessWidget::mouseReleaseEvent(QMouseEvent* event)
{
	m_bMouseLeftBtnPress = false;
}
