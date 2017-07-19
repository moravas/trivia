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

// =============================================================================
//! \brief The Game class implements...
// =============================================================================
class Game{
// =============================================================================
// Section for Ctor / Dtor
// =============================================================================
    public: Game();

// =============================================================================
// Section for Implement / Overridden
// =============================================================================

// =============================================================================
// Section for Other methods
// =============================================================================
    public: bool IsPlayable();
    public: bool Add(const std::string& playerName);
    public: int GetPlayersCount();
    public: void Roll(int roll);
    public: bool WasCorrectlyAnswered();
    public: bool WrongAnswer();

    private: void AskQuestion();
    private: std::string CurrentCategory();
    private: bool DidPlayerWin();

// =============================================================================
// Section for Member declaration
// =============================================================================
    private: int _places[6];
    private: int _purses[6];
    private: bool _inPenaltyBox[6];
    private: std::vector<std::string> _players;

    private: std::list<std::string> _popQuestions;
    private: std::list<std::string> _scienceQuestions;
    private: std::list<std::string> _sportsQuestions;
    private: std::list<std::string> _rockQuestions;

    private: uint_fast32_t _currentPlayer;
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
