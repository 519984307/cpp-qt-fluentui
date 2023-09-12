#include "../FluentUiControl/FluTransparentToolButton.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"
#include <QWidget>

class ButtonDemo : public QWidget
{
	Q_OBJECT
public:
	ButtonDemo(QWidget* parent = nullptr);
private:
	FluTransparentToolButton* m_toolBtn;
};