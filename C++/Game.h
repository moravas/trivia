// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#ifndef GAME_H_
#define GAME_H_

#include <list>
#include <vector>
#include <iostream>
#include <memory>

// =============================================================================
//! \brief The Game class implements...
// =============================================================================
class Player;

class Game {
// =============================================================================
// Section for Ctor / Dtor
// =============================================================================
    public: Game();
    public: ~Game();

// =============================================================================
// Section for Implement / Overridden
// =============================================================================

// =============================================================================
// Section for Other methods
// =============================================================================
    public: void Add(const std::string& playerName);
    public: void Roll(int roll);
    public: bool WasCorrectlyAnswered();
    public: bool WrongAnswer();

    private: void AskQuestion();
    private: bool DidPlayerWin();
    private: void ShiftPlayers();

// =============================================================================
// Section for Member declaration
// =============================================================================
	// use enum for question type

    private: std::list<std::unique_ptr<Player>> _players;

    private: std::list<std::string> _popQuestions;
    private: std::list<std::string> _scienceQuestions;
    private: std::list<std::string> _sportsQuestions;
    private: std::list<std::string> _rockQuestions;

    private: bool _isGettingOutOfPenaltyBox;

};
// =============================================================================
// Inline method implementation
// =============================================================================

#endif // GAME_H_
// =============================================================================
//! \file
//! \copyright
// ============================== end of file: Game.hpp ========================
