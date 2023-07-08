#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "FluWidget.h"
#include "FluentUiControlGlobal.h"

class FLUENTUICONTROL_EXPORT FluFrameLessWidget : public QWidget
{
	Q_OBJECT
public:
	enum class BorderArea
	{
		BorderAreaNone = 0,
		BorderAreaTop,
		BorderAreaBottom,
		BorderAreaLeft,
		BorderAreaRight,
		BorderAreaTopLeft,
		BorderAreaTopRight,
		BorderAreaBottomLeft,
		BorderAreaBottomRight,
	};
public:
	FluFrameLessWidget(QWidget *parent = nullptr, QWidget* centerWidget = nullptr);
	virtual ~FluFrameLessWidget();

	void UpdateBorderArea(QPoint pos);
	void UpdateCursor();
	void UpdateWindowByBorderArea();

	void adjustWndSizeByMouseMove(QMouseEvent* event);

	QWidget* getCenterWidget()
	{
		return m_centerWidget;
	}

protected:
	void mouseMoveEvent(QMouseEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

	void resizeEvent(QResizeEvent* event) override;
public slots:
	void slotClickMinBtn();
	void slotClickCloseBtn();
	void slotClickMaxNorBtn();

protected:
	QHBoxLayout* m_hLayout;
	QVBoxLayout* m_vLayout;

	QWidget* m_centerWidget;
	QPushButton* m_minBtn;
	QPushButton* m_closeBtn;
	QPushButton* m_maxNorBtn;

	QPoint m_mouseLeftBtnPressPoint;
	BorderArea m_borderArea;
	bool m_bMouseLeftBtnPress;
};
