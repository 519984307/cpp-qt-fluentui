#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FLUENTUICONTROL_LIB)
#  define FLUENTUICONTROL_EXPORT Q_DECL_EXPORT
# else
#  define FLUENTUICONTROL_EXPORT Q_DECL_IMPORT
# endif
#else
# define FLUENTUICONTROL_EXPORT
#endif
