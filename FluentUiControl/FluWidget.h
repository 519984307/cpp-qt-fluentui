#pragma once

#include <QWidget>
#include "ui_FluWidget.h"

class FluWidget : public QWidget, public Ui::FluWidgetClass
{
	Q_OBJECT

public:
	FluWidget(QWidget *parent = nullptr);
	~FluWidget();

private:
	 
};
