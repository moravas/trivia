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

#include <iostream>
#include <sstream>

using namespace std;

Game::Game()
{}

Game::~Game()
{}

void Game::Add(const string& playerName) {
    _players.emplace_back(make_unique<Player>(playerName));
    cout << playerName << " was added" << endl;
    cout << "They are player number " << _players.size() << endl;
}

void Game::Roll(IQuestionContainer& generator) {
    ActivePlayer().Roll(generator);
}

bool Game::CheckAnswer() {
    if (rand() % 9 == 7) {
	cout << "Question was incorrectly answered" << endl;
	ActivePlayer().Punish();
	ShiftPlayers();
	return true;
    }
    else if (ActivePlayer().IsPunished()) {
	ActivePlayer().Rehabilitate();
	if (!ActivePlayer().IsPunished()) {
	    cout << "Answer was correct!!!!" << endl;
	    ActivePlayer().IncreaseCoins();
	    ShiftPlayers();
	    return ActivePlayer().IsWin();
	}
	else {
	    ShiftPlayers();
	    return true;
	}
    }
    else {
	cout << "Answer was corrent!!!!" << endl;
	ShiftPlayers();
	ShiftPlayers();
	return ActivePlayer().IsWin();
    }
}

void Game::ShiftPlayers() {
    _players.emplace_back(move(_players.front()));
    _players.pop_front();
}

// =============================================================================
//! \file
//! \copyright
// ============================== end of file: Game.cpp ========================
