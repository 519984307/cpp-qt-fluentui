#pragma once

#include <QPixmap>
#include <QFont>
#include "../FluentUiControl/FluDef.h"

class FluentUiIconUtils
{
private:
	FluentUiIconUtils();
	~FluentUiIconUtils();

public:
	static FluentUiIconUtils* getInstance();
	static QPixmap GetFluentIcon(FluAwesomeType nType);
private:
	QFont m_fluentFont;
};

