// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#ifndef QUESTION_TYPE_H_
#define QUESTION_TYPE_H_
#include <string>
#include <ostream>

enum class QuestionType {
    Pop,
    Science,
    Sports,
    Rock
};

// =============================================================================
// Inline method implementation
// =============================================================================
inline std::ostream& operator<< (std::ostream& out, QuestionType type) {
    switch (type) {
	case QuestionType::Pop:
	    out << "Pop";
	    break;
	case QuestionType::Science:
	    out << "Science";
	    break;
	case QuestionType::Sports:
	    out << "Sports";
	    break;
	case QuestionType::Rock:
	    out << "Rock";
	    break;
	default:
	    out << "Unknown";
	    break;
    }

    return out;
}

#endif // QUESTION_TYPE_H_
// =============================================================================
//! \file
//! \copyright
// ======================= end of file: QuestionType.hpp =======================
