#pragma once

#include <QString>
#include <QFile>

class FluentUiStyleSheetUitls
{
public:
	FluentUiStyleSheetUitls()
	{

	}

	static QString getQssByFileName(QString fileName)
	{
		QFile file(fileName);
		if (file.open(QIODevice::ReadOnly))
		{
			QString qssStr = file.readAll();
			file.close();
			return qssStr;
		}
		return "";
	}
};

