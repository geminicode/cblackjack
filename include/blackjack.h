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

/**
 * Deal a single card from the deck
 * @param[in] deck to pull card from
 */
Card* deck_deal(Deck** deck);

/** @}*/  /* END addtogroup Card */


/** \addtogroup Player
 *  @{
 */

 /** Player's Hand Friendly name */
 typedef struct Node Hand;

 /**
  * Simple structure for a Deck of Cards (i.e. LinkedList)
  */
 typedef struct _Player {
 		/** Player's Hand */
     Hand* hand;
     /** Next card (node) in Deck */
     char name[10];
 } Player;

/**
* Create a new player.
* @param[in] name of player
* @return player that was created
*/
Player* player_create(char *name);

/**
* Dispose of a player.
* @param[in] player to dispose of
*/
void player_free(Player* player);

/**
* Deal a player a single card.
* @param[in] player to deal to
* @param[in] card given to player
* return player's hand Total
* @see player_hand_value
*/
int player_hit(Player* player, Card* card);

/**
* Total the players hand and return the value.
* @param[in] player to total hand
* @return value of player's hand
*/
int player_hand_value(Player* player);

 /** @}*/  /* END addtogroup Player */

#ifdef __cplusplus
}
#endif  /* __cplusplus  */

#endif /* BLACKJACK_H  */
