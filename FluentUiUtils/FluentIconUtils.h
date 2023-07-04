#pragma once

#include <QPixmap>
#include <QFont>

class FluentIconUtils
{
private:
	FluentIconUtils();
	~FluentIconUtils();

public:
	static FluentIconUtils* getInstance();
	static QPixmap GetFluentIcon(int nIndex);
private:
	QFont m_fluentFont;
};

