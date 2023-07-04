#pragma once

#include <QWidget>
#include "ui_Label.h"

class FluLabel : public QWidget, public Ui::LabelClass
{
	Q_OBJECT

public:
	FluLabel(QWidget *parent = nullptr);
	~FluLabel();

private:
	 
};
