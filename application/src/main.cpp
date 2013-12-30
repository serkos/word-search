
#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "core/TrivialSearch.h"
#include "core/KMPSearch.h"

using namespace std;

string generateRandomWord(char *letters, int len)
{
	string word;
	word.resize(len);

	int numOfLetters = strlen(letters);

	for (int i = 0; i < len; i++)
	{
		int index = rand() % numOfLetters;
		word[i] = letters[index];
	}
	
	return word;
}

string generateWordFromBase(char *base, int degree)
{
	string word = "";

	for (int i = 0; i < degree; i++)
		word += base;

	return word;
}

string parseInput(char *argv[], int &key)
{
	string word;
	
	if (!strcmp(argv[key], "-word"))
	{
		word = argv[key + 1];
		key += 2;
	} else if (!strcmp(argv[key], "-random"))
	{
		char *letters = argv[key + 1];
		int len = atoi(argv[key + 2]);
		word = generateRandomWord(letters, len);
		key += 2;
	} else if (!strcmp(argv[key], "-base"))
	{
		char *base = argv[key + 1];
		int degree = atoi(argv[key + 2]);
		word = generateWordFromBase(base, degree);
		key += 2;
	}

	return word;
}

int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		cout << "Incorrect input format" << endl;
		return -1;
	}

	int key = 1;
	string word = parseInput(argv, key);
	string text = parseInput(argv, key);

    int numIterations = 1;
    long trivialSearhTime = 0;
    long KMPSearchTime = 0;

    vector<int> result;

    for (int i = 0; i < numIterations; i++)
    {
        long t = clock();

        result = trivialSearch(word, text);

        long t1 = clock();

        trivialSearhTime += t1 - t;
    }

    for (int i = 0; i < numIterations; i++)
    {
        long t = clock();

        result = KMPSearch(word, text);

        long t1 = clock();

        KMPSearchTime += t1 - t;
    }

    cout << "Average trivialSearch time: " << (double)trivialSearhTime / numIterations << endl;
    cout << "Average KMPSearch time: " << (double)KMPSearchTime / numIterations << endl;

    return 0;
}
