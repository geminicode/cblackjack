#include <stdio.h>
#include "gtest/gtest.h"
#include "blackjack.h"

TEST(PlayerTest,PlayerCreate){
    Player *player = player_create("Dealer");

    EXPECT_TRUE(player != NULL);

    player_free(player);
}

TEST(PlayerTest,PlayerHit){
    Player *player = player_create("Dealer");
    Card* card = card_create(Heart, Jack);

    int value = player_hit(player, card);

    EXPECT_TRUE(player != NULL);
    EXPECT_EQ(value, 10);

    player_free(player);
    card_free(card);
}
/*
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
    EXPECT_EQ(size, 55);

    deck_free(deck);
}
*/
