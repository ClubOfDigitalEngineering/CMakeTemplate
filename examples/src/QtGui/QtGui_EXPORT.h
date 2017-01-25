
#ifndef QtGui_EXPORT_H
#define QtGui_EXPORT_H

#ifdef QtGui_BUILT_AS_STATIC
#  define QtGui_EXPORT
#  define QTGUI_NO_EXPORT
#else
#  ifndef QtGui_EXPORT
#    ifdef QtGui_EXPORTS
        /* We are building this library */
#      define QtGui_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define QtGui_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef QTGUI_NO_EXPORT
#    define QTGUI_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef QTGUI_DEPRECATED
#  define QTGUI_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef QTGUI_DEPRECATED_EXPORT
#  define QTGUI_DEPRECATED_EXPORT QtGui_EXPORT QTGUI_DEPRECATED
#endif

#ifndef QTGUI_DEPRECATED_NO_EXPORT
#  define QTGUI_DEPRECATED_NO_EXPORT QTGUI_NO_EXPORT QTGUI_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define QTGUI_NO_DEPRECATED
#endif

#endif
