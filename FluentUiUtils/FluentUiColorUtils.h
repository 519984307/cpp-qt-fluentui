#pragma once

#include <QColor>
#include <QObject>
#include <QString>

#include "FluentUiColorSet.h"

class FluentUiColorUtils
{
public:
	QString Black;
	QString White;
	QString Grey10;
	QString Grey20;
	QString Grey30;
	QString Grey40;
	QString Grey50;
	QString Grey60;
	QString Grey70;
	QString Grey80;
	QString Grey90;
	QString Grey100;
	QString Grey110;
	QString Grey120;
	QString Grey130;
	QString Grey140;
	QString Grey150;
	QString Grey160;
	QString Grey170;
	QString Grey180;
	QString Grey190;
	QString Grey200;
	QString Grey210;
	QString Grey220;

	FluentUiColorSet Yellow;
	FluentUiColorSet Orange;
	FluentUiColorSet Red;
	FluentUiColorSet Magenta;
	FluentUiColorSet Purple;
	FluentUiColorSet Blue;
	FluentUiColorSet Teal;
	FluentUiColorSet Green;
private:
	FluentUiColorUtils();
public:
	static FluentUiColorUtils* getInstance()
	{
		FluentUiColorUtils utils;
		return &utils;
	}
};

