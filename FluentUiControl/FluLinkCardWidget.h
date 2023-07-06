#pragma once

#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QUrl>
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include "FluImgWidget.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"

class FluLinkCardWidget : public QWidget
{
public:
	FluLinkCardWidget(QWidget* parent = nullptr, QPixmap img = QPixmap(), QString title = "", QString content = "", QString url= "" );
protected:
	void mouseReleaseEvent(QMouseEvent* event) override;
private:
	QVBoxLayout *m_vLayout;
	FluImgWidget* m_iconWidget;
	QLabel* m_titleLabel;
	QLabel* m_contentLabel;
	FluImgWidget* m_urlWidegt;
	QUrl m_url;
};

