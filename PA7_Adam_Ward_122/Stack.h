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

	//push()
	void push(string& date) {
		datesVect.push_back(date);
	};

	//pop()
	void pop() {
		datesVect.pop_back();
	}
	
	//peek()
	string peek() {
		return datesVect.back();
	}

	//isempty()
	int isEmpty() {
		if (datesVect.empty()) { return 1; }
		else return 0;
	}

	//getter
	vector<string> getDatesVect() {
		return datesVect;
	};

	//friend Data; //dunno if this is needed but I think i recall this being helpful a couple PA's ago, so why not 
};


#endif 