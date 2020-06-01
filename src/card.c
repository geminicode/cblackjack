#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <wctype.h>
#include <wchar.h>
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

wchar_t* card_tostring(Card *card)
{
	int ARRAY_LENGTH = 5;
	wchar_t *buffer = malloc( sizeof(wchar_t) * ARRAY_LENGTH);
	memset(buffer, '\0', sizeof(char) * ARRAY_LENGTH);
	wchar_t *s = malloc( sizeof(wchar_t) * 2);
	wchar_t *f = malloc( sizeof(wchar_t) * 3);
	memset(f, '\0', sizeof(char) * 3);

	switch (card->suit)
	{
		case Spade:
			s = L"\u2660";
			break;
		case Heart:
			s = L"\u2665";
			break;
		case Diamond:
			s = L"\u2666";
			break;
		default:
			s = L"\u2663";
			break;
	}

	switch (card->face)
	{
		case Jack:
			swprintf(f, 3, L"%ls", L"J");
			break;
		case Queen:
			swprintf(f, 3, L"%ls", L"Q");
			break;
		case King:
			swprintf(f, 3, L"%ls", L"K");
			break;
		case Ace:
			swprintf(f, 3, L"%ls", L"A");
			break;
		default:
			swprintf(f, 3, L"%d", card->value);
			break;
	}

	swprintf(buffer, ARRAY_LENGTH, L"%ls%ls", f, s);

	return buffer;
}
