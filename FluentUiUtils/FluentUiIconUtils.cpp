#include "../FluentUiControl/FluDef.h"
#include "FluentUiIconUtils.h"
#include <QFontDatabase>
#include <QPainter>

FluentUiIconUtils::FluentUiIconUtils()
{
	int fontId = QFontDatabase::addApplicationFont("../res/Segoe_Fluent_Icons.ttf");
	QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
	m_fluentFont.setFamily(fontFamilies.at(0));
}

FluentUiIconUtils::~FluentUiIconUtils()
{

}

FluentUiIconUtils* FluentUiIconUtils::getInstance()
{
	static FluentUiIconUtils utils;
	return &utils;
}

QPixmap FluentUiIconUtils::GetFluentIcon(FluAwesomeType nType)
{
	QFont tmpFont = getInstance()->m_fluentFont;

	QPixmap tmpPixMap(30, 30);
	tmpPixMap.fill(Qt::transparent);
	QPainter painter;
	painter.begin(&tmpPixMap);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	painter.setPen(QColor("black"));
	painter.setBrush(QColor("black"));
	tmpFont.setPointSize(15);
	painter.setFont(tmpFont);
	painter.drawText(tmpPixMap.rect(), Qt::AlignCenter, QChar((int)nType));
	painter.end();

	return tmpPixMap;
}
