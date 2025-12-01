#include "Player.h"
#include <iostream>

Player::Player(const std::string& name)
    : GenericPlayer(name)
{
}

bool Player::isHitting() const
{
    // basic input prompt
    std::cout << getName() << ", do you want a hit? (y/n): ";

    char response;
    std::cin >> response;

    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    std::cout << getName() << " wins." << std::endl;
}

void Player::lose() const
{
    std::cout << getName() << " loses." << std::endl;
}

void Player::push() const
{
    std::cout << getName() << " pushes (tie)." << std::endl;
}
