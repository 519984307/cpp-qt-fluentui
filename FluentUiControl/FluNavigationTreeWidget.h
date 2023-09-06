#pragma once

#include "FluNavigationBaseTreeWidget.h"
#include "FluNavigationTreeItem.h"
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <algorithm>

class FluNavigationTreeWidget : public FluNavigationBaseTreeWidget
{
	Q_OBJECT
public:
	FluNavigationTreeWidget(QWidget* parent, QPixmap icon, QString text, bool bSelectable)
		: FluNavigationBaseTreeWidget(parent, bSelectable)
	{
		m_bExpanded = false;
		m_itemWidget = new FluNavigationTreeItem(parent, icon, text, bSelectable);
		m_vLayout = new QVBoxLayout(this);

		m_expandAni = new QPropertyAnimation(this, "geometry", this);
	}

	void __initWidget()
	{
		m_vLayout->setSpacing(4);
		m_vLayout->setContentsMargins(0, 0, 0, 0);
		m_vLayout->addWidget(m_itemWidget, 0, Qt::AlignTop);

		connect(m_itemWidget, &FluNavigationTreeItem::signalItemClicked, this, &FluNavigationTreeWidget::_onClicked);

		// 设置窗口透明
		setAttribute(Qt::WA_TranslucentBackground);
		connect(m_expandAni, &QPropertyAnimation::valueChanged, this, &FluNavigationTreeWidget::_onSize);
	}

	void addChild()
	{

	}

	QString getText()
	{
		return m_itemWidget->getText();
	}

	QPixmap getIcon()
	{
		return m_itemWidget->getIcon();
	}

	void setText(QString text)
	{
		m_itemWidget->setText(text);
	}

	void setIcon(QPixmap icon)
	{
		m_itemWidget->setIcon(icon);
	}

	void setFont(QFont font)
	{
		QWidget* pParentWidget = dynamic_cast<QWidget*>(parent());
		pParentWidget->setFont(font);
		m_itemWidget->setFont(font);
	}


	void insertChild(int index, FluNavigationWidget* child)
	{
		auto itf = std::find(m_treeChildren.begin(), m_treeChildren.end(), child);
		if (itf != m_treeChildren.end())
			return;

		child->setTreeParent(this);
		child->setNodeDepth(getNodeDepth() + 1);
		child->setVisible(m_bExpanded);

		connect(m_expandAni, &QPropertyAnimation::valueChanged, this, &FluNavigationTreeWidget::_onSize);

		if (index <= 0)
			index = m_treeChildren.size();

		m_treeChildren.insert(index + m_treeChildren.begin(), (FluNavigationTreeWidget*)child);
		m_vLayout->insertWidget(index, child, 0, Qt::AlignTop);
	}

	void removeChild(FluNavigationWidget* child)
	{
		
	}

public slots:
	void _onClicked(bool triggerByUser, bool clickArrow)
	{
		if (!getCompacted())
		{
			if (getSelectable() && !getSelected() && !clickArrow)
			{
			}
		}
	}

	void _onSize(QVariant size)
	{
		QSize tmpSize = size.toSize();
		this->setFixedSize(tmpSize);
	}
private:
	QPropertyAnimation* m_expandAni;
	QVector<FluNavigationTreeWidget*> m_treeChildren;
	FluNavigationTreeItem* m_itemWidget;
	QVBoxLayout* m_vLayout;
	bool m_bExpanded;
};

