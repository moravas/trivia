// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#include "Game.h"
#include "Player.h"
#include "QuestionType.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

Game::Game(IQuestionContainer& generator)
    : _question(generator)
{}

Game::~Game()
{}

void Game::Add(const string& playerName) {
    _players.emplace_back(make_unique<Player>(playerName));
    cout << playerName << " was added" << endl;
    cout << "They are player number " << _players.size() << endl;
}

void Game::Roll(int roll) {
    auto& player = *(_players.front());
    cout << player << " is the current player" << endl;
    cout << "They have rolled a " << roll << endl;

    if (player.IsPunished()) {
	if (roll % 2 != 0) {
	    player.Rehabilitate();
	    player.AddRank(roll);
	    player.Ask(_question);
	}
    }
    else {
	player.AddRank(roll);
	player.Ask(_question);
    }
}

bool Game::WasCorrectlyAnswered() {
    auto& player = *(_players.front());
    if (player.IsPunished()) {
	if (_isGettingOutOfPenaltyBox) {
	    cout << "Answer was correct!!!!" << endl;
	    player.IncreaseCoins();
	    cout << player << " now has " << player.Coins() <<  " Gold Coins." << endl;
	    ShiftPlayers();
	    return DidPlayerWin();
	}
	else {
	    ShiftPlayers();
	    return true;
	}
    }
    else {
	cout << "Answer was corrent!!!!" << endl;
	ShiftPlayers();
	cout << player << " now has " << player.Coins() << " Gold Coins." << endl;
	ShiftPlayers();
	return DidPlayerWin();
    }
}

bool Game::WrongAnswer() {
    auto& player = *(_players.front());
    cout << "Question was incorrectly answered" << endl;
    cout << player << " was sent to the penalty box" << endl;
    player.Punish();
    ShiftPlayers();
    return true;
}


bool Game::DidPlayerWin()
{
    return !(_players.front()->Coins() == 6);
}

void Game::ShiftPlayers() {
    _players.emplace_back(move(_players.front()));
    _players.pop_front();
}

// =============================================================================
//! \file
//! \copyright
// ============================== end of file: Game.cpp ========================
