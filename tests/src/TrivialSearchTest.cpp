
#include <vector>
#include <iostream>

#include "gtest/gtest.h"
#include "core/TrivialSearch.h"
#include "core/EmptyPatternException.h"
#include "core/EmptyTextException.h"
#include "core/IllegalPatternSizeException.h"

using namespace std;

TEST(TrivialSearch, RaiseExceptionIfWordIsEmpty)
{
    string pattern = "";
    string text = "abracadabra";
    EXPECT_THROW(trivialSearch(pattern, text), EmptyPatternException);
}

TEST(TrivialSearch, RaiseExceptionIfTextIsEmpty)
{
    string pattern = "abracadabra";
    string text = "";
    EXPECT_THROW(trivialSearch(pattern, text), EmptyTextException);
}

TEST(TrivialSearch, RaiseExceptionIfTextLessThanWord)
{
    string pattern = "Hello, World!";
    string text = "Hi!";
    EXPECT_THROW(trivialSearch(pattern, text), IllegalPatternSizeException);
}

TEST(TrivialSearch, CanFindWordsInText)
{
    string text = "Hello, World! Hello!";
    string pattern = "Hello";

    std::vector<int> patternPositions = trivialSearch(pattern, text);

    EXPECT_EQ(2, patternPositions.size());
    EXPECT_EQ(0, patternPositions[0]);
    EXPECT_EQ(14, patternPositions[1]);
}

TEST(TrivialSearch, GivesEmptyVectorIfNoWordsFound)
{
    string text = "zzzz";
    string pattern = "x";

    std::vector<int> patternPositions = trivialSearch(pattern, text);

    EXPECT_EQ(0, patternPositions.size());
}

TEST(TrivialSearch, CanFindOverlappingEntries)
{
    string text = "olololololo";
    string pattern = "olo";

    std::vector<int> patternPositions = trivialSearch(pattern, text);

    EXPECT_EQ(5, patternPositions.size());
    EXPECT_EQ(0, patternPositions[0]);
    EXPECT_EQ(2, patternPositions[1]);
    EXPECT_EQ(4, patternPositions[2]);
    EXPECT_EQ(6, patternPositions[3]);
    EXPECT_EQ(8, patternPositions[4]);
}

TEST(TrivialSearch, CanFindWordIfWordSizeAndTextSizeAreEqual)
{
    string text = "test";
    string pattern = "test";

    std::vector<int> patternPositions = trivialSearch(pattern, text);

    EXPECT_EQ(1, patternPositions.size());
    EXPECT_EQ(0, patternPositions[0]);
}
