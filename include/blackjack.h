#ifndef BLACKJACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/** \addtogroup Card
 *  @{
 */

/**
 * Standard Suit for a deck of cards
 * @author Darrell Fuller
 *
 */
enum Suit {
	Club,  // '\u2663'
	Spade, // '\u2660'
	Heart, // '\u2665'
	Diamond // '\u2666'
};

/**
 * Cards in one suite
 * @author Darrell Fuller
 *
 */
enum Face {
	One,
	Two, 
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace
};

/**
 * Card in a Deck.  A Card has a Suit (Heart, Spade, etc.) and a Face (Two, Queen, Ace, etc).
 * There is an associated value for each card.  Face cards are 10.
 *
 * @author Darrell Fuller
 *
 */
typedef struct _Card {
	/** Card Suit (Hearts, Club, etc.. */
	enum Suit suit;
	/** Card Face (Two, Jack, Ace, etc) */
	enum Face face;
	/** Card Value (1-11) */
	int value;
} Card;


/**
 * Create a single card with the supplied parameters
 * @param [in] suit of card
 * @param [in] face of card
 */
Card* card_create(enum Suit suit, enum Face face);

/**
 * dispose of a card.
 * @param [in] card to dispose of
 */
void card_free(Card* card);

/**
 * Numerical value of Face of Card.
 * @param [in] card to check
 * @return card value
 */
int card_value(Card *card);

/**
 * Card Suit (Heart, Spade, etc.)
 * @param [in] card to check
 * @return suit of card
 */
int card_suit(Card *card);

/**
 * Card Face (Two, Jack, Ace, etc.)
 * @param [in] card to check
 * @return face of card
 */
int card_face(Card *card);

/**
 * Compare this card to another
 * @param [in] card to check
 * @param [in] other card to check
 * @param obj other card
 */
bool card_equals(Card *card, void *obj);

/**
 * String representation of a card.
 * @param [in] card to check
 */
char* card_tostring(Card *card);

/** @}*/  /* END addtogroup Card */

/** \addtogroup Card
 *  @{
 */

/**
 * Simple structure for a Deck of Cards (i.e. LinkedList)
 */
struct Node {
	/** Card in Deck */
    Card* card;
    /** Next card (node) in Deck */
    struct Node* next;
};

/** Deck Friendly name */
typedef struct Node Deck;

/**
 * Create a Deck of Cards
 * @returns deck of cards
 */
Deck* deck_create();

/**
 * Dispose of the Deck
 * @param[in] deck to displose of
 */
void deck_free(Deck* deck);

/**
 * Number of cards in the deck
 * @param[in] deck of cards
 */
int deck_size(Deck* deck);

/** @}*/  /* END addtogroup Card */

/**
 * Deal a single card from the deck
 * @param[in] deck to pull card from
 */
Card* deck_deal(Deck* deck);


#ifdef __cplusplus
}
#endif  /* __cplusplus  */

#endif /* BLACKJACK_H  */
