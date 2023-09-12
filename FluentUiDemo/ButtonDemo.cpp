#include "ButtonDemo.h"

ButtonDemo::ButtonDemo(QWidget* parent /*= nullptr*/) : QWidget(parent)
{
	m_toolBtn = new FluTransparentToolButton(this, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::Bookmarks));
	//m_toolBtn->setGeometry(50, 50, 100, 20);
	setFixedSize(600, 400);
}

