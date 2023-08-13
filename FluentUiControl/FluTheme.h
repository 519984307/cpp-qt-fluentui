#pragma once

#include <QObject>

class FluTheme : public QObject
{
private:
	static FluTheme* m_instance;
	FluTheme(QObject* parent = nullptr);
signals:
	void darkChanged(bool bDark);
public:
	static FluTheme* getInstance()
	{
		if (FluTheme::m_instance == nullptr)
		{
			FluTheme::m_instance = new FluTheme;
		}
		return FluTheme::m_instance;
	}

	bool getDark()
	{
		return m_bDark;
	}

	void setDark(bool bDark)
	{
		emit darkChanged(bDark);
		m_bDark = bDark;
	}
private:
	// 只有两种默认主题：黑色和白色
	bool m_bDark;
};

