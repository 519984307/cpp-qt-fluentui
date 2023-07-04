#pragma once

#include <QWidget>
#include "FluentUiControlGlobal.h"

class FLUENTUICONTROL_EXPORT FluFrameLessWidget : public QWidget
{
	Q_OBJECT

public:
	FluFrameLessWidget(QWidget *parent = nullptr);
	virtual ~FluFrameLessWidget();
protected:
	void mouseMoveEvent(QMouseEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
private:
	QPoint m_mouseLeftBtnPressPoint;
	bool m_bMouseLeftBtnPress;
};
