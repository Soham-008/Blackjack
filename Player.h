#ifndef PLAYER_H
#define PLAYER_H

#include "GenericPlayer.h"

// Player is the human user and asks for input.
class Player : public GenericPlayer
{
public:
    Player(const std::string& name = "");
    virtual ~Player() = default;

    virtual bool isHitting() const override;

    void win() const;
    void lose() const;
    void push() const;
};

#endif
