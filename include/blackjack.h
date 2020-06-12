#ifndef BLACKJACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <wchar.h>

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
typedef struct Card {
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
void card_free(Card *card);

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
wchar_t* card_tostring(Card *card);

/** @}*//* END addtogroup Card */

/** \addtogroup Deck
 *  @{
 */

/**
 * Simple structure for a Deck of Cards (i.e. LinkedList)
 */
struct Node {
	/** Card in Deck */
	Card *card;
	/** Next card (node) in Deck */
	struct Node *next;
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
void deck_free(Deck *deck);

/**
 * Number of cards in the deck
 * @param[in] deck of cards
 */
int deck_size(Deck *deck);

/**
 * Deal a single card from the deck
 * @param[in] deck to pull card from
 */
Card* deck_deal(Deck **deck);

/** @}*//* END addtogroup Deck */

/** \addtogroup Player
 *  @{
 */

/** Player's Hand Friendly name */
typedef struct Node Hand;

/**
 * Simple structure for a Deck of Cards (i.e. LinkedList)
 */
typedef struct Player {
	/** Player's Hand */
	Hand *hand;
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
void player_free(Player *player);

/**
 * Deal a player a single card.
 * @param[in] player to deal to
 * @param[in] card given to player
 * return player's hand Total
 * @see player_hand_value
 */
int player_hit(Player *player, Card *card);

/**
 * Total the players hand and return the value.
 * @param[in] player to total hand
 * @return value of player's hand
 */
int player_hand_value(Player *player);

/** @}*//* END addtogroup Player */

/** \addtogroup BlackJack
 *  @{
 */

/**
 * Status of a Players Hand
 * @author Darrell Fuller
 */
enum HandStatus {
	/** Player is playing the game */
	Playing,
	/** Player is playing the game */
	Standing,
	/** Player is holding his hand and current points */
	BlackJack21,
	/** Player has the highest possible hand */
	Busted,
	/** Player has won the game */
	Winner
};

#define MAX_PLAYERS 5

// Commands
/** Quit Key Command  */
#define CMD_QUIT  'Q'
#define CMD_QUITL  'q'
/** Hit Key Command  */
#define CMD_HIT   'H'
#define CMD_HITL   'h'
/** Stand Key Command  */
#define CMD_STAND 'S'
#define CMD_STANDL 's'

/** Dealer's name  */
#define  DEALER_NAME "Dealer"

/**
 * Simple structure for the BlackJack Game
 */
typedef struct BlackJack {
	/** Deck of Cards for Game */
	Deck *deck;
	/** Number of players (including Dealer) */
	int num_players;
	/** Players in the game, including Dealer */
	Player *players[MAX_PLAYERS+1];
	/** Status of all Players, including Dealer */
	int player_status[MAX_PLAYERS+1];
	/** The current player */
	int current_player;
} BlackJack;

/**
 * Create the BlackJack Game.
 * @param[int] count of players
 * @return Game.
 */
BlackJack* blackjack_create(int count);

/**
 * Dispose of the BlackJack Game.
 * @param[in] Game to dispose of.
 */
void blackjack_free(BlackJack *game);

/**
 * Deal a single card to the specified player
 * @param[in] player to deal cards to
 */
void blackjack_deal_card(BlackJack *game, Player *player);

/**
 * Deal a specified number of cards to a player
 * @param[in] player to deal cards to
 * @param[in] cards to deal out
 */
void blackjack_deal_cards(BlackJack *game, Player *player, int cards);

/**
 * Setup the game.  Deal initial cards to players.
 * @param[in] game to start.
 */
int blackjack_start(BlackJack* game);

/**
 * Get the current user.
 * @param[in] game with players.
 * @return player who is current
 */
Player* blackjack_current_player(BlackJack* game);

/**
 * Get the next user.
 * @param[in] game with players.
 * @return player who is next becomes current
 */
Player* blackjack_next_player(BlackJack* game);

/**
 * Update the status of a player
 * @param[in] game with players to update
 * @param[in] player to update status
 * @param[in] status of player
 */
void blackjack_player_status(BlackJack* game, Player* player, int status);


/**
 * Update the status of a player
 * @param[in] game with players to update
 * @param[in] cmd to action to
 * @return false (0) if game is over.
 */
int blackjack_command_handler(BlackJack* game, wchar_t cmd);


/** @}*//* END addtogroup BlackJack */

#ifdef __cplusplus
}
#endif  /* __cplusplus  */

#endif /* BLACKJACK_H  */
