#include "FluLinkCardView.h"
#include <QStyle>
#include <QPainter>
#include <QStyleOption>
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"

FluLinkCardView::FluLinkCardView(QWidget* parent /*= nullptr*/) : QScrollArea(parent)
{
	m_view = new QWidget(this);
	m_hLayout = new QHBoxLayout(this);

	m_hLayout->setContentsMargins(26, 0, 36, 0);
	m_hLayout->setSpacing(12);
	m_hLayout->setAlignment(Qt::AlignLeft);

	setWidget(m_view);
	setWidgetResizable(true);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	m_view->setObjectName("view");
	//setStyleSheet("background-color:transparent;border:none;");

	QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluLinkCardView.qss");
	setStyleSheet(qss);
}

void FluLinkCardView::addCard(QPixmap img, QString title, QString content, QString url)
{
	FluLinkCardWidget* cardWidget = new FluLinkCardWidget(m_view, img, title, content, url);
	m_hLayout->addWidget(cardWidget, 0, Qt::AlignLeft);
}

void FluLinkCardView::paintEvent(QPaintEvent* event)
{
	QStyleOption opt;
	opt.initFrom(this);
	QPainter painter(viewport());
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
