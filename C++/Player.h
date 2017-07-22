// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#ifndef PLAYER_H_
#define PLAYER_H_
#include "IQuestionContainer.h"

#include <string>
#include <ostream>

enum class QuestionType;

// =============================================================================
//! \brief The Player class implements ...
// =============================================================================
class Player {
// =============================================================================
// Section for Ctor / Dtor
// =============================================================================
    public: Player(const std::string& name);

// =============================================================================
// Section for Implement / Overridden
// =============================================================================

// =============================================================================
// Section for Other methods
// =============================================================================
    public: void Ask(IQuestionContainer& questionContainer) const;
    public: void AddRank(uint32_t rank);
    public: void IncreaseCoins();
    public: void Rehabilitate();

    public: inline uint32_t Coins() const;

    public: inline void Punish();

    public: inline bool IsPunished() const;

    public: inline void PrintToStream(std::ostream& out) const;

    private: QuestionType Rank() const;

// =============================================================================
// Section for Member declaration
// =============================================================================
    public: static constexpr uint32_t MaxRank = 12;

    private: bool _punished;
    private: uint32_t _rank;
    private: uint32_t _coins;
    private: const std::string _name;
};
// =============================================================================
// Inline method implementation
// =============================================================================
inline uint32_t Player::Coins() const {
    return _coins;
}

inline void Player::Punish() {
    _punished = true;
}

inline bool Player::IsPunished() const {
    return _punished;
}

inline void Player::PrintToStream(std::ostream& out) const {
    out << _name;
}

inline std::ostream& operator<< (std::ostream& out, const Player& player) {
    player.PrintToStream(out);
    return out;
}

#endif // PLAYER_H_
// =============================================================================
//! \file
//! \copyright
// ============================ end of file: Player.hpp ========================
