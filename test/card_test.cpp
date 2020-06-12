#include <stdio.h>
#include "gtest/gtest.h"
#include "blackjack.h"

TEST(CardTest,SpadeIsASpade){
    enum Suit spade;
    spade = Spade;
    EXPECT_EQ(1,spade);
}

TEST(CardTest,JackIsATen){
    Card* card = card_create(Heart, Jack);
    Card* card2 = card_create(Heart, Ten);

    int value1 = card_value(card);
    int value2 = card_value(card2);

    EXPECT_EQ(value1, value2);
}

TEST(CardTest,HeartIsNotADiamond){
    enum Suit heart;
    heart = Heart;
    EXPECT_NE(heart,Diamond);
}

TEST(CardTest,CreateCard){
    Card* card = card_create(Heart, Two);
    EXPECT_EQ(card->suit,Heart);
    card_free(card);
}

TEST(CardTest,FaceCard){
    Card* card = card_create(Heart, Two);
    int f = card_face(card);
    EXPECT_EQ(f,Two);
    card_free(card);
}

TEST(CardTest,SuitCard){
    Card* card = card_create(Heart, Two);
    int s = card_suit(card);
    EXPECT_EQ(s,Heart);
    card_free(card);
}

TEST(CardTest,FreeCardNull){
    Card* card = NULL;
    card_free(card);
}

TEST(CardTest,ValueCardNull){
    Card* card = NULL;
    int answer = card_value(card);
    EXPECT_EQ(answer,0);
}

TEST(CardTest,JackIsAJack){
    Card* card = card_create(Heart, Jack);
    Card* card2 = card_create(Heart, Jack);

    int value1 = card_value(card);
    int value2 = card_value(card2);

    bool success = card_equals(card, card2);

    EXPECT_TRUE(success);

    EXPECT_TRUE(value1 == value2);
}

TEST(CardTest,JackIsANull){
    Card* card = card_create(Heart, Jack);
    Card* card2 = NULL;

    bool success = card_equals(card, card2);

    EXPECT_FALSE(success);
}

TEST(CardTest,HeartToString){
    Card* card = card_create(Heart, Two);
    wchar_t *buffer = card_tostring(card);
    EXPECT_TRUE(buffer != NULL);
    card_free(card);
}


TEST(CardTest,DiamondToString){
    Card* card = card_create(Diamond, Jack);
    wchar_t *buffer = card_tostring(card);
    EXPECT_TRUE(buffer != NULL);
    card_free(card);
}

TEST(CardTest,ClubToString){
    Card* card = card_create(Club, Queen);
    wchar_t *buffer = card_tostring(card);
    EXPECT_TRUE(buffer != NULL);
    card_free(card);
}

TEST(CardTest,SpadeToString){
    Card* card = card_create(Spade, King);
    wchar_t *buffer = card_tostring(card);
    EXPECT_TRUE(buffer != NULL);
    card_free(card);
}

TEST(CardTest,AceToString){
    Card* card = card_create(Spade, Ace);
    wchar_t *buffer = card_tostring(card);
    EXPECT_TRUE(buffer != NULL);
    card_free(card);
}

TEST(CardTest,SuitIsNull){
    int suit = card_suit(NULL);
    EXPECT_EQ(suit, 0);
 }

TEST(CardTest,FaceIsNull){
    int face = card_face(NULL);
    EXPECT_EQ(face, 0);
 }
