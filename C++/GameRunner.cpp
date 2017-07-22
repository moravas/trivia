// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#include "Game.h"
#include "QuestionContainer.h"
#include "QuestionType.h"

int main() {
    QuestionContainer question;
    question.Add(QuestionType::Pop, 50);
    question.Add(QuestionType::Science, 50);
    question.Add(QuestionType::Sports, 50);
    question.Add(QuestionType::Rock, 50);

    Game game(question);
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
