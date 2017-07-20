// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#include "Game.h"
#include "Player.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

namespace {
    // TODO: use DI by outer class
    list<string> GenerateQuestion(const string& prefix, uint32_t count) {
	uint32_t index = 0;
	list<string> questions(count, prefix);
	for(auto& item: questions) {
	    item.append(to_string(index++));
	}

	return questions;
    }

    string MapRankToCategory(uint32_t rank) {
	switch (rank % 4) {
	    case 0: {
		return "Pop";
	    }
	    case 1: {
		return "Science";
	    }
	    case 2: {
		return "Sports";
	    }
	    case 3: {
		return "Rock";
	    }
	}

	return string();
    }
}

Game::Game()
    : _popQuestions(GenerateQuestion("Pop Question ", 50))
    , _scienceQuestions(GenerateQuestion("Science Question ", 50))
    , _sportsQuestions(GenerateQuestion("Sports Question ", 50))
    , _rockQuestions(GenerateQuestion("Rock Question ", 50))
    , _isGettingOutOfPenaltyBox(false)
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
	    _isGettingOutOfPenaltyBox = true;
	    cout << player << " is getting out of the penalty box" << endl;
	    player.AddRank(roll);

	    cout << player << "'s new location is " << player.Rank() << endl;
	    cout << "The category is " << MapRankToCategory(_players.front()->Rank()) << endl;
	    AskQuestion();
	}
	else {
	    cout << player << " is not getting out of the penalty box" << endl;
	    _isGettingOutOfPenaltyBox = false;
	}
    }
    else {
	player.AddRank(roll);
	cout << player << "'s new location is " << player.Rank() << endl;
	cout << "The category is " << MapRankToCategory(_players.front()->Rank()) << endl;
	AskQuestion();
    }
}

void Game::AskQuestion() {
    const string category(MapRankToCategory(_players.front()->Rank()));
    if (category == "Pop") {
	cout << _popQuestions.front() << endl;
	_popQuestions.pop_front();
    }
    else if (category == "Science") {
	cout << _scienceQuestions.front() << endl;
	_scienceQuestions.pop_front();
    }
    else if (category == "Sports") {
	cout << _sportsQuestions.front() << endl;
	_sportsQuestions.pop_front();
    }
    else if (category == "Rock") {
	cout << _rockQuestions.front() << endl;
	_rockQuestions.pop_front();
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
