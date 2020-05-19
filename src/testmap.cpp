#include <gtest/gtest.h>
#include "KeyValueMap.h"
#include <string.h>

TEST(KeyValueMap, EmptyTest){
SKeyValueMapRef KeyValueMap = KeyValueMapCreate();

ASSERT_TRUE(KeyValueMap != NULL);
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 0);
KeyValueMapDestroy(KeyValueMap);
}

TEST(KeyValueMap, EmptyGetTest){
SKeyValueMapRef KeyValueMap = KeyValueMapCreate();

ASSERT_TRUE(KeyValueMap != NULL);
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 0);
EXPECT_TRUE(KeyValueMapGet(KeyValueMap, "2007") == NULL);
KeyValueMapDestroy(KeyValueMap);
}

TEST(KeyValueMap, SetTest){
SKeyValueMapRef KeyValueMap = KeyValueMapCreate();

ASSERT_TRUE(KeyValueMap != NULL);
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 0);
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2007", "In Rainbows"));
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 1);
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2010", "TKOL"));
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 2);
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2016", "A Moon Shaped Pool"));
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 3);
EXPECT_FALSE(KeyValueMapSet(KeyValueMap, NULL  , "OkNotOk"));     //null test
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 3);
EXPECT_FALSE(KeyValueMapSet(NULL ,"2003", "Hail to the Thief"));        //null test
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 3);
EXPECT_FALSE(KeyValueMapSet(KeyValueMap, "2019", NULL));        //null test
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 3);
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2003", "Hail to the Thief"));
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 4);
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2007", "Live From the Basement"));
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 4);
}

TEST(KeyValueMap, GetTest){
SKeyValueMapRef KeyValueMap = KeyValueMapCreate();

ASSERT_TRUE(KeyValueMap != NULL);
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 0);
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2007", "In Rainbows"));
EXPECT_EQ(strcmp(KeyValueMapGet(KeyValueMap, "2007"), "In Rainbows"), 0);
EXPECT_EQ(strcmp(KeyValueMapGet(KeyValueMap, "2007"), "In Rainbows"), 0);
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 1);
EXPECT_FALSE(KeyValueMapGet(NULL, "2007"));     //null test
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 1);
EXPECT_FALSE(KeyValueMapGet(KeyValueMap, NULL));    //null test
EXPECT_FALSE(KeyValueMapGet(NULL, "2007"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2000", "Kid A"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2003", "Hail To The Thief"));
EXPECT_EQ(strcmp(KeyValueMapGet(KeyValueMap, "2003"), "Hail To The Thief"), 0);
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2007", "Live from the Basement"));
EXPECT_EQ(strcmp(KeyValueMapGet(KeyValueMap, "2007"), "Live from the Basement"), 0);
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 3);

KeyValueMapDestroy(KeyValueMap);
}

TEST(KeyValueMap, DeleteTest){
SKeyValueMapRef KeyValueMap = KeyValueMapCreate();
ASSERT_TRUE(KeyValueMap != NULL);
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2007", "In Rainbows"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2003", "Hail to the Thief"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1995", "The Bends"));
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 3);
EXPECT_TRUE(KeyValueMapDelete(KeyValueMap, "2003"));
EXPECT_FALSE(KeyValueMapGet(KeyValueMap, "2003"));
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 2);
EXPECT_FALSE(KeyValueMapDelete(NULL, "2003")); //null test
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 2);
EXPECT_FALSE(KeyValueMapDelete(KeyValueMap, NULL)); //null test
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 2);
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1993", "Pablo Honey"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2010", "TKOL"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2016", "A Moon Shaped Pool"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2001", "Amnesiac"));
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 6);
EXPECT_TRUE(KeyValueMapDelete(KeyValueMap, "1993"));
EXPECT_EQ(KeyValueMapSize(KeyValueMap), 5);
KeyValueMapDestroy(KeyValueMap);
}

