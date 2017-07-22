// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#include "Player.h"
#include "QuestionType.h"

#include <limits>
#include <iostream>

using namespace std;

Player::Player(const string& name)
    : _punished(false)
    , _rank(0)
    , _coins(0)
    , _name(name)
{}

void Player::Ask(IQuestionContainer& questionContainer) const {
    questionContainer.Ask(Rank());
}

void Player::AddRank(uint32_t rank) {
    _rank += rank;
    if (_rank >= MaxRank) {
	_rank = 0;
    }

    cout << _name << "'s new location is " << _rank << endl
	 << "The category is " << Rank() << endl;
}

QuestionType Player::Rank() const {
    if ((_rank % 4) == 0) {
	return QuestionType::Pop;
    }
    else if ((_rank % 4) == 1) {
	return QuestionType::Science;
    }
    else if ((_rank % 4) == 2) {
	return QuestionType::Sports;
    }
    else {
	return QuestionType::Rock;
    }
}

void Player::IncreaseCoins() {
    if (_coins < numeric_limits<decltype(_coins)>::max()) {
	_coins++;
    }
}

void Player::Rehabilitate() {
    _punished = false;
    cout << _name << " is getting out of the penalty box" << endl;
}

// =============================================================================
//! \file
//! \copyright
// ============================ end of file: Player.cpp ========================
