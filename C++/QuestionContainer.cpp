// =============================================================================
//! \file
//! \brief
//! \author
//! \date
//! \note
// =============================================================================
#include "QuestionContainer.h"
#include "QuestionType.h"

#include <sstream>
#include <iostream>

using namespace std;

void QuestionContainer::Take(QuestionType type) {
    auto it = _questions.find(type);
    cout << it->second.front() << endl;
    it->second.pop_front();
}

void QuestionContainer::Add(QuestionType type, unsigned int count) {
	uint32_t index = 0;
	list<string> questions(count);
	for(auto& item: questions) {
	    stringstream s;
	    s << type << " Question " << index++;
	    item = s.str();
	}

	_questions[type] = questions;
}

// =============================================================================
//! \file
//! \copyright
// ==================== end of file: QuestionContainer.cpp =====================
