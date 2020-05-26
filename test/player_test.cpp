#include <stdio.h>
#include "gtest/gtest.h"
#include "blackjack.h"

//#define DEALER "Dealer"
char DEALER[]=DEALER_NAME;

TEST(PlayerTest,PlayerCreate){
    Player *player = player_create(DEALER);

    EXPECT_TRUE(player != NULL);

    player_free(player);
}

TEST(PlayerTest,PlayerHit){
    Player *player = player_create(DEALER);
    Card* card = card_create(Heart, Jack);

    int value = player_hit(player, card);

    EXPECT_TRUE(player != NULL);
    EXPECT_EQ(value, 10);

    player_free(player);
    card_free(card);
}

TEST(PlayerTest,PlayerHitTwice){
    Player *player = player_create(DEALER);

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
