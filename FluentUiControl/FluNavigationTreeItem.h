#pragma once

#include "FluNavigationPushButton.h"
#include <QPropertyAnimation>
class FluNavigationTreeItem : public FluNavigationPushButton
{
	Q_OBJECT
public:
	FluNavigationTreeItem(QWidget* parent, QPixmap icon, QString text, bool bSelectable)
		: FluNavigationPushButton(parent, icon, text, bSelectable)
	{
		m_nArrowAngle = 0;
		m_rotateAni = new QPropertyAnimation(this, "arrowAngle", this);
	}

	void setExpanded(bool bExpanded)
	{
		m_rotateAni->stop();
		if (!bExpanded)
		{
			m_rotateAni->setEndValue(180);
			m_rotateAni->setDuration(150);
			m_rotateAni->start();
		}

		if (bExpanded)
		{
			m_rotateAni->setEndValue(180);
			m_rotateAni->setDuration(150);
			m_rotateAni->start();
		}
	}
signals:
	void signalItemClicked(bool bTrigger, bool bClickArrow);
protected:
	void mouseReleaseEvent(QMouseEvent* event)
	{
		FluNavigationPushButton::mouseReleaseEvent(event);
		
		//判断是否点击了"箭头"
		QRect tmpArrowRect = QRect(width() - 30, 8, 20, 20);
		bool bClickArrow = tmpArrowRect.contains(event->pos());

		FluNavigationWidget* parentWidget = dynamic_cast<FluNavigationWidget*>(parent());
		emit signalItemClicked(true, bClickArrow && !parentWidget->isLeaf());
		update();
	}

     bool _canDrawIndicator()
	{
		FluNavigationWidget* parentWidget = dynamic_cast<FluNavigationWidget*>(parent());
		if (parentWidget->isLeaf() || parentWidget->getSelected())
			return parentWidget->getSelected();
	}
private:
	QPropertyAnimation* m_rotateAni;
	// 箭头旋转角度
	int m_nArrowAngle;
};

