// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#include "Player.h"

#include <limits>

using namespace std;

Player::Player(const string& name)
    : _punished(false)
    , _rank(0)
    , _coins(0)
    , _name(name)
{}

void Player::AddRank(uint32_t rank) {
    _rank += rank;
    if (_rank >= MaxRank) {
	_rank = 0;
    }
}

void Player::IncreaseCoins() {
    if (_coins < numeric_limits<decltype(_coins)>::max()) {
	_coins++;
    }
}

// =============================================================================
//! \file
//! \copyright
// ============================ end of file: Player.cpp ========================
