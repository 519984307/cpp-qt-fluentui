#include "FluLinkCardWidget.h"
#include <QDesktopServices>

FluLinkCardWidget::FluLinkCardWidget(QWidget* parent /*= nullptr*/, QPixmap img /*= QPixmap()*/, QString title /*= ""*/, QString content /*= ""*/, QString url/*= "" */)
	: QWidget(parent)
{
	setFixedSize(200, 220);
	m_url = QUrl(url);

	m_vLayout = new QVBoxLayout(this);
	m_iconWidget = new FluImgWidget(this, img);
	m_titleLabel = new QLabel(this);
	m_contentLabel = new QLabel(this);
	m_urlWidegt = new FluImgWidget(this, FluentUiIconUtils::GetFluentIcon(FluAwesomeType::Link));

	m_vLayout->addWidget(m_iconWidget);
	m_vLayout->addWidget(m_titleLabel);
	m_vLayout->addWidget(m_contentLabel);


	m_titleLabel->setText(title);
	m_titleLabel->setWordWrap(true);
	m_contentLabel->setText(content);
	m_contentLabel->setWordWrap(true);
	m_iconWidget->setFixedSize(55, 55);
	m_urlWidegt->setFixedSize(16, 16);
	m_vLayout->setContentsMargins(15, 15, 15, 15);
	m_urlWidegt->setGeometry(170, 190, 16, 16);
	setStyleSheet("background-color:red;");
}

void FluLinkCardWidget::mouseReleaseEvent(QMouseEvent* event)
{
	QWidget::mouseReleaseEvent(event);
	QDesktopServices::openUrl(m_url);
}
