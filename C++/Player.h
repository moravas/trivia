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
    private: enum class PunishmentState {
	    Free,
	    Punished,
	    Rehabilitation
	};

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
    public: void Roll(IQuestionContainer& questionContainer);
    public: void IncreaseCoins();
    public: void Rehabilitate();
    public: void Punish();

    public: inline bool IsWin() const;
    public: inline bool IsPunished() const;

    private: void AddRank(uint32_t rank);
    private: QuestionType Rank() const;

    private: inline void StartRehabilitate();

// =============================================================================
// Section for Member declaration
// =============================================================================
    public: static constexpr uint32_t MaxRank = 12;
    public: static constexpr uint32_t WinnerCoins = 6;

    private: PunishmentState _punished;
    private: uint32_t _rank;
    private: uint32_t _coins;
    private: const std::string _name;
};
// =============================================================================
// Inline method implementation
// =============================================================================
inline bool Player::IsWin() const {
    return _coins == WinnerCoins;
}

inline void Player::StartRehabilitate() {
    _punished = PunishmentState::Rehabilitation;
}

inline bool Player::IsPunished() const {
    return _punished != PunishmentState::Free;;
}

#endif // PLAYER_H_
// =============================================================================
//! \file
//! \copyright
// ============================ end of file: Player.hpp ========================
