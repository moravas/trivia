﻿// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#include "Game.h"

#include <stdlib.h>

static bool notAWinner;

int main()
{
    Game aGame;

    aGame.add("Chet");
    aGame.add("Pat");
    aGame.add("Sue");

    do
    {

	aGame.roll(rand() % 5 + 1);

	if (rand() % 9 == 7)
	{
	    notAWinner = aGame.wrongAnswer();
	}
	else
	{
	    notAWinner = aGame.wasCorrectlyAnswered();
	}
    } while (notAWinner);

}
// =============================================================================
//! \file
//! \copyright
// =========================== end of file: GameRunner.cpp =====================
