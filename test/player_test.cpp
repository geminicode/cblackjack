#include <stdio.h>
#include "gtest/gtest.h"
#include "blackjack.h"

//#define DEALER_NAME "Dealer"
char DEALER_NAME[]="Dealer";

TEST(PlayerTest,PlayerCreate){
    Player *player = player_create(DEALER_NAME);

    EXPECT_TRUE(player != NULL);

    player_free(player);
}

TEST(PlayerTest,PlayerHit){
    Player *player = player_create(DEALER_NAME);
    Card* card = card_create(Heart, Jack);

    int value = player_hit(player, card);

    EXPECT_TRUE(player != NULL);
    EXPECT_EQ(value, 10);

    player_free(player);
    card_free(card);
}

TEST(PlayerTest,PlayerHitTwice){
    Player *player = player_create(DEALER_NAME);

    Deck *deck = deck_create();
    Card *card = deck_deal(&deck);
    Card *card2 = deck_deal(&deck);

    int value = player_hit(player, card);
    value = player_hit(player, card2);
    int cards_in_deck = deck_size(deck);

    EXPECT_TRUE(player != NULL);
    EXPECT_EQ(cards_in_deck, 54);
    EXPECT_GT(value, 1);

    player_free(player);
    deck_free(deck);
    card_free(card);
    card_free(card2);
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
