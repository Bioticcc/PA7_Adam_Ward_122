#ifndef DATA_H
#define DATA_H

#include "Header.h"
#include "Stack.h"

//allright, lets try make these classes a bit cleaner, ey? previous assignments have been UGLY tbh
#pragma once
class Data {
private:
	int recordNumber;
	int ID;
	int units;

	string name;
	string email;
	string program;
	string level; 

	//extra additions involving stack class
	int numAbsences;
	Stack datesOfAbsences;
public:
	//default constructor:
	Data() : recordNumber(0), ID(0), units(0), name("none"), email("none"), program("none"), level("none"), numAbsences(0),datesOfAbsences() {}

	//copy constructor:
	Data(const Data& t) {
		recordNumber = t.recordNumber;
		ID = t.ID;
		units = t.units;
		name = t.name;
		email = t.email;
		program = t.program;
		level = t.level;
		numAbsences = t.numAbsences;
		Stack datesOfAbsences(t.datesOfAbsences); //i think this works for copy? i never use it anyway, but im a bit concerned.
	}

	//deconstructor:
	~Data() {}

	//getters
	int getRecordNumber() {return recordNumber;}
	int getID() { return ID; }
	int getUnits() { return units; }
	string getName() { return name; }
	string getEmail() { return email; }
	string getProgram() { return program; }
	string getLevel() { return level; }
	int getNumAbsences() { return numAbsences; }


	//setters
	void setRecordNumber(int t) {recordNumber = t;}
	void setID(int t) { ID = t; }
	void setUnits(int t) { units = t; }
	void setName(string t) { name = t; }
	void setEmail(string t) { email = t; }
	void setProgram(string t) { program = t; }
	void setLevel(string t) { level = t; }
	void setNumAbsences(int t) { numAbsences = t; }

};



#endif

