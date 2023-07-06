#pragma once

#include <QHBoxLayout>
#include <QVBoxLayout>
#include "FluFrameLessWidget.h"


class FluMainWidget : public FluFrameLessWidget
{
public:
	FluMainWidget(QWidget* parent = nullptr, QWidget* centerWidget = nullptr);

	QHBoxLayout *m_hLayout;

	FluWidget* m_leftWidget;
	QVBoxLayout* m_leftVLayout;

	FluWidget* m_rightTopWidget;
	FluWidget* m_rightBottomWidget;
	QVBoxLayout* m_rightVLayout;
};

