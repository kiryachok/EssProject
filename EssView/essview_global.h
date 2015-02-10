#ifndef ESSVIEW_GLOBAL_H
#define ESSVIEW_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ESSVIEW_LIBRARY)
#  define ESSVIEWSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ESSVIEWSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ESSVIEW_GLOBAL_H
