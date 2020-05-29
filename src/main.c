#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "blackjack.h"

/**
 * Display the Blackjack Gui
 * @param[in] game to display
 */
void display_gui(BlackJack* game);

int game_loop(BlackJack* game);


void display_gui(BlackJack* game)
{
	for(int i=0; i < game->num_players; i++)
	{
		int hand_value = player_hand_value(game->players[i]);
		wprintf(L"%s %s [%d]", (i == game->current_player)?"->":"..", game->players[i]->name, hand_value);
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
	wprintf(L"\n\n\n\nPlayer %s Turn: [H]it [S]tand [Q]uit : ", DEALER_NAME );
}

int game_loop(BlackJack* game)
{
	int ret_val = 1;
	wchar_t cmd[2];
	Player* player = blackjack_current_player(game);

	while(ret_val > 0)
	{
		display_gui(game);
		wscanf(L"%ls", cmd);

		switch(cmd[0])
		{
		case(CMD_QUIT):
		case(CMD_QUITL):
			wprintf(L"Thank you for playing!\n\n");
			ret_val = 0;
			break;
		case(CMD_HIT):
		case(CMD_HITL):
		    blackjack_deal_card(game, player);
		    int hand_value = player_hand_value(player);
			if (hand_value >= 21)
			{
				player = blackjack_next_player(game);
			}
			break;
		case(CMD_STAND):
		case(CMD_STANDL):
			blackjack_player_status(game, player, Standing);
			player = blackjack_next_player(game);
			break;
		default:
			wprintf(L"Invalid Command: [%lc]\n\n", cmd[0]);
			break;
		}
	}

	return ret_val;
}

int main(void)
{
	setlocale(LC_ALL, "en_US.utf-8");  // MUST BE HERE TO GET THE SYMBOLS
	wprintf(L"Hello\r\n");

	BlackJack* game = blackjack_create(3);

	blackjack_start(game);

	game_loop(game);
}

