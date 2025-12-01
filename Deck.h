#ifndef DECK_H
#define DECK_H

#include "Hand.h"
#include "GenericPlayer.h"

// Deck inherits from Hand so it stores Card pointers.
class Deck : public Hand
{
public:
    Deck();

    void populate();
    void shuffle();
    void deal(Hand& aHand);
    void additionalCards(GenericPlayer& gp);
};

#endif
