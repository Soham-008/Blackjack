#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card
{
public:

    // The ranks (Ace starts at 1 in this project)
    enum RANK { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
                EIGHT, NINE, TEN, JACK, QUEEN, KING };

    // suits; kind of irrelevant for blackjack but included for completeness
    enum SUIT { CLUBS = 0, DIAMONDS, HEARTS, SPADES };

    // constructor - initializes using the initializer list (per rubric)
    Card(RANK r = ACE, SUIT s = SPADES, bool faceUp = true);

    int getValue() const;     // value of the card (or 0 if faceDown)
    void flip();              // turns it face-down/up

    // friend print operator so we can do cout << card
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
    RANK rank;
    SUIT suit;
    bool faceUp;   // true = card is showing, false = face down
};

#endif
