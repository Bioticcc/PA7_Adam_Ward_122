#ifndef STACK_H
#define STACK_H

#include "Header.h"
//#include "Data.h"

#pragma once

class Stack {

private:
	vector<string> datesVect;

public:

	Stack() = default;

	Stack(const Stack& t) {
		datesVect = t.datesVect;
	};

	void addDate(string& date) {
		datesVect.push_back(date);
	};

	//getter
	vector<string> getDatesVect() {
		return datesVect;
	};

	friend Data;
};


#endif // STACK_H