
#include "KMPSearch.h"
#include "Exceptions.h"
#include "Utils.h"

using namespace std;

vector<int> computePrefixFunction(string pattern)
{
    vector<int> prefixFunction(pattern.size());

    prefixFunction[0] = 0;
    for (unsigned int k = 0, i = 1; i < pattern.size(); i++)
    {
        while (k > 0 && pattern[i] != pattern[k])
            k = prefixFunction[k - 1];

        if (pattern[i] == pattern[k])
            k++;

        prefixFunction[i] = k;
    }

    return prefixFunction;
}

vector<int> KMPSearch(string pattern, string text)
{
    checkInputData(pattern, text);

    vector<int> prefixFunction = computePrefixFunction(pattern);
    vector<int> patternPositions;

    for (unsigned int k = 0, i = 0; i < text.size(); i++)
    {
        while (k > 0 && pattern[k] != text[i])
            k = prefixFunction[k - 1];
        if (pattern[k] == text[i])
            k++;

        if (k == pattern.size())
            patternPositions.push_back(i - pattern.size() + 1);
    }

    return patternPositions;
}
