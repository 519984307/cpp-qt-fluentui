#pragma once

#include "FluentUiUtilsGlobal.h"
#include <QPixmap>

class FLUENTUIUTILS_EXPORT FluentUiUtils
{
public:
    FluentUiUtils();

    static QPixmap GetFluentIcon(int nIndex);
};
