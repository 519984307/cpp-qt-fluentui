#include "FluPixmapLabel.h"

FluPixmapLabel::FluPixmapLabel(QWidget* parent /*= nullptr*/) : QLabel(parent)
{

}

void FluPixmapLabel::setPixmap(QPixmap pixmap)
{
	m_pixmap = pixmap;
	setFixedSize(m_pixmap.size());
	update();
}

QPixmap FluPixmapLabel::getPixmap()
{
	return m_pixmap;
}

void FluPixmapLabel::paintEvent(QPaintEvent* event)
{
	if (m_pixmap.isNull())
		return;

	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	painter.setPen(Qt::NoPen);
	painter.drawPixmap(rect(), m_pixmap);
}
