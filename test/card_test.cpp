#include <stdio.h>
#include "gtest/gtest.h"
#include "blackjack.h"

TEST(CardTest,SpadeIsASpade){
    enum Suit spade;
    spade = Spade;
    EXPECT_EQ(1,spade);
}

TEST(CardTest,HeartIsNotADiamond){
    enum Suit heart;
    heart = Heart;
    EXPECT_NE(heart,Diamond);
}

TEST(CardTest,CreateCard){

    Card* card = card_create(Heart, Two);
    EXPECT_EQ(card->suit,Heart);
}
