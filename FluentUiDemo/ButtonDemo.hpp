#include "../FluentUiControl/FluTransparentToolButton.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"
#include <QWidget>

class ButtonDemo : public QWidget
{
	Q_OBJECT
public:
	ButtonDemo(QWidget* parent = nullptr) : QWidget(parent)
	{
		m_toolBtn = new FluTransparentToolButton(this, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::Bookmarks));
		//m_toolBtn->setGeometry(50, 50, 100, 20);
		setFixedSize(600, 400);
	}
private:
	FluTransparentToolButton* m_toolBtn;
};