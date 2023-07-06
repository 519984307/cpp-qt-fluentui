#include "FluImgWidget.h"
#include <QPainter>

FluImgWidget::FluImgWidget(QWidget* parent /*= nullptr*/, QPixmap pixmap /*= QPixmap()*/)
	: QWidget(parent), m_Img(pixmap)
{

}

void FluImgWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	painter.drawPixmap(rect(), m_Img);
}
