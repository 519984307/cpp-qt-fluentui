#include "FluFrameLessWidget.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"
#include <QMouseEvent>

FluFrameLessWidget::FluFrameLessWidget(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
	m_bMouseLeftBtnPress = false;
	m_mouseLeftBtnPressPoint = QPoint(0, 0);

	m_vLayout = new QVBoxLayout(this);
	setLayout(m_vLayout);

	m_hLayout = new QHBoxLayout(this);
	
	m_hLayout->addStretch(1);
	m_minBtn = new QPushButton(this);
	m_minBtn->setFixedSize(30, 30);
	m_minBtn->setIcon(QIcon(FluentUiIconUtils::GetFluentIcon((int)FluentUiIconUtils::AwesomeType::ChromeMinimize)));
	m_hLayout->addWidget(m_minBtn);

	m_maxNorBtn = new QPushButton(this);
	m_maxNorBtn->setFixedSize(30, 30);
	m_hLayout->addWidget(m_maxNorBtn);

	m_closeBtn = new QPushButton(this);
	m_closeBtn->setFixedSize(30, 30);
	m_hLayout->addWidget(m_closeBtn);

	m_vLayout->addLayout(m_hLayout, 0);
	m_vLayout->addStretch(1);

	setMinimumSize(800, 600);
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
