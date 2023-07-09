#include "FluMainWidget.h"
#include "FluLabel.h"
#include "FluLinkCardWidget.h"
#include "FluSampleCardView.h"
#include "FluSampleCard.h"
#include "FluHomeInterface.h"

FluMainWidget::FluMainWidget(QWidget* parent /*= nullptr*/, QWidget* centerWidget /*= nullptr*/) 
	: FluFrameLessWidget(parent, centerWidget)
{
	m_hLayout = new QHBoxLayout();
	m_centerWidget->setLayout(m_hLayout);

	m_leftVLayout = new QVBoxLayout();
	m_leftWidget = new QWidget(centerWidget);
	m_leftWidget->setFixedWidth(280);

	m_leftVLayout->addWidget(m_leftWidget);
	m_leftWidget->setStyleSheet("background-color:pink;");
	m_hLayout->addLayout(m_leftVLayout);


	m_rightVLayout = new QVBoxLayout(centerWidget);


//	m_rightTopWidget = new FluImgWidget(centerWidget, QPixmap("../res/bg_home_header.png"));
//	//m_rightTopWidget->setStyleSheet("background-color:green;");
//
//	FluLabel* m_titleLable = new FluLabel(m_rightTopWidget);
//	m_titleLable->setText("FluentUI Gallery");
//	m_titleLable->setStyleSheet(" font: 30px 'Segoe UI', 'Microsoft YaHei';");
//
//	FluLinkCardWidget* linkCardWidget = new FluLinkCardWidget(m_rightTopWidget, 
//		QPixmap("../res/ic_home_github.png"), "FluentUI GitHub", 
//		"The latest FluentUI controls and styles for your applications.",
//		"https://github.com/mowangshuying/CppQtFluentUI");
//
//	linkCardWidget->move(20, 80);
//
//	m_rightVLayout->addWidget(m_rightTopWidget);
////	m_rightTopWidget->setBackgrondImg(QPixmap("../res/bg_home_header.png"));
//	m_rightTopWidget->setFixedHeight(320);
//
//	m_rightBottomWidget = new QWidget(centerWidget);
//	//m_rightBottomWidget->setStyleSheet("background-color:pink;");
//	QVBoxLayout* m_tmpVLayout = new QVBoxLayout();
//	m_rightBottomWidget->setLayout(m_tmpVLayout);
//
//	FluSampleCardView* m_basicCardView = new FluSampleCardView(m_rightBottomWidget, "Basic input samples");
//	m_basicCardView->addSampleCard(QPixmap("../res/imgs/Button.png"), "Button", "A control that responds to user input and emit clicked signal.", "basicInputInterface", 0);
//	m_basicCardView->addSampleCard(QPixmap("../res/imgs/CheckBox.png"), "CheckBox", "A control that a user can select or clear.", "basicInputInterface", 0);
//	m_basicCardView->addSampleCard(QPixmap("../res/imgs/ComboBox.png"), "ComboBox", "A drop-down list of items a user can select from.", "basicInputInterface", 0);
//	m_basicCardView->addSampleCard(QPixmap("../res/imgs/RadioButton.png"),"RadioButton","A control that allows a user to select a single option from a group of options.","basicInputInterface",0);
//	m_basicCardView->addSampleCard(QPixmap("../res/imgs/Slider.png"),"Slider","A control that lets the user select from a range of values by moving a Thumb control along a track.","basicInputInterface",0);
//	m_basicCardView->addSampleCard(QPixmap("../res/imgs/ToggleSwitch.png"),"SwitchButton","A switch that can be toggled between 2 states.","basicInputInterface",0);
//	m_tmpVLayout->addWidget(m_basicCardView);
//
//	m_rightVLayout->addWidget(m_rightBottomWidget);

	FluHomeInterface* homeInterFace = new FluHomeInterface(m_centerWidget);
	m_rightVLayout->addWidget(homeInterFace);


	m_hLayout->addLayout(m_rightVLayout);
}
