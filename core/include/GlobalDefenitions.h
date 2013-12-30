
#ifndef _GLOBALDEFENITIONS_H__
#define _GLOBALDEFENITIONS_H__

#ifdef WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT
#endif

#endif
