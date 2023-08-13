#include "FluMainWidget.h"
#include "FluLabel.h"
#include "FluLinkCardWidget.h"
#include "FluSampleCardView.h"
#include "FluSampleCard.h"
#include "FluHomeInterface.h"

FluMainWidget::FluMainWidget(QWidget* parent /*= nullptr*/, QWidget* centerWidget /*= nullptr*/) 
	: FluFrameLessWidgetV1(parent, centerWidget)
{
	// 设置水平布局
	m_hLayout = new QHBoxLayout();
	m_centerWidget->setLayout(m_hLayout);
	m_navigationInterface = new FluNavigationInterface(this, true, true);

	m_hLayout->addWidget(m_navigationInterface);
	m_rightVLayout = new QVBoxLayout(centerWidget);
	FluHomeInterface* homeInterFace = new FluHomeInterface(m_centerWidget);
	m_rightVLayout->addWidget(homeInterFace);

	m_hLayout->addLayout(m_rightVLayout);
}
