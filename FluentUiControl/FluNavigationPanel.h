#pragma once

#include "FluDef.h"
#include <QWidget>
#include <QScrollArea>
#include <QPropertyAnimation>
#include "FluNavigationPushButton.h"
#include "FluNavigationItemLayout.h"
#include "FluNavigationHistory.h"
#include "FluNavigationToolButton.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"


enum class FluNavigationDisplayMode
{
	MINIMAL = 0,
	COMPACT = 1,
	EXPAND = 2,
	MENU = 3
};

enum class FluNavigationItemPosition
{
	TOP = 0,
	SCROLL,
	BOTTOM
};

using FluNavigationWidgetClickedCallBack = void (*)();

class FluNavigationPanel : public QWidget
{
	Q_OBJECT
public:
	FluNavigationPanel(QWidget* parent = nullptr, bool bMinimalEnable = false)
		: QWidget(parent)
	{
		__initWidget(parent, bMinimalEnable);
		__initLayout();
		__connect();
	}

	void __initWidget(QWidget* parent, bool bMinimalEnable)
	{
		m_parent = parent;
		m_bMenuButtonVisible = true;
		m_bReturnButtonVisible = false;

		m_scrollArea = new QScrollArea(this);
		m_scrollWidget = new QWidget();

		m_menuButton = new FluNavigationToolButton(this, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::GlobalNavButton));
		m_menuButton = new FluNavigationToolButton(this, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::Back));

		m_vLayout = new FluNavigationItemLayout(this);
		m_vTopLayout = new FluNavigationItemLayout();
		m_vBottomLayout = new FluNavigationItemLayout();
		m_vScrollLayout = new FluNavigationItemLayout(m_scrollWidget);

		m_expandAnimation = new QPropertyAnimation(this, "geometry", this);
		m_expandWidth = 322;

		m_bMinimalEnabled = bMinimalEnable;
		if (bMinimalEnable)
			m_displayMode = FluNavigationDisplayMode::MINIMAL;
		else
			m_displayMode = FluNavigationDisplayMode::COMPACT;

		resize(48, height());
		setAttribute(Qt::WA_StyledBackground);
		window()->installEventFilter(this);

		m_returnButton->hide();
		m_returnButton->setDisabled(true);

		m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		m_scrollArea->setWidget(m_scrollWidget);
		m_scrollArea->setWidgetResizable(true);

		m_expandAnimation->setEasingCurve(QEasingCurve::OutQuad);
		m_expandAnimation->setDuration(150);

		setProperty("menu", false);
		m_scrollWidget->setObjectName("scrollWidget");
	}

	void __connect()
	{

	}

	void __initLayout()
	{
		m_vLayout->setContentsMargins(0, 5, 0, 5);
		m_vTopLayout->setContentsMargins(4, 0, 4, 0);
		m_vBottomLayout->setContentsMargins(4, 0, 4, 0);
		m_vScrollLayout->setContentsMargins(4, 0, 4, 0);

		m_vLayout->setSpacing(4);
		m_vTopLayout->setSpacing(4);
		m_vScrollLayout->setSpacing(4);
		m_vBottomLayout->setSpacing(4);

		m_vLayout->addLayout(m_vTopLayout);
		m_vLayout->addLayout(m_vScrollLayout, 1);
		m_vLayout->addLayout(m_vBottomLayout);

		m_vLayout->setAlignment(Qt::AlignTop);
		m_vTopLayout->setAlignment(Qt::AlignTop);
		m_vScrollLayout->setAlignment(Qt::AlignTop);
		m_vBottomLayout->setAlignment(Qt::AlignBottom);
	}

	void addWidget(QString routeKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack callback, FluNavigationItemPosition position = FluNavigationItemPosition::TOP)
	{
		auto itf = m_items.find(routeKey);
		if (itf != m_items.end())
		{
			return;
		}

		widget->setProperty("routeKey", routeKey);
		m_items[routeKey] = widget;

		if (m_displayMode == FluNavigationDisplayMode::EXPAND || m_displayMode == FluNavigationDisplayMode::MENU)
		{
			widget->setCompacted(false);
		}

		addWidgetToLayout(widget, position);
	}

	void addWidgetToLayout(FluNavigationWidget* widget, FluNavigationItemPosition postion)
	{
		switch (postion)
		{
		case FluNavigationItemPosition::TOP:
			widget->setParent(this);
			m_vTopLayout->addWidget(widget, 0, Qt::AlignTop);
			break;
		case FluNavigationItemPosition::SCROLL:
			widget->setParent(m_scrollWidget);
			m_vScrollLayout->addWidget(widget, 0, Qt::AlignTop);
			break;
		case FluNavigationItemPosition::BOTTOM:
			widget->setParent(this);
			m_vBottomLayout->addWidget(widget, 0, Qt::AlignBottom);
			break;
		default:
			break;
		}

		widget->show();
	}

	void addItem(QString routeKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack callback, FluNavigationItemPosition position = FluNavigationItemPosition::TOP)
	{

	}

	void removeWidget(QString routeKey)
	{
		auto itf = m_items.find(routeKey);
		if (itf == m_items.end())
		{
			return;
		}

		FluNavigationWidget* widget = m_items[routeKey];
		m_items.remove(routeKey);
		widget->deleteLater();
		m_history->remove(routeKey, true);
	}

	void setMenuButtonVisible(bool bVisible)
	{
		m_bMenuButtonVisible = bVisible;
		m_menuButton->setVisible(bVisible);
	}

	void setReturnButtonVisible(bool bVisible)
	{
		m_bReturnButtonVisible = bVisible;
		m_returnButton->setVisible(bVisible);
	}

	void setExpandWidth(int width)
	{
		if (width <= 42)
		{
			return;
		}

		m_expandWidth = width;
		//
	}

	void expand()
	{

	}
	
private:
	QWidget* m_parent;
	bool m_bMenuButtonVisible;
	bool m_bReturnButtonVisible;
	QScrollArea* m_scrollArea;
	QWidget* m_scrollWidget;

	FluNavigationToolButton* m_menuButton;
	FluNavigationToolButton* m_returnButton;

	FluNavigationItemLayout* m_vLayout;
	FluNavigationItemLayout* m_vTopLayout;
	FluNavigationItemLayout* m_vBottomLayout;
	FluNavigationItemLayout* m_vScrollLayout;

	QMap<QString, FluNavigationWidget*> m_items;
	FluNavigationHistory* m_history;

	QPropertyAnimation* m_expandAnimation;
	int m_expandWidth;


	bool m_bMinimalEnabled;
	FluNavigationDisplayMode m_displayMode;
};

