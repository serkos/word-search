
#ifndef __ILLEGALPATTERNSIZEEXCEPTION_H__
#define __ILLEGALPATTERNSIZEEXCEPTION_H__

#include <iostream>
#include <exception>

#include "GlobalDefenitions.h"

EXPORT class IllegalPatternSizeException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Text size less than pattern size";
    }
};


#endif
