#include "Card.h"
#include <string>

// small note: I didn't use <array> this time so it's a bit more "basic C++"

Card::Card(RANK r, SUIT s, bool faceUpInit)
    : rank(r), suit(s), faceUp(faceUpInit)
{
    // nothing else to do here, pdf says leave body empty anyway
}

int Card::getValue() const
{
    // if face-down return 0 right away
    if (faceUp == false)
    {
        return 0;
    }

    // Face cards (10, J, Q, K) are all worth 10.
    if (rank >= TEN)
    {
        return 10;
    }

    // All other cards just return their numeric value.
    // ACE returns 1 (Hand class adjusts to 11 later if possible)
    return (int)rank;
}

void Card::flip()
{
    // beginner-friendly toggle
    faceUp = !faceUp;
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    // beginner style plain arrays
    static std::string RANKS[14] =
    { "0","A","2","3","4","5","6","7","8","9","10","J","Q","K" };

    static char SUITS[4] = { 'C','D','H','S' };

    if (!card.faceUp)
    {
        os << "XX";   // face down cards just show XX
    }
    else
    {
        os << RANKS[(int)card.rank] << SUITS[(int)card.suit];
    }

    return os;
}
