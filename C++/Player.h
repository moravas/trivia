// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <ostream>

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
    public: void AddRank(uint32_t rank);
    public: inline uint32_t Rank() const;
    public: void IncreaseCoins();
    public: inline uint32_t Coins() const;

    public: inline void Punish();
    public: inline void Rehabilitate();

    public: inline bool IsPunished() const;

    public: inline void PrintToStream(std::ostream& out) const;

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
inline uint32_t Player::Rank() const {
    return _rank;
}

inline uint32_t Player::Coins() const {
    return _coins;
}

inline void Player::Punish() {
    _punished = true;
}

inline void Player::Rehabilitate() {
    _punished = false;
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
