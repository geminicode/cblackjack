#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "blackjack.h"

Player* player_create(char *name)
{
    if (name == NULL)
      return NULL;

    Player *player = (Player*)malloc(sizeof(Player));

  	if (player == NULL)
  		return NULL;

    strcpy(player->name, name);
    player->hand = NULL;

    return player;
}

void player_free(Player* player)
{
    if (player == NULL)
        return;

    deck_free((Deck*)player->hand);
    free(player);
}

int player_hit(Player* player, Card* card)
{
    int hand_value = 0;
    if (player == NULL || card == NULL)
        return -1;

    if (player->hand == NULL)
    {
      player->hand = (Hand*)malloc(sizeof(Hand));
      player->hand->card = card_create(card->suit, card->face);;
      player->hand->next = NULL;
    }
    else
    {
        struct Node *head = player->hand;
        struct Node *current = head;

        while(current)
        {
            current = current->next;
        }

        current = (struct Node*)malloc(sizeof(struct Node));
        current->card = card_create(card->suit, card->face);
        current->next = head;
        player->hand = current;
    }
    hand_value = player_hand_value(player);

    return hand_value;
}

int player_hand_value(Player* player)
{
    if (player == NULL)
        return -1;

    if (player->hand == NULL)
        return 0;

    int value = 0;

  	struct Node *head = player->hand;

  	while(head)
  	{
        if (head->card)
        {
            value+=head->card->value;
        }
  	    head = head->next;
  	}

  	return value;
}
