#include "ApiTest_QCursor.h"
#include <QApplication>
#include <QCursor>


ApiTest_QCursor::ApiTest_QCursor(QWidget* parent /*= nullptr*/) : QWidget(parent)
{

}

void ApiTest_QCursor::mousePressEvent(QMouseEvent* event)
{
	LogDebug << QCursor::pos();
	QScreen *screen = QApplication::screenAt(QCursor::pos()); // 获取到在哪个屏幕
	LogDebug << screen->availableGeometry();  // 打印屏幕信息
}

//void ApiTest_QCursor::example()
//{
//	LogDebug << QCursor::pos();
//}
