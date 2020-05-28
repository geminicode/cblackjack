#include <stdio.h>
#include <wchar.h>
#include <locale.h>
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
		wprintf(L"%s [%d]", game->players[i]->name, hand_value);
        struct Node *current = game->players[i]->hand;

        while(current)
        {
        	wchar_t *buffer = card_tostring(current->card);
            current = current->next;
            wprintf(L" %ls", buffer);
        }
		wprintf(L"\n");
	}
	wprintf(L"\n\n\n\nPlayer %s Turn: [H]it [S]tand [Q]uit : ", DEALER_NAME );
}


int main(void)
{
	setlocale(LC_ALL, "en_US.utf-8");  // MUST BE HERE TO GET THE SYMBOLS
	wprintf(L"Hello\r\n");

	BlackJack* game = blackjack_create(3);

	blackjack_start(game);

	display_gui(game);
}

