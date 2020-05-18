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
			current->next = NULL;  // Make sure next is NULL
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

	struct Node *head = deck;
	
	while(head)
	{
		head = head->next;
		if (head)
			size++;
	}
	
	return size;
}

Card* deck_deal(Deck** deck)
{
	Card *card = NULL;

	if (*deck == NULL)
		return NULL;

	struct Node *head = *deck;

	card = card_create(head->card->suit, head->card->face);

	
    (*deck) = (*deck)->next;
  
    card_free(head->card);
    free(head);

	return card;
}
