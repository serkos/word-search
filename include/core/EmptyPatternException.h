
#ifndef __EMPTYPATTERNEXCEPTION_H__
#define __EMPTYPATTERNEXCEPTION_H__

#include <iostream>
#include <exception>

class EmptyPatternException : public std::exception
{
public:
    virtual const char* what() const throw();
};


#endif
