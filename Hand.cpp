#include "Hand.h"

Hand::Hand()
{
    // The assignment says reserve 7 because most blackjack hands fit that.
    cardVector.reserve(7);
}

Hand::~Hand()
{
    clearHand();  // destructor must clean up pointers
}

void Hand::add(Card* cardPtr)
{
    // very basic push_back
    cardVector.push_back(cardPtr);
}

void Hand::clearHand()
{
    // delete all the card pointers stored inside
    for (std::vector<Card*>::iterator it = cardVector.begin();
        it != cardVector.end(); ++it)
    {
        delete *it;   // deletes card
        *it = nullptr; // set pointer to nullptr after deletion
    }

    // now clear the vector itself
    cardVector.clear();
}

int Hand::getTotal() const
{
    // empty hand -> total 0
    if (cardVector.empty())
    {
        return 0;
    }

    // if first card is face down, total is hidden according to rubric
    if (cardVector[0]->getValue() == 0)
    {
        return 0;
    }

    int total = 0;
    bool foundAce = false;

    // basic loop to sum values
    for (std::vector<Card*>::const_iterator it = cardVector.begin();
        it != cardVector.end(); ++it)
    {
        int val = (*it)->getValue();
        total += val;

        // if any card value is 1 then it's an ace
        if (val == 1)
        {
            foundAce = true;
        }
    }

    // If an ace is present, try counting one as 11 instead of 1
    if (foundAce && total <= 11)
    {
        total += 10;
    }

    return total;
}
