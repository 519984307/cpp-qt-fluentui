#include "FluHomeInterface.h"
#include <QStyleOption>
#include <QPainter>

FluHomeInterface::FluHomeInterface(QWidget* parent /*= nullptr*/) : QScrollArea(parent)
{
	m_view = new QWidget(this);
	m_bannerWidget = new FluBannerWidget(this);
	m_vLayout = new QVBoxLayout(m_view);

	// init
	m_view->setObjectName("view");

	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setWidgetResizable(true);

	m_vLayout->setContentsMargins(0, 0, 0, 36);
	m_vLayout->setSpacing(40);
	m_vLayout->addWidget(m_bannerWidget);
	m_vLayout->setAlignment(Qt::AlignTop);

	m_basicCardView = new FluSampleCardView(m_view, "Basic input samples");
	m_basicCardView->addSampleCard(QPixmap("../res/imgs/Button.png"), "Button", "A control that responds to user input and emit clicked signal.", "basicInputInterface", 0);
	m_basicCardView->addSampleCard(QPixmap("../res/imgs/CheckBox.png"), "CheckBox", "A control that a user can select or clear.", "basicInputInterface", 0);
	m_basicCardView->addSampleCard(QPixmap("../res/imgs/ComboBox.png"), "ComboBox", "A drop-down list of items a user can select from.", "basicInputInterface", 0);
	m_basicCardView->addSampleCard(QPixmap("../res/imgs/RadioButton.png"), "RadioButton", "A control that allows a user to select a single option from a group of options.", "basicInputInterface", 0);
	m_basicCardView->addSampleCard(QPixmap("../res/imgs/Slider.png"), "Slider", "A control that lets the user select from a range of values by moving a Thumb control along a track.", "basicInputInterface", 0);
	m_basicCardView->addSampleCard(QPixmap("../res/imgs/ToggleSwitch.png"), "SwitchButton", "A switch that can be toggled between 2 states.", "basicInputInterface", 0);
	m_vLayout->addWidget(m_basicCardView);

	m_view->setLayout(m_vLayout);

	setWidget(m_view);
	QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluHomeInterface.qss");
	setStyleSheet(qss);
}

void FluHomeInterface::paintEvent(QPaintEvent* event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
