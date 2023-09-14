#pragma once

#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <QLabel>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include <QApplication>
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"
#include <QCursor>
#include <QScreen>
#include <QApplication>
#include <QTimer>


class FluToolTipPositionManager;
class FluTopToolTipManager;
class FluBottomToolTipManager;
class FluLeftToolTipManager;
class FluRightToolTipManager;

class FluTopLeftToolTipManager;
class FluBottomLeftToolTipManager;
class FluTopRightToolTipManager;
class FluBottomRightToolTipManager;

enum class FluToolTipPositon
{
	TOP,
	BOTTOM,
	LEFT,
	RIGHT,
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT,
};

class FluToolTip : public QFrame
{
public:
	FluToolTip(QWidget* parent = nullptr, QString text = "");

	void __setQss();

	QString text();

	void setText(const QString& text);

	int duration();

	void setDuration(int duration);

	void showEvent(QShowEvent* event);

	void hideEvent(QHideEvent* event);

	void adjustPos(QWidget* widget, FluToolTipPositon position);
private:
	QFrame* m_container;
	QTimer* m_timer;
	QLabel* m_label;

	// 窗口总布局
	QHBoxLayout* m_hMainLayout;
	QHBoxLayout* m_hContainerLayout;

	QPropertyAnimation* m_opcityAni;
	QGraphicsDropShadowEffect* m_shadowEffect;

	QString m_text;
	int m_duration;
};

class FluToolTipPositionManager
{
public:
	QPoint position(FluToolTip* toolTip, QWidget* parent);

	virtual QPoint _pos(FluToolTip* toolTip, QWidget* parent);

	static FluToolTipPositionManager* make(FluToolTipPositon position);

private:
	static QMap<FluToolTipPositon, FluToolTipPositionManager*> m_manages;
};

class FluTopToolTipManager : public FluToolTipPositionManager
{
public:
	QPoint _pos(FluToolTip* toolTip, QWidget* parent);
};

class FluBottomToolTipManager : public FluToolTipPositionManager
{
public:
	QPoint _pos(FluToolTip* toolTip, QWidget* parent);
};

class FluLeftToolTipManager : public FluToolTipPositionManager
{
public:
	QPoint _pos(FluToolTip* toolTip, QWidget* parent);
};

class FluRightToolTipManager : public FluToolTipPositionManager
{
public:
	QPoint _pos(FluToolTip* toolTip, QWidget* parent);
};

class FluTopLeftToolTipManager : public FluToolTipPositionManager
{
public:
	QPoint _pos(FluToolTip* toolTip, QWidget* parent);
};

class FluTopRightToolTipManager : public FluToolTipPositionManager
{
public:
	QPoint _pos(FluToolTip* toolTip, QWidget* parent);
};

class FluBottomLeftToolTipManager : public FluToolTipPositionManager
{
public:
	QPoint _pos(FluToolTip* toolTip, QWidget* parent);
};

class FluBottomRightToolTipManager : public FluToolTipPositionManager
{
public:
	QPoint _pos(FluToolTip* toolTip, QWidget* parent);
};

class FluToolTipFilter : public QObject
{
public:
	FluToolTipFilter(QWidget* parent = nullptr, int showDelay = 300, FluToolTipPositon position = FluToolTipPositon::TOP);

	bool eventFilter(QObject* object, QEvent* event);

	void hideToolTip();

	void showToolTip();

	void setToolTipDelay(int delay);

	bool _canShowToolTip();
private:
	FluToolTip* m_toolTip;
	FluToolTipPositon m_position;
	QTimer* m_timer;
	int m_toolTipDelay;
	bool m_isEnter;
};


