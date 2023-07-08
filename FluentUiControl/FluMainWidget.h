#pragma once

#include "FluDef.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "FluFrameLessWidget.h"
#include <QWidget>

class FluMainWidget : public FluFrameLessWidget
{
	Q_OBJECT

public:
	FluMainWidget(QWidget* parent = nullptr, QWidget* centerWidget = nullptr);

	QHBoxLayout *m_hLayout;

	QWidget* m_leftWidget;
	QVBoxLayout* m_leftVLayout;

	QWidget* m_rightTopWidget;
	QWidget* m_rightBottomWidget;
	QVBoxLayout* m_rightVLayout;
};

