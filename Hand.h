#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

// Hand stores multiple Card pointers.
// I keep this pretty straightforward on purpose.
class Hand
{
protected:
    std::vector<Card*> cardVector;  // holds cards

public:
    Hand();
    virtual ~Hand();

    void add(Card* cardPtr); // add card pointer to the hand
    void clearHand();        // delete all cards
    int getTotal() const;    // total value of the cards (Ace logic inside)
};

#endif
