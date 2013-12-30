
#ifndef __EMPTYPATTERNEXCEPTION_H__
#define __EMPTYPATTERNEXCEPTION_H__

#include <iostream>
#include <exception>

#include "GlobalDefenitions.h"

EXPORT class EmptyPatternException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Pattern is empty";
    }
};


#endif
