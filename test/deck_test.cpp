#include <stdio.h>
#include "gtest/gtest.h"
#include "blackjack.h"

TEST(DeckTest,DeckCreate){
    Deck *deck = deck_create();

    EXPECT_TRUE(deck != NULL);

    deck_free(deck);
}

TEST(DeckTest,DeckSize){
    Deck *deck = deck_create();
    EXPECT_TRUE(deck != NULL);

    int size = deck_size(deck);
    EXPECT_EQ(size, 56);

    deck_free(deck);
}

TEST(DeckTest,DealCheck){
    Deck *deck = deck_create();
    EXPECT_TRUE(deck != NULL);

    int size = deck_size(deck);
    EXPECT_EQ(size, 56);

    Card *card = deck_deal(deck);

    size = deck_size(deck);
    EXPECT_EQ(size, 55);

    deck_free(deck);
}

/*
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
}
*/
