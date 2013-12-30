
#ifndef __ILLEGALPATTERNSIZEEXCEPTION_H__
#define __ILLEGALPATTERNSIZEEXCEPTION_H__

#include <iostream>
#include <exception>

class IllegalPatternSizeException : public std::exception
{
public:
    virtual const char* what() const throw();
};


#endif
