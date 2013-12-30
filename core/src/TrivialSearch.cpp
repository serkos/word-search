
#include "TrivialSearch.h"
#include "Exceptions.h"
#include "Utils.h"

using namespace std;

vector<int> trivialSearch(string pattern, string text)
{	
    checkInputData(pattern, text);
    
    vector<int> patternPositions;

    for (unsigned int i = 0; i < text.size() - pattern.size() + 1; i++)
	{
        unsigned int s = 0;
        for (unsigned int j = 0; j < pattern.size(); j++)
            if (pattern[j] == text[i + j])
				s++;
        if (s == pattern.size())
            patternPositions.push_back(i);
	}

    return patternPositions;
}
