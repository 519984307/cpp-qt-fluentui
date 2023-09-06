#pragma once

#include "FluNavigationPushButton.h"

class FluNavigationToolButton : public FluNavigationPushButton
{
	Q_OBJECT
public:
	FluNavigationToolButton(QWidget* parent, QPixmap icon)
		: FluNavigationPushButton(parent, icon, "", false)
	{
		//setFixedSize(40, 40);
	}

	void setCompacted(bool bCompacted)
	{
		setFixedSize(40, 36);
	}
};

