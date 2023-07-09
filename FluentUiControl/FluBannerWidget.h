#pragma once

#include "FluDef.h"
#include "FluLinkCardView.h"
#include <QLabel>

class FluBannerWidget : public QWidget
{
	Q_OBJECT
	FluSetPropertyP(QVBoxLayout, vLayout);
	FluSetPropertyP(QLabel, galleryLabel);
	FluSetPropertyP(FluLinkCardView, linkCardView);
	FluSetPropertyN(QPixmap, img);
public:
	FluBannerWidget(QWidget* parent = nullptr);
protected:
	void paintEvent(QPaintEvent* event) override;
};

