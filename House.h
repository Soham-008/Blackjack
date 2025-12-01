#ifndef HOUSE_H
#define HOUSE_H

#include "GenericPlayer.h"

// House uses automatic rules instead of user input
class House : public GenericPlayer
{
public:
    House(const std::string& name = "House");
    virtual ~House() = default;

    virtual bool isHitting() const override;

    void flipFirstCard();
};

#endif
