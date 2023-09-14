#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include "../FluentUiControl/FluButton.h"
#include "../FluentUiControl/FluToolTip.h"

class FluToolTipDemo : public QWidget
{
	Q_OBJECT
public:
	FluToolTipDemo(QWidget* parent = nullptr) : QWidget(parent)
	{
		m_hBoxLayout = new QHBoxLayout(this);
		setLayout(m_hBoxLayout);

		m_button1 = new FluPushButton("闪闪发光");
		m_button2 = new FluPushButton("吃过的爱", this);
		m_button3 = new FluPushButton("唾液", this);

		m_button1->setToolTipDuration(1000);

		m_button1->setToolTip("aiko - 闪闪发光✨");
		m_button2->setToolTip("aiko - 吃过的爱🥰");
		m_button3->setToolTip("aiko - 唾液😊");


		m_button1->installEventFilter(new FluToolTipFilter(m_button1, 0, FluToolTipPositon::TOP));
		m_button2->installEventFilter(new FluToolTipFilter(m_button2, 0, FluToolTipPositon::BOTTOM));
		m_button3->installEventFilter(new FluToolTipFilter(m_button3, 0, FluToolTipPositon::LEFT));

		m_hBoxLayout->setContentsMargins(24, 24, 24, 24);
		m_hBoxLayout->setSpacing(16);

		m_hBoxLayout->addWidget(m_button1);
		m_hBoxLayout->addWidget(m_button2);
		m_hBoxLayout->addWidget(m_button3);

		resize(480, 240);
		
		setStyleSheet("FluToolTipDemo{background:white;}");
	}
private:
	QHBoxLayout* m_hBoxLayout;
	FluPushButton* m_button1;
	FluPushButton* m_button2;
	FluPushButton* m_button3;
};