TEST(KeyValueMap, ForwardIteratorTest){     //create iterator, start at beginning
SKeyValueMapRef KeyValueMap = KeyValueMapCreate();
SKeyValueMapIteratorRef Iterator, IteratorEnd;
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2007", "In Rainbows"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2003", "Hail to the Thief"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1995", "The Bends"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1993", "Pablo Honey"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2010", "TKOL"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2016", "A Moon Shaped Pool"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2001", "Amnesiac"));
Iterator = KeyValueMapBegin(KeyValueMap);
Iterator = KeyValueMapIteratorNext(Iterator);
Iterator = KeyValueMapIteratorNext(Iterator);
Iterator = KeyValueMapIteratorNext(Iterator);
Iterator = KeyValueMapIteratorNext(Iterator);
Iterator = KeyValueMapIteratorNext(Iterator);
Iterator = KeyValueMapIteratorNext(Iterator);
Iterator = KeyValueMapIteratorNext(Iterator);
IteratorEnd = KeyValueMapEnd(KeyValueMap);
EXPECT_TRUE(Iterator == IteratorEnd);
KeyValueMapDestroy(KeyValueMap);

}
TEST(KeyValueMap, ReverseIteratorTest){
SKeyValueMapRef KeyValueMap = KeyValueMapCreate();
SKeyValueMapIteratorRef Iterator, IteratorBegin;
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2007", "In Rainbows"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2003", "Hail to the Thief"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1995", "The Bends"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1993", "Pablo Honey"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2010", "TKOL"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2016", "A Moon Shaped Pool"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2001", "Amnesiac"));
Iterator = KeyValueMapEnd(KeyValueMap);
Iterator = KeyValueMapIteratorPrevious(Iterator);
Iterator = KeyValueMapIteratorPrevious(Iterator);
Iterator = KeyValueMapIteratorPrevious(Iterator);
Iterator = KeyValueMapIteratorPrevious(Iterator);
Iterator = KeyValueMapIteratorPrevious(Iterator);
Iterator = KeyValueMapIteratorPrevious(Iterator);
Iterator = KeyValueMapIteratorPrevious(Iterator);
IteratorBegin = KeyValueMapBegin(KeyValueMap);
EXPECT_TRUE(Iterator == IteratorBegin);
KeyValueMapDestroy(KeyValueMap);
}

TEST(KeyValueMap, IteratorFindTest){
SKeyValueMapRef KeyValueMap = KeyValueMapCreate();
SKeyValueMapIteratorRef Iterator;
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2007", "In Rainbows"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2003", "Hail to the Thief"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1995", "The Bends"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1993", "Pablo Honey"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2010", "TKOL"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2016", "A Moon Shaped Pool"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2001", "Amnesiac"));
Iterator = KeyValueMapBegin(KeyValueMap);
EXPECT_TRUE(Iterator == KeyValueMapFind(KeyValueMap, "1993"));
KeyValueMapDestroy(KeyValueMap);
}

TEST(KeyValueMap, IteratorFindSetTest){

SKeyValueMapRef KeyValueMap = KeyValueMapCreate();
SKeyValueMapIteratorRef Iterator;
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2007", "In Rainbows"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2003", "Hail to the Thief"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1995", "The Bends"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1993", "Pablo Honey"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2010", "TKOL"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2016", "A Moon Shaped Pool"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2001", "Amnesiac"));
Iterator = KeyValueMapBegin(KeyValueMap);
Iterator = KeyValueMapIteratorNext(Iterator);
KeyValueMapIteratorSet(Iterator, "It set");
EXPECT_EQ(strcmp(KeyValueMapGet(KeyValueMap, "1995"), "It set"), 0);
KeyValueMapDestroy(KeyValueMap);
}

TEST(KeyValueMap, IteratorFindDeleteTest){
SKeyValueMapRef KeyValueMap = KeyValueMapCreate();
SKeyValueMapIteratorRef Iterator, NextIt;
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2007", "In Rainbows"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2003", "Hail to the Thief"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1995", "The Bends"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "1993", "Pablo Honey"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2010", "TKOL"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2016", "A Moon Shaped Pool"));
EXPECT_TRUE(KeyValueMapSet(KeyValueMap, "2001", "Amnesiac"));
Iterator = KeyValueMapBegin(KeyValueMap);
Iterator = KeyValueMapIteratorNext(Iterator);
NextIt = KeyValueMapIteratorNext(Iterator);
EXPECT_TRUE(KeyValueMapIteratorDelete(Iterator) == NextIt);
KeyValueMapDestroy(KeyValueMap);
}

TEST(KeyValueMap, InvalidParameterTest){
    /* INSERT TESTS HERE */
}
