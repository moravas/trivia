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

    Game game;
    game.Add("Chet");
    game.Add("Pat");
    game.Add("Sue");

    do {
	game.Roll(question);
    } while(game.CheckAnswer());

    return 0;
}

// =============================================================================
//! \file
//! \copyright
// =========================== end of file: GameRunner.cpp =====================
