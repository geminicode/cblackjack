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

    Card *card = deck_deal(&deck);

    size = deck_size(deck);
    EXPECT_TRUE(card != NULL);
    EXPECT_EQ(size, 55);

    deck_free(deck);
}
