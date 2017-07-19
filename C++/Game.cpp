// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#include "Game.h"

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
}

Game::Game()
    : _places({})
    , _purses({})
    , _popQuestions(GenerateQuestion("Pop Question ", 50))
    , _scienceQuestions(GenerateQuestion("Science Question ", 50))
    , _sportsQuestions(GenerateQuestion("Sports Question ", 50))
    , _rockQuestions(GenerateQuestion("Rock Question ", 50))
    , _currentPlayer(0)
    , _isGettingOutOfPenaltyBox(false)
{}

bool Game::IsPlayable() {
    return (GetPlayersCount() >= 2);
}

bool Game::Add(const string& playerName) {
    _players.push_back(playerName);
    _places[GetPlayersCount()] = 0;
    _purses[GetPlayersCount()] = 0;
    _inPenaltyBox[GetPlayersCount()] = false;

    cout << playerName << " was added" << endl;
    cout << "They are player number " << _players.size() << endl;
    return true;
}

int Game::GetPlayersCount() {
    return _players.size();
}

void Game::Roll(int roll) {
    cout << _players[_currentPlayer] << " is the current player" << endl;
    cout << "They have rolled a " << roll << endl;

    if (_inPenaltyBox[_currentPlayer]) {
	if (roll % 2 != 0) {
	    _isGettingOutOfPenaltyBox = true;
	    cout << _players[_currentPlayer] << " is getting out of the penalty box" << endl;
	    _places[_currentPlayer] = _places[_currentPlayer] + roll;
	    if (_places[_currentPlayer] > 11) {
		_places[_currentPlayer] = _places[_currentPlayer] - 12;
	    }

	    cout << _players[_currentPlayer] << "'s new location is " << _places[_currentPlayer] << endl;
	    cout << "The category is " << CurrentCategory() << endl;
	    AskQuestion();
	}
	else {
	    cout << _players[_currentPlayer] << " is not getting out of the penalty box" << endl;
	    _isGettingOutOfPenaltyBox = false;
	}
    }
    else {
	_places[_currentPlayer] = _places[_currentPlayer] + roll;
	if (_places[_currentPlayer] > 11) {
	    _places[_currentPlayer] = _places[_currentPlayer] - 12;
	}

	cout << _players[_currentPlayer] << "'s new location is " << _places[_currentPlayer] << endl;
	cout << "The category is " << CurrentCategory() << endl;
	AskQuestion();
    }
}

void Game::AskQuestion() {
    const string category(CurrentCategory());
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


string Game::CurrentCategory() {
    if (_places[_currentPlayer] == 0) return "Pop";
    if (_places[_currentPlayer] == 4) return "Pop";
    if (_places[_currentPlayer] == 8) return "Pop";
    if (_places[_currentPlayer] == 1) return "Science";
    if (_places[_currentPlayer] == 5) return "Science";
    if (_places[_currentPlayer] == 9) return "Science";
    if (_places[_currentPlayer] == 2) return "Sports";
    if (_places[_currentPlayer] == 6) return "Sports";
    if (_places[_currentPlayer] == 10) return "Sports";
    return "Rock";
}

bool Game::WasCorrectlyAnswered() {
    if (_inPenaltyBox[_currentPlayer]) {
	if (_isGettingOutOfPenaltyBox) {
	    cout << "Answer was correct!!!!" << endl;
	    _purses[_currentPlayer]++;
	    cout << _players[_currentPlayer] << " now has " << _purses[_currentPlayer] <<  " Gold Coins." << endl;

	    _currentPlayer++;
	    if (_currentPlayer == _players.size()) {
		_currentPlayer = 0;
	    }

	    return DidPlayerWin();
	}
	else {
	    _currentPlayer++;
	    if (_currentPlayer == _players.size()) {
		_currentPlayer = 0;
	    }

	    return true;
	}
    }
    else {
	cout << "Answer was corrent!!!!" << endl;
	_purses[_currentPlayer]++;
	cout << _players[_currentPlayer] << " now has " << _purses[_currentPlayer] << " Gold Coins." << endl;

	_currentPlayer++;
	if (_currentPlayer == _players.size()) {
	    _currentPlayer = 0;
	}

	return DidPlayerWin();
    }
}

bool Game::WrongAnswer() {
    cout << "Question was incorrectly answered" << endl;
    cout << _players[_currentPlayer] + " was sent to the penalty box" << endl;
    _inPenaltyBox[_currentPlayer] = true;

    _currentPlayer++;
    if (_currentPlayer == _players.size()) {
	_currentPlayer = 0;
    }

    return true;
}


bool Game::DidPlayerWin()
{
    return !(_purses[_currentPlayer] == 6);
}


// =============================================================================
//! \file
//! \copyright
// ============================== end of file: Game.cpp ========================
