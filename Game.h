#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "House.h"
#include <string>

// Game class handles one complete round of blackjack
class Game
{
private:
    Deck m_deck;
    Player m_player;
    House m_house;

public:
    Game(const std::string& playerName);
    void play();
};

#endif
