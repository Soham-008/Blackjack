#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "Hand.h"
#include <string>
#include <iostream>

// GenericPlayer feeds into Player and House.
// I tried to keep comments casual and simple.
class GenericPlayer : public Hand
{
protected:
    std::string name;

public:
    GenericPlayer(const std::string& n = "");
    virtual ~GenericPlayer();

    virtual bool isHitting() const = 0; // player/house decides when to hit

    bool isBusted() const;
    void bust() const;

    const std::string& getName() const;
    void setName(const std::string& n);

    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& gp);
};

#endif
