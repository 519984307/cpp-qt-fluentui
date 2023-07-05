#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
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

	void resizeEvent(QResizeEvent* event) override;
public slots:
	void slotClickMinBtn();
	void slotClickCloseBtn();
	void slotClickMaxNorBtn();
private:
	QHBoxLayout* m_hLayout;
	QVBoxLayout* m_vLayout;

	QPushButton* m_minBtn;
	QPushButton* m_closeBtn;
	QPushButton* m_maxNorBtn;

	QPoint m_mouseLeftBtnPressPoint;
	bool m_bMouseLeftBtnPress;
};
