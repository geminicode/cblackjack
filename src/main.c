#include <stdio.h>
#include "blackjack.h"

/**
 * Display the Blackjack Gui
 * @param[in] game to display
 */
void display_gui(BlackJack* game);



void display_gui(BlackJack* game)
{
	for(int i=0; i < game->num_players; i++)
	{
		int hand_value = player_hand_value(game->players[i]);
		printf("%s [%d]\n", game->players[i]->name, hand_value);

		//log(String.format("%s (%s) %s\n", (p.equals(currentPlayer))?"->":"..", playerStatus.get(p),  p.getHand()));

	}
	printf("\n\n\n\nPlayer %s Turn: [H]it [S]tand [Q]uit : ", DEALER_NAME );
}


int main(void)
{
	printf("Hello\r\n");

	BlackJack* game = blackjack_create(3);

	blackjack_start(game);

	display_gui(game);
}

