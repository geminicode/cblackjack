#include <stdio.h>
#include "gtest/gtest.h"
#include "blackjack.h"

TEST(BlackJackTest,GameCreate){
    BlackJack *game = blackjack_create(1);

    EXPECT_TRUE(game != NULL);

    blackjack_free(game);
}


TEST(BlackJackTest,DealCard){
    BlackJack *game = blackjack_create(1);
    Player *player = player_create(DEALER_NAME);

    EXPECT_TRUE(game != NULL);

    int size = deck_size(game->deck);
    EXPECT_EQ(size, 56);

    blackjack_deal_card(game, player);

    size = deck_size(game->deck);
    EXPECT_EQ(size, 55);

    blackjack_free(game);
    player_free(player);
}

TEST(BlackJackTest,DealCards){
    BlackJack *game = blackjack_create(1);
    Player *player = player_create(DEALER_NAME);

    EXPECT_TRUE(game != NULL);

    int size = deck_size(game->deck);
    EXPECT_EQ(size, 56);

    blackjack_deal_cards(game, player, 2);

    size = deck_size(game->deck);
    EXPECT_EQ(size, 54);

    blackjack_free(game);
    player_free(player);
}

/*
TEST(BlackJackTest,DealCheck){
    BlackJack *game = blackjack_create(1);
    EXPECT_TRUE(game != NULL);

    int size = game_size(game);
    EXPECT_EQ(size, 56);

    Card *card = game_deal(&game);

    size = game_size(game);
    EXPECT_TRUE(card != NULL);
    EXPECT_EQ(size, 55);

    game_free(game);
}
*/
