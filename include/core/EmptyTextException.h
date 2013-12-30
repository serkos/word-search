
#ifndef __EMPTYTEXTEXCEPTION_H__
#define __EMPTYTEXTEXCEPTION_H__

#include <iostream>
#include <exception>

class EmptyTextException : public std::exception
{
public:
    virtual const char* what() const throw();
};


#endif