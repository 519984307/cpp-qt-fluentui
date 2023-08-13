#pragma once

#include "FluDef.h"
#include "FluNavigationPanel.h"
#include <QFunctionPointer>

class FluNavigationInterface : public QWidget
{
	Q_OBJECT
public:
	FluNavigationInterface(QWidget* parent = nullptr, bool bShowMenuButton = true, bool bShowReturnButton = false)
		: QWidget(parent)
	{
		m_panel = new FluNavigationPanel(this);
		m_panel->setMenuButtonVisible(bShowMenuButton);
		m_panel->setReturnButtonVisible(bShowReturnButton);
	//	m_panel->resize(48, height());
		m_panel->resize(312, height());
		//m_panel->setMinimumWidth(312);
		m_panel->setAttribute(Qt::WA_StyledBackground);
		setFixedWidth(312);
	}
protected:
	void resizeEvent(QResizeEvent* event)
	{
		m_panel->setFixedHeight(height());
	}
public:
	
private:
	FluNavigationPanel* m_panel;
};

