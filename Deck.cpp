#include "Deck.h"
#include "Card.h"
#include <random>
#include <iostream>

Deck::Deck()
{
    cardVector.reserve(52);  // standard deck size
    populate();
    shuffle();
}

void Deck::populate()
{
    // make sure deck is empty first
    clearHand();

    // loops through ranks/suits to create the 52 cards
    for (int r = Card::ACE; r <= Card::KING; ++r)
    {
        for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
        {
            Card* c = new Card((Card::RANK)r, (Card::SUIT)s, true);
            add(c);
        }
    }
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(cardVector.begin(), cardVector.end(), gen);
}

void Deck::deal(Hand& aHand)
{
    if (cardVector.empty())
    {
        std::cout << "No more cards to deal." << std::endl;
        return;
    }

    // take card from back of vector
    Card* card = cardVector.back();
    cardVector.pop_back();

    aHand.add(card);
}

void Deck::additionalCards(GenericPlayer& gp)
{
    // give cards as long as they want to hit
    while (!gp.isBusted() && gp.isHitting())
    {
        deal(gp);
        std::cout << gp << std::endl;

        if (gp.isBusted())
        {
            gp.bust();
        }
    }
}
