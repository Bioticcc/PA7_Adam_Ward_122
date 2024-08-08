#ifndef LISTT_H
#define LISTT_H

#include "Header.h"
#include "NodeT.h"

#pragma once
template <typename T>
class ListT
{
private:

public:
	NodeT<T>* headPtr;
	ListT() : headPtr(nullptr) {}



	//insert function
	NodeT<T>* insert(NodeT<T>* headPtr, T& data) {
		NodeT<T>* newNode = new NodeT<T>(data);
	
		if (!headPtr) {
			//list empty, dont update next
			headPtr = newNode;
			return headPtr;
		}
		else {
			//list not empty, update next
			newNode->next = headPtr;
			headPtr = newNode;
			return headPtr;
		}
	}


	NodeT<T>* importCsv(string fileName) {
		T record; //for storing read data before inserting into list
		vector<string> tokens; //for storing read words before inserting into record
		string token; //for stori- blah blah you get the point lol
		string line; // ^
		string name;
		int token1;
		ifstream input(fileName); 
		getline(input, line); //skipping header

		while (!input.eof()) {
			name = "";
			tokens.clear(); //resetting vector every record
			getline(input, line);
			if (line == "") {
				break;
			}
			std::istringstream s(line);
			for (int i = 0; i < 7; i++) {
				//looping through vector 
				getline(s, token, ',');
				size_t pos;
				tokens.push_back(token);
				switch (i)
				{
				case 0:
					//cout << token << "|i: " << i << endl;
					token1 = std::stoi(token);
					record.setRecordNumber(token1);

					line.erase(line.find(token), token.length()); //im kind of a genius for this one tbh let me cook youll see
					break;
				case 1:
					//cout << token << "|i: " << i << endl;
					token1 = std::stoi(token);
					record.setID(token1);
					line.erase(line.find(token), token.length());
					break;
				case 2:
					//cout << token << "|i: " << i << endl;
					name.append(token);
					name.append(", ");
					line.erase(line.find(token), token.length());
					break;
				case 3:
					//cout << token << "|i: " << i << endl;
					//add last name to first
					name.append(token);
					record.setName(name);
					line.erase(line.find(token), token.length());
					break;
				case 4:
					//cout << token << "|i: " << i << endl;
					record.setEmail(token);
					line.erase(line.find(token), token.length());
					break;
				case 5:
					//cout << token << "|i: " << i << endl;
					record.setUnits(token); //ah this the problem child, gotta swap up somethings in setUnits! weeee->
					line.erase(line.find(token), token.length());
					break;
				case 6:
					//cout << token << "|i: " << i << endl;
					record.setProgram(token);
					line.erase(line.find(token), token.length());
					break;
				}
			}
			//and now that weve removed everything in the original getline() string, it should ONLY be the final field in the record,
			//notably the one without the comma delimeter! >:)
			line.erase(0, 7);
			record.setLevel(line);

			//cout << line << "\n\n\n";

			//TO THE ME OF TOMMOROW: THE PROBLEM IS SOMETIMES THE UNIT IS NOT AN INTEGER! MAKE IT CHECK IF ITS A INTEGER OR STRING
			//TO THE ME OF THE PAST: o7

			//inserting to list:
			headPtr = insert(headPtr, record);
		}


		return headPtr;

	}


	void printList() {
		//cout << "test";
		NodeT<T>*curr = headPtr;
		cout << "Record Num, ID, Name, Email, Units, Program, Level \n";

		while (curr!=nullptr) 	{	
			cout << " " << curr->data.getRecordNumber();
			cout << ", " << curr->data.getID();
			cout << ", " << curr->data.getName();
			cout << ", " << curr->data.getEmail();
			cout << ", " << curr->data.getUnits();
			cout << ", " << curr->data.getProgram();
			cout << ", " << curr->data.getLevel();
			cout << std::endl;
			curr = curr->next;
		}
	}

};


#endif