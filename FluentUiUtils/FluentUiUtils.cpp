#include "FluentUiUtils.h"
#include <QFontDatabase>
#include <QPainter>

FluentUiUtils::FluentUiUtils()
{
}

QPixmap FluentUiUtils::GetFluentIcon(int nIndex)
{
	int fontId = QFontDatabase::addApplicationFont("./Segoe_Fluent_Icons.ttf");
	QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
	QFont fluentFont;
	fluentFont.setFamily(fontFamilies.at(0));

	QPixmap tmpPixMap(30, 30);
	tmpPixMap.fill(Qt::transparent);
	QPainter painter;
	painter.begin(&tmpPixMap);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	painter.setPen(QColor("black"));
	painter.setBrush(QColor("black"));
	fluentFont.setPointSize(10);
	painter.setFont(fluentFont);
	painter.drawText(tmpPixMap.rect(), Qt::AlignCenter, QChar(nIndex));
	painter.end();
	return tmpPixMap;
}
