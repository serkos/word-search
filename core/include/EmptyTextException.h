
#ifndef __EMPTYTEXTEXCEPTION_H__
#define __EMPTYTEXTEXCEPTION_H__

#include <iostream>
#include <exception>

#include "GlobalDefenitions.h"

EXPORT class EmptyTextException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Text is empty";
    }
};


#endif
