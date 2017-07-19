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
    public: std::string createRockQuestion(int index);
    public: bool isPlayable();
    public: bool add(std::string playerName);
    public: int howManyPlayers();
    public: void roll(int roll);
    public: bool wasCorrectlyAnswered();
    public: bool wrongAnswer();

    private: void askQuestion();
    private: std::string currentCategory();
    private: bool didPlayerWin();

// =============================================================================
// Section for Member declaration
// =============================================================================
    private: int places[6];
    private: int purses[6];
    private: bool inPenaltyBox[6];
    private: std::vector<std::string> players;

    private: std::list<std::string> popQuestions;
    private: std::list<std::string> scienceQuestions;
    private: std::list<std::string> sportsQuestions;
    private: std::list<std::string> rockQuestions;

    private: int currentPlayer;
    private: bool isGettingOutOfPenaltyBox;

};
// =============================================================================
// Inline method implementation
// =============================================================================

#endif // GAME_H_
// =============================================================================
//! \file
//! \copyright
// ============================== end of file: Game.hpp ========================
