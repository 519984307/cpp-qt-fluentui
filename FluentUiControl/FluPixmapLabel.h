#pragma once

#include <QLabel>
#include <QPainter>

class FluPixmapLabel : public QLabel
{
public:
	FluPixmapLabel(QWidget* parent = nullptr);

	void setPixmap(QPixmap pixmap);

	QPixmap getPixmap();

protected:
	void paintEvent(QPaintEvent* event);
private:
	QPixmap m_pixmap;
};

