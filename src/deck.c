#include <stdlib.h>
#include <stddef.h>
#include "blackjack.h"

Deck* deck_create()
{
	struct Node *head = (struct Node*)malloc(sizeof(struct Node));
	struct Node *current = head;

	if (head == NULL)
		return NULL;

	for (int s=Club; s<=Diamond; s++)
	{
		for (int f=One; f<=Ace; f++)
		{
			current->card = card_create(s, f);
			current->next = (struct Node*)malloc(sizeof(struct Node));

			if (current->next == NULL)
			{
				deck_free(head);
				return NULL;
			}
			current = current->next;
		}
	}

	return head;
}

void deck_free(Deck* deck)
{
	if (deck == NULL)
		return;

	struct Node *current = deck;
	struct Node *temp = NULL;

	do{
		temp = current;
		current = current->next;
		card_free(temp->card);
		free(temp);
	}while(current->next != NULL);
}

int deck_size(Deck* deck)
{
	int size = 0;

	if (deck == NULL)
		return size;

	while(deck->next != NULL) {
		size++;
		deck = deck->next;
	}

	//size++;
	return size;
}

Card* deck_deal(Deck* deck)
{
	Card *card = NULL;

	if (deck == NULL)
		return NULL;

	struct Node *previous = deck;

	while(deck->next != NULL) {
		previous = deck;
		deck = deck->next;
	}

	card = card_create(deck->card->suit, deck->card->face);

	card_free(deck->card);
    free(previous->next);
	//previous->next = NULL;

	return card;
}
