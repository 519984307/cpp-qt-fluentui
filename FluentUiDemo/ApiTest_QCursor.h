#pragma once

#include <QApplication>
#include "../FluentUiUtils/FluentUiLogUtils.h"
#include <QWidget>
#include <QMouseEvent>

class ApiTest_QCursor : public QWidget
{
public:
	ApiTest_QCursor(QWidget* parent = nullptr);

	void mousePressEvent(QMouseEvent* event);

//	void example();
};

