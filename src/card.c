#include <stdlib.h>
#include <stddef.h>
#include <wctype.h>
#include "blackjack.h"

Card* card_create(enum Suit suit, enum Face face)
{
	Card *card = malloc( sizeof(Card) );

	if (card == NULL)
		return NULL;

	card->suit = suit;
	card->face = face;

	// Ordinal is zero based.
	card->value = face+1;

	// Face cards are ten
	if ((face == Jack) || (face == Queen) || (face == King))
		card->value = 10;

	// Aces are high by default
	if (face == Ace)
		card->value = 11;

	return card;
}

void card_free(Card* card)
{
	if (card == NULL)
		return;

	free(card);
}

int card_value(Card *card)
{
	if (card == NULL)
		return 0;
	else
		return card->value;
}

int card_suit(Card *card)
{
	if (card == NULL)
		return 0;
	else
		return card->suit;
}

int card_face(Card *card)
{
	if (card == NULL)
		return 0;
	else
		return card->face;
}

bool card_equals(Card *card, void *obj)
{
	if (obj == NULL)
		return false;

	//if (!(obj instanceof Card))
	//	return false;

	Card *other = (Card *) obj;
	// Card is equal if Face and Suit match
	return (card->face == other->face &&
		card->suit == other->suit);
}

char* card_tostring(Card *card)
{
	wchar_t s = 0x2663;
	switch (card->suit)
	{
		case Spade:
			s = 0x2660;
			break;
		case Heart:
			s = 0x2665;
			break;
		case Diamond:
			s = 0x2666;
			break;
		default:
			break;
	}
	return printf("%d%d", card->value, s);
}
