// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#ifndef GAME_H_
#define GAME_H_
#include "IQuestionContainer.h"

#include <list>
#include <memory>

class Player;
enum class QuestionType;

// =============================================================================
//! \brief The Game class implements...
// =============================================================================
class Game {
// =============================================================================
// Section for Ctor / Dtor
// =============================================================================
    public: Game(IQuestionContainer& generator);
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

    private: bool DidPlayerWin();
    private: void ShiftPlayers();

// =============================================================================
// Section for Member declaration
// =============================================================================
    private: IQuestionContainer& _question;
    private: std::list<std::unique_ptr<Player>> _players;
};
// =============================================================================
// Inline method implementation
// =============================================================================

#endif // GAME_H_
// =============================================================================
//! \file
//! \copyright
// ============================== end of file: Game.hpp ========================
