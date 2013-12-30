
#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include "EmptyPatternException.h"
#include "EmptyTextException.h"
#include "IllegalPatternSizeException.h"

#define THROW_EXCEPTION(Type) \
    { Type exception; throw exception; }

#endif
