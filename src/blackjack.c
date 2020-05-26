#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <wctype.h>
#include "blackjack.h"

BlackJack* blackjack_create()
{
	BlackJack *game = malloc( sizeof(BlackJack) );

	if (game == NULL)
		return NULL;

	game->deck = deck_create();

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
			//playerStatus.put(player, HandStatus.BlackJack);
		}
		else
		{
			//playerStatus.put(player, HandStatus.Busted);
		}
	}
	else
	{
		//playerStatus.put(player, HandStatus.Playing);
	}
}
