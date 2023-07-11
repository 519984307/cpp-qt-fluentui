#include "FluMainWidget.h"
#include "FluLabel.h"
#include "FluLinkCardWidget.h"
#include "FluSampleCardView.h"
#include "FluSampleCard.h"
#include "FluHomeInterface.h"

FluMainWidget::FluMainWidget(QWidget* parent /*= nullptr*/, QWidget* centerWidget /*= nullptr*/) 
	: FluFrameLessWidgetV1(parent, centerWidget)
{
	m_hLayout = new QHBoxLayout();
	m_centerWidget->setLayout(m_hLayout);

	m_leftVLayout = new QVBoxLayout();
	m_leftWidget = new QWidget(centerWidget);
	m_leftWidget->setFixedWidth(280);

	m_leftVLayout->addWidget(m_leftWidget);
	//m_leftWidget->setStyleSheet("background-color:pink;");
	m_hLayout->addLayout(m_leftVLayout);


	m_rightVLayout = new QVBoxLayout(centerWidget);
	FluHomeInterface* homeInterFace = new FluHomeInterface(m_centerWidget);
	m_rightVLayout->addWidget(homeInterFace);


	m_hLayout->addLayout(m_rightVLayout);
}
