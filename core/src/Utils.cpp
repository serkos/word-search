
#include "Utils.h"

using namespace std;

void checkInputData(string pattern, string text)
{
    if (pattern.empty())
        THROW_EXCEPTION(EmptyPatternException)

    if (text.empty())
        THROW_EXCEPTION(EmptyTextException)

    if (pattern.size() > text.size())
        THROW_EXCEPTION(IllegalPatternSizeException)
}
