#include "FluMainWidget.h"
#include "FluLabel.h"


FluMainWidget::FluMainWidget(QWidget* parent /*= nullptr*/, QWidget* centerWidget /*= nullptr*/) 
	: FluFrameLessWidget(parent, centerWidget)
{
	m_hLayout = new QHBoxLayout(m_centerWidget);

	m_leftVLayout = new QVBoxLayout(centerWidget);
	m_leftWidget = new FluWidget(centerWidget);
	m_leftWidget->setFixedWidth(280);

	m_leftVLayout->addWidget(m_leftWidget);
	m_leftWidget->setStyleSheet("background-color:pink;");
	m_hLayout->addLayout(m_leftVLayout);


	m_rightVLayout = new QVBoxLayout(centerWidget);


	m_rightTopWidget = new FluWidget(centerWidget);
	//m_rightTopWidget->setStyleSheet("background-color:green;");

	FluLabel* m_titleLable = new FluLabel(m_rightTopWidget);
	m_titleLable->setText("FluentUI Gallery");
	m_titleLable->setStyleSheet(" font: 30px 'Segoe UI', 'Microsoft YaHei';");

	m_rightVLayout->addWidget(m_rightTopWidget);
	m_rightTopWidget->setBackgrondImg(QPixmap("../res/bg_home_header.png"));
	m_rightTopWidget->setFixedHeight(320);

	m_rightBottomWidget = new FluWidget(centerWidget);
	m_rightBottomWidget->setStyleSheet("background-color:blue;");
	m_rightVLayout->addWidget(m_rightBottomWidget);

	m_hLayout->addLayout(m_rightVLayout);
}
