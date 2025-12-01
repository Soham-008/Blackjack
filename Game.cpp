#include "Game.h"
#include <iostream>

Game::Game(const std::string& playerName)
    : m_deck(), m_player(playerName), m_house("House")
{
    // deck constructor already populates + shuffles
}

void Game::play()
{
    // deal 2 cards to player and house (two rounds)
    for (int i = 0; i < 2; i++)
    {
        m_deck.deal(m_player);
        m_deck.deal(m_house);
    }

    // hide house's first card
    m_house.flipFirstCard();

    std::cout << m_player << std::endl;
    std::cout << m_house << std::endl;

    // player's turn
    m_deck.additionalCards(m_player);

    // reveal dealer card
    m_house.flipFirstCard();
    std::cout << m_house << std::endl;

    // dealer's turn
    m_deck.additionalCards(m_house);

    // determine winner
    if (m_house.isBusted())
    {
        if (!m_player.isBusted())
        {
            m_player.win();
        }
    }
    else
    {
        if (!m_player.isBusted())
        {
            if (m_player.getTotal() > m_house.getTotal())
            {
                m_player.win();
            }
            else if (m_player.getTotal() < m_house.getTotal())
            {
                m_player.lose();
            }
            else
            {
                m_player.push();
            }
        }
        else
        {
            m_player.lose();
        }
    }

    // cleanup
    m_player.clearHand();
    m_house.clearHand();
}
