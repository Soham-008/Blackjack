#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::string& n)
    : name(n)
{
}

GenericPlayer::~GenericPlayer()
{
    // nothing special to do here
}

bool GenericPlayer::isBusted() const
{
    return getTotal() > 21;
}

void GenericPlayer::bust() const
{
    // simple busted message
    std::cout << name << " busted." << std::endl;
}

const std::string& GenericPlayer::getName() const
{
    return name;
}

void GenericPlayer::setName(const std::string& n)
{
    name = n;
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& gp)
{
    os << gp.name << "\t";

    if (!gp.cardVector.empty())
    {
        // loop through cards to print each one
        for (std::vector<Card*>::const_iterator it = gp.cardVector.begin();
            it != gp.cardVector.end(); ++it)
        {
            os << **it << "\t";
        }

        // show total if not hidden
        if (gp.getTotal() != 0)
        {
            os << "(" << gp.getTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }

    return os;
}
