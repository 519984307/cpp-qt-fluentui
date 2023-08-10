#include <QApplication>
#include <QWidget>
#include "ButtonDemo.hpp"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	//QWidget widget;
	//widget.show();

	ButtonDemo buttonDemo;
	buttonDemo.show();

	return app.exec();
}