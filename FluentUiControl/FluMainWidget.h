#pragma once

#include "FluDef.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "FluFrameLessWidgetV1.h"
#include "FluNavigationInterface.h"
#include <QWidget>

class FluMainWidget : public FluFrameLessWidgetV1
{
	Q_OBJECT

public:
	FluMainWidget(QWidget* parent = nullptr, QWidget* centerWidget = nullptr);

	// 水平布局
	QHBoxLayout *m_hLayout;

	//QWidge* m_leftWidget;
	FluNavigationInterface* m_navigationInterface;
	QVBoxLayout* m_leftVLayout;

	QWidget* m_rightTopWidget;
	QWidget* m_rightBottomWidget;
	QVBoxLayout* m_rightVLayout;
};

