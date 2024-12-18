#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MyPlugin_EXPORTS)
#  define MYPLUGINLIB_EXPORT Q_DECL_EXPORT
# else
#  define MYPLUGINLIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define MYPLUGINLIB_EXPORT
#endif
