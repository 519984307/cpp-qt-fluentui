#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FLUENTUIUTILS_LIB)
#  define FLUENTUIUTILS_EXPORT Q_DECL_EXPORT
# else
#  define FLUENTUIUTILS_EXPORT Q_DECL_IMPORT
# endif
#else
# define FLUENTUIUTILS_EXPORT
#endif
