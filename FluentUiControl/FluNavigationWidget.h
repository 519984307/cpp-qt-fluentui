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
		m_treeParent = nullptr;
		m_nNodeDepth = 0;
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
		QWidget::mousePressEvent(event);
		m_bPressed = true;
		update();
	}

	void mouseReleaseEvent(QMouseEvent* event)
	{
		QWidget::mouseReleaseEvent(event);
		m_bPressed = false;
		update();
		emit signalClicked(true);
	}
public:
	void emitSignalClicked(bool bClicked)
	{
		emit signalClicked(bClicked);
	}
	void click()
	{
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

	bool getSelectable()
	{
		return m_bSelectable;
	}

	void setSelectable(bool bSelectable)
	{
		m_bSelectable = bSelectable;
	}

	bool isRoot()
	{
		return true;
	}

	bool isLeaf()
	{
		return true;
	}

	FluNavigationWidget* getTreeParent()
	{
		return m_treeParent;
	}

	void setTreeParent(FluNavigationWidget* treeParent)
	{
		m_treeParent = treeParent;
	}

	int getNodeDepth()
	{
		return m_nNodeDepth;
	}

	void setNodeDepth(int nNodeDepth)
	{
		m_nNodeDepth = nNodeDepth;
	}


private:
	bool m_bCompacted;
	bool m_bSelected;
	bool m_bPressed;
	bool m_bEnter;
	bool m_bSelectable;

	FluNavigationWidget* m_treeParent;
	int m_nNodeDepth;
};

