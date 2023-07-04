#pragma once

#include <QWidget>
#include "ui_FrameLessWidget.h"

class FluFrameLessWidget : public QWidget, public Ui::FrameLessWidgetClass
{
	Q_OBJECT

public:
	FluFrameLessWidget(QWidget *parent = nullptr);
	virtual ~FluFrameLessWidget();

private:
	 
};
