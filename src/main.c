#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "blackjack.h"

/**
 * Display the Blackjack Gui
 * @param[in] game to display
 */
void display_gui(BlackJack* game);

int game_loop(BlackJack* game);

void display_gui(BlackJack* game)
{
	char game_status[10] = {};

	for(int i=0; i < game->num_players; i++)
	{
		int hand_value = player_hand_value(game->players[i]);
		switch(game->player_status[i])
		{
		case Playing:
			strcpy(game_status, "Playing");
			break;
		case Standing:
			strcpy(game_status, "Standing");
			break;
		case BlackJack21:
			strcpy(game_status, "BlackJack");
			break;
		case Busted:
			strcpy(game_status, "Busted");
			break;
		case Winner:
			strcpy(game_status, "Winner");
			break;
		default:
			strcpy(game_status, "Playing99");
			break;
		}

		wprintf(L"%s (%s) %s [%d]", (i == game->current_player)?"->":"..", game_status, game->players[i]->name, hand_value);
        struct Node *current = game->players[i]->hand;

        while(current)
        {
        	wchar_t *buffer = card_tostring(current->card);
            current = current->next;
            wprintf(L" %ls", buffer);
        }
		wprintf(L"\n");
	}
	Player* player = blackjack_current_player(game);
	wprintf(L"\n\n\n\nPlayer %s Turn: [H]it [S]tand [Q]uit : ", player->name );
}

int game_loop(BlackJack* game)
{
	int ret_val = 1;
	wchar_t cmd[2];

	while(ret_val > 0)
	{
		display_gui(game);
		wscanf(L"%ls", cmd);

		ret_val = blackjack_command_handler(game, cmd[0]);

		if (ret_val == 0)
		{
			display_gui(game);
		};
	}

	wprintf(L"\n\nGame is over!\n");

	return ret_val;
}

int main(void)
{
	setlocale(LC_ALL, "en_US.utf-8");  // MUST BE HERE TO GET THE SYMBOLS
	wprintf(L"Welcome to BlackJack!.  Let's Play a Game.\n  Five or less Players, NOT including the Dealer.\n");

	int num_players = 3;
	while(1)
	{
		wprintf(L"How many players? ");
		wscanf(L"%d", &num_players);

		if (num_players == 0)
		{
			num_players = 1;
		}
		else if (num_players > 5)
		{
			wprintf(L"Error: Too many players!");
			continue;
		}
		wprintf(L"Starting Game with %d Players\n", num_players);

		break;
	}

	BlackJack* game = blackjack_create(num_players);

	blackjack_start(game);

	game_loop(game);
}

