#pragma once

#include <QWidget>
#include <QPixmap>

class FluImgWidget : public QWidget 
{
public:
	FluImgWidget(QWidget* parent = nullptr, QPixmap pixmap = QPixmap());

	void setImg(QPixmap pixmap)
	{
		m_Img = pixmap;
	}

	QPixmap getImg()
	{
		return m_Img;
	}
protected:
	void paintEvent(QPaintEvent* event) override;
private:
	QPixmap m_Img;
};

