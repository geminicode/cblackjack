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

TEST(BlackJackTest,QuitGame){
    BlackJack *game = blackjack_create(4);

    blackjack_start(game);

    wchar_t cmd = 0x0051;

    int ret_value = blackjack_command_handler(game, cmd);
    EXPECT_EQ(ret_value, 0);

    blackjack_free(game);
}

TEST(BlackJackTest,HitCmdGame){
    BlackJack *game = blackjack_create(4);

    blackjack_start(game);

    wchar_t cmd = 0x0048;

    int ret_value = blackjack_command_handler(game, cmd);
    EXPECT_EQ(ret_value, 1);

    blackjack_free(game);
}

TEST(BlackJackTest,StandCmdGame){
    BlackJack *game = blackjack_create(4);

    blackjack_start(game);

    wchar_t cmd = 0x0053;

    int ret_value = blackjack_command_handler(game, cmd);
    EXPECT_EQ(ret_value, 1);

    blackjack_free(game);
}

TEST(BlackJackTest,CompleteGame){
    BlackJack *game = blackjack_create(4);

    blackjack_start(game);

    wchar_t cmd = 0x0048;

    int ret_value = 1;
    do{
    	ret_value = blackjack_command_handler(game, cmd);
    }while(ret_value);

    EXPECT_EQ(ret_value, 0);

    blackjack_free(game);
}

