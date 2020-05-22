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

TEST(CardTest,JackIsAJack){
    Card* card = card_create(Heart, Jack);
    Card* card2 = card_create(Heart, Jack);

    int value1 = card_value(card);
    int value2 = card_value(card2);

    bool success = card_equals(card, card2);

    EXPECT_TRUE(success);

    EXPECT_TRUE(value1 == value2);
}
