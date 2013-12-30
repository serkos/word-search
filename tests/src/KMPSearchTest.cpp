
#include <vector>
#include <string>

#include "gtest/gtest.h"
#include "core/KMPSearch.h"
#include "core/EmptyPatternException.h"
#include "core/EmptyTextException.h"
#include "core/IllegalPatternSizeException.h"

TEST(KMPSearchTest, RaiseExceptionIfWordIsEmpty)
{
    string pattern = "";
    string text = "Hello, World!";
    EXPECT_THROW(KMPSearch(pattern, text), EmptyPatternException);
}

TEST(KMPSearchTest, RaiseExceptionIfTextIsEmpty)
{
    string pattern = "word";
    string text = "";
    EXPECT_THROW(KMPSearch(pattern, text), EmptyTextException);
}

TEST(KMPSearchTest, RaiseExceptionIfTextLessThanWord)
{
    string pattern = "abracadabra";
    string text = "test";
    EXPECT_THROW(KMPSearch(pattern, text), IllegalPatternSizeException);
}

TEST(KMPSearchTest, CanFindWordInText)
{
    string pattern = "World";
    string text = "Hello, World! Hello, World!";

    vector<int> patternPositions = KMPSearch(pattern, text);

    EXPECT_EQ(2, patternPositions.size());
    EXPECT_EQ(7, patternPositions[0]);
    EXPECT_EQ(21, patternPositions[1]);
}

TEST(KMPSearchTest, GivesEmptyVectorIfNoWordsFound)
{
    string pattern = "xx";
    string text = "zzzzz";

    vector<int> patternPositions = KMPSearch(pattern, text);

    EXPECT_EQ(0, patternPositions.size());
}

TEST(KMPSearchTest, CanFindOverlappingEntries)
{
    string pattern = "olo";
    string text = "ololololo";

    vector<int> patternPositions = KMPSearch(pattern, text);

    EXPECT_EQ(4, patternPositions.size());
    EXPECT_EQ(0, patternPositions[0]);
    EXPECT_EQ(2, patternPositions[1]);
    EXPECT_EQ(4, patternPositions[2]);
    EXPECT_EQ(6, patternPositions[3]);
}

TEST(KMPSearchTest, CanFindWordIfWordSizeAndTextSizeAreEqual)
{
    string pattern = "test";
    string text = "test";

    vector<int> patternPositions = KMPSearch(pattern, text);

    EXPECT_EQ(1, patternPositions.size());
    EXPECT_EQ(0, patternPositions[0]);
}
