#pragma once

#include <QWidget>
#include <QEnterEvent>
#include <QMouseEvent>
#include <QEvent>

class FluNavigationWidget : public QWidget
{
	Q_OBJECT
public:
	FluNavigationWidget(QWidget* parent = nullptr, bool bSelectable = true) : QWidget(parent)
	{
		m_bCompacted = true;
		m_bSelected = false;
		m_bPressed = false;
		m_bEnter = false;
		m_bSelectable = bSelectable;
		setFixedSize(40, 36);
	}
signals:
	void signalClicked(bool bClicked);
protected:
	void enterEvent(QEvent* event)
	{
		m_bEnter = true;
		update();
	}

	void leaveEvent(QEvent* event) override
	{
		m_bEnter = false;
		m_bPressed = false;
		update();
	}

	void mousePressEvent(QMouseEvent* event)
	{
		m_bPressed = true;
		update();
	}

	void mouseReleaseEvent(QMouseEvent* event)
	{
		m_bPressed = false;
		update();
		emit signalClicked(true);
	}

	void setCompacted(bool bCompacted)
	{
		if (m_bCompacted == bCompacted)
		{
			return;
		}

		m_bCompacted = bCompacted;
		if (m_bCompacted)
		{
			setFixedSize(40, 36);
		}
		else
		{
			setFixedSize(312, 36);
		}
		update();
	}

	bool getEnter()
	{
		return m_bEnter;
	}

	void setEnter(bool bEnter)
	{
		m_bEnter = bEnter;
	}

	bool getPressed()
	{
		return m_bPressed;
	}

	void setPressed(bool bPressed)
	{
		m_bPressed = bPressed;
	}

	bool getSelected()
	{
		return m_bSelected;
	}

	void setSelected(bool bSelected)
	{
		if (!m_bSelectable)
		{
			return;
		}

		if (m_bSelected == bSelected)
		{
			return;
		}

		m_bSelected = bSelected;
		update();
	}

	bool getCompacted()
	{
		return m_bCompacted;
	}

	//void setCompacted(bool bCompacted)
	//{
	//	m_bCompacted = bCompacted;
	//}
private:
	bool m_bCompacted;
	bool m_bSelected;
	bool m_bPressed;
	bool m_bEnter;
	bool m_bSelectable;
};

