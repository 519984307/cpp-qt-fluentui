#pragma once

#include <QObject>
#include "FluNavigationWidget.h"


class FluNavigationHistory : public QObject
{
public:
	FluNavigationHistory(QObject* parent = nullptr) : QObject(parent)
	{

	}
signals:
	void signalEmptyChanged(bool bEmpty);
public:
	QString getDefaultRouteKey()
	{
		return m_defalutRouteKey;
	}

	void setDefaultRouteKey(QString defalutRouteKey)
	{
		m_defalutRouteKey = defalutRouteKey;
	}

	void push(QString routeKey)
	{
		if (m_history.isEmpty() && m_defalutRouteKey != routeKey)
		{
			m_history.append(routeKey);
			emit signalEmptyChanged(false);
			return;
		}

		if (!m_history.isEmpty() && m_history.back() != routeKey)
		{
			m_history.push_back(routeKey);
		}
	}

	void pop()
	{
		if (m_history.isEmpty())
			return;

		m_history.pop_back();
		navigate();
	}

	void remove(QString routeKey, bool all = false)
	{
		if (!m_history.contains(routeKey))
			return;

		for (auto itBeg = m_history.begin(); itBeg != m_history.end(); )
		{
			if ((*itBeg) == routeKey)
			{
				m_history.erase(itBeg);
				if (!all)
					return;

				continue;
			}

			itBeg++;
		}

		navigate();
	}

	void navigate()
	{
		if (!m_history.isEmpty())
		{
			m_items[m_history.back()]->emitSignalClicked(false);
			return;
		}

		if (m_history.isEmpty())
		{
			if (!m_defalutRouteKey.isEmpty())
				m_items[m_defalutRouteKey]->emitSignalClicked(false);
			emit signalEmptyChanged(true);
		}
	}


private:
	QVector<QString> m_history;
	QString m_defalutRouteKey;
	QMap<QString, FluNavigationWidget*> m_items;
};

