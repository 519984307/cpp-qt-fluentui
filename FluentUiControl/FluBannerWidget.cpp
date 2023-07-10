#include "FluBannerWidget.h"
#include <QPainter>
#include <QPainterPath>

FluBannerWidget::FluBannerWidget(QWidget* parent /*= nullptr*/) : QWidget(parent)
{
	setFixedHeight(360);
	m_vLayout = new QVBoxLayout(this);
	m_galleryLabel = new QLabel("FluentUI Gallery", this);
//	m_galleryLabel->setStyleSheet("font: 42px 'Segoe UI', 'Microsoft YaHei';font-weight: bold;background-color: transparent;color: black;padding-left: 28px;");
	m_img = QPixmap("../res/bg_home_header.png");

	m_linkCardView = new FluLinkCardView(this);
	m_galleryLabel->setObjectName("galleryLabel");

	m_vLayout->setSpacing(0);
	m_vLayout->setContentsMargins(0, 20, 0, 20);
	m_vLayout->addWidget(m_galleryLabel);
	m_vLayout->addWidget(m_linkCardView, 1, Qt::AlignBottom);
	m_vLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

	m_linkCardView->addCard(QPixmap("../res/ic_home_github.png"),
		"FluentUI GitHub",
		"The latest FluentUI controls and styles for your applications.",
		"https://github.com/mowangshuying/CppQtFluentUI");
}

void FluBannerWidget::paintEvent(QPaintEvent* event)
{
	QWidget::paintEvent(event);

	QPainter painter(this);
	painter.setRenderHints(QPainter::SmoothPixmapTransform | QPainter::Antialiasing);
	painter.setPen(Qt::NoPen);

	QPainterPath painterPath;
	painterPath.setFillRule(Qt::WindingFill);

	int  tmpW = width();
	int tmpH = height();

	painterPath.addRoundedRect(QRectF(0, 0, tmpW, tmpH), 10, 10);
	painterPath.addRect(QRectF(0, tmpH - 50, 50, 50));
	painterPath.addRect(QRectF(0, tmpH - 50, 50, 50));
	painterPath.addRect(QRectF(tmpW - 50, 0, 50, 50));
	painterPath.addRect(QRectF(tmpW - 50, tmpH - 50, 50, 50));

	painterPath = painterPath.simplified();

	painter.fillPath(painterPath, QColor(206, 216, 228));

	QPixmap tmpPixmap = m_img.scaled(tmpW, tmpH);
	painterPath.addRect(QRectF(0, tmpH, tmpW, height() - tmpH));
	painter.fillPath(painterPath, QBrush(tmpPixmap));
}
