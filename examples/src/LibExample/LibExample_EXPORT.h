
#ifndef LibExample_EXPORT_H
#define LibExample_EXPORT_H

#ifdef LibExample_BUILT_AS_STATIC
#  define LibExample_EXPORT
#  define LIBEXAMPLE_NO_EXPORT
#else
#  ifndef LibExample_EXPORT
#    ifdef LibExample_EXPORTS
        /* We are building this library */
#      define LibExample_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define LibExample_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef LIBEXAMPLE_NO_EXPORT
#    define LIBEXAMPLE_NO_EXPORT 
#  endif
#endif

#ifndef LIBEXAMPLE_DEPRECATED
#  define LIBEXAMPLE_DEPRECATED __declspec(deprecated)
#endif

#ifndef LIBEXAMPLE_DEPRECATED_EXPORT
#  define LIBEXAMPLE_DEPRECATED_EXPORT LibExample_EXPORT LIBEXAMPLE_DEPRECATED
#endif

#ifndef LIBEXAMPLE_DEPRECATED_NO_EXPORT
#  define LIBEXAMPLE_DEPRECATED_NO_EXPORT LIBEXAMPLE_NO_EXPORT LIBEXAMPLE_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define LIBEXAMPLE_NO_DEPRECATED
#endif

#endif
