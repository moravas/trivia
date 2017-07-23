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
    public: Game();
    public: ~Game();

// =============================================================================
// Section for Implement / Overridden
// =============================================================================

// =============================================================================
// Section for Other methods
// =============================================================================
    public: void Add(const std::string& playerName);
    public: void Roll(IQuestionContainer& generator);
    public: bool CheckAnswer();

    private: void ShiftPlayers();
    private: inline Player& ActivePlayer() const;

// =============================================================================
// Section for Member declaration
// =============================================================================
    private: std::list<std::unique_ptr<Player>> _players;
};
// =============================================================================
// Inline method implementation
// =============================================================================
inline Player& Game::ActivePlayer() const {
    return *(_players.front());
}

#endif // GAME_H_
// =============================================================================
//! \file
//! \copyright
// ============================== end of file: Game.hpp ========================
