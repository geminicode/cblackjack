#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <wctype.h>
#include "blackjack.h"

/******************  PRIVATE FUNCTIONS **************************/

/**
 * Update the status of a player
 * @param[in] game with players to update
 * @param[in] player to update status
 * @param[in] status of player
 */
void blackjack_player_status(BlackJack* game, Player* player, int status);


/****************** END PRIVATE FUNCTIONS ***********************/


BlackJack* blackjack_create(int count)
{
	char player_name[10];
	int i=0;
	BlackJack *game = malloc( sizeof(BlackJack) );

	if (game == NULL)
		return NULL;

	game->num_players = count +1;
	game->deck = deck_create();

	if (game->num_players > MAX_PLAYERS)
	{
		game->num_players = MAX_PLAYERS;
	}

	for (i=0; i < game->num_players - 1; i++)
	{
		sprintf(player_name, "Player#%d", i + 1);
		game->players[i] = player_create(player_name);
		game->player_status[i] = Playing;
	}
	game->players[i] = player_create(DEALER_NAME);

	return game;
}

void blackjack_free(BlackJack* game)
{
	if (game == NULL)
		return;

	deck_free(game->deck);

	free(game);
}

void blackjack_deal_card(BlackJack* game, Player* player)
{
	blackjack_deal_cards(game, player, 1);
}

/**
 * Deal a specified number of cards to a player
 * @param player to deal cards to
 * @param cards to deal out
 */
void blackjack_deal_cards(BlackJack* game, Player* player, int cards)
{
	for (int i=0; i<cards; i++)
	{
		Card* card = deck_deal(&(game->deck));
		player_hit(player, card);
		// card_free(card);
	}

	int hand_value = player_hand_value(player);
	if (hand_value >= 21)
	{
		if (hand_value == 21)
		{
			blackjack_player_status(game, player, BlackJack21);
		}
		else
		{
			blackjack_player_status(game, player, Busted);
		}
	}
	else
	{
		blackjack_player_status(game, player, Playing);
	}
}

void blackjack_player_status(BlackJack* game, Player* player, int status)
{
	for(int i=0; i < game->num_players; i++)
	{
		if (strcmp(game->players[i]->name, player->name))
		{
			game->player_status[i]=status;
			//printf("matched player [%s] [%d]", player->name, status);
			break;
		}
	}
}


int blackjack_start(BlackJack* game)
{
	int value = 0;

	for(int i=0; i < game->num_players; i++)
	{
		blackjack_deal_cards(game, game->players[i], 2);
	}

	return value;
}
