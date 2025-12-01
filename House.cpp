#include "House.h"
#include <iostream>

House::House(const std::string& name)
    : GenericPlayer(name)
{
}

bool House::isHitting() const
{
    // dealer hits on 16 and stands on 17+ (based)
    return getTotal() <= 16;
}

void House::flipFirstCard()
{
    if (cardVector.empty())
    {
        std::cout << "House has no cards to flip." << std::endl;
        return;
    }

    cardVector[0]->flip(); // flip the first card
}
