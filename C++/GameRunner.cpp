// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#include "Game.h"

#include <stdlib.h>

int main() {
    Game game;
    game.Add("Chet");
    game.Add("Pat");
    game.Add("Sue");

    bool notAWinner = true;
    while(notAWinner) {
	game.Roll(rand() % 5 + 1);
	if (rand() % 9 == 7) {
	    notAWinner = game.WrongAnswer();
	}
	else {
	    notAWinner = game.WasCorrectlyAnswered();
	}
    }

    return 0;
}

// =============================================================================
//! \file
//! \copyright
// =========================== end of file: GameRunner.cpp =====================
