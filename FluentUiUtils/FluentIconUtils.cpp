#include "FluentIconUtils.h"
#include <QFontDatabase>
#include <QPainter>

FluentIconUtils::FluentIconUtils()
{
	int fontId = QFontDatabase::addApplicationFont("./Segoe_Fluent_Icons.ttf");
	QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
	m_fluentFont.setFamily(fontFamilies.at(0));
}

FluentIconUtils::~FluentIconUtils()
{

}

FluentIconUtils* FluentIconUtils::getInstance()
{
	static FluentIconUtils utils;
	return &utils;
}

QPixmap FluentIconUtils::GetFluentIcon(int nIndex)
{
	QFont tmpFont = getInstance()->m_fluentFont;

	QPixmap tmpPixMap(30, 30);
	tmpPixMap.fill(Qt::transparent);
	QPainter painter;
	painter.begin(&tmpPixMap);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	painter.setPen(QColor("black"));
	painter.setBrush(QColor("black"));
	tmpFont.setPointSize(10);
	painter.setFont(tmpFont);
	painter.drawText(tmpPixMap.rect(), Qt::AlignCenter, QChar(nIndex));
	painter.end();

	return tmpPixMap;
}
