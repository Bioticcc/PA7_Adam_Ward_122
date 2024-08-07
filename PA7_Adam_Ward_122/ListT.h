#ifndef LISTT_H
#define LISTT_H

#include "Header.h"
#include "NodeT.h"

#pragma once
template <typename T>
class ListT
{
private:
	NodeT<T>* headPtr;

public:
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



	//read function, will read in data for newNode, then call insert and add it to the linked list!
	/*NodeT<T>* importCsv(string fileName) {
		//cout << "test1\n";
		//stores read data to be inserted into list
		T record; 
		//opening csv
		//ifstream input.open(fileName, 'r');
		ifstream input(fileName);

		//if (input.is_open()) { cout << "test2\n"; }
		//else cout << "test3\n";
		//cout << "test2.5\n";

		//reading csv and saving to string

		string line;
		getline(input, line); //skipping first line
		cout << "Header: Number" << line << "\n";
		//cout << "test5\n";

		
		while (getline(input, line)) {
			//cout << "test5.5";
			//cout << line;
			std::istringstream parse(line);
			int n1, n2, n3;
			string s1, s2, s3, s4;
			parse >> n1 >> n2 >> s1 >> s2 >> n3 >> s3 >> s4;
			record.setRecordNumber(n1);
			record.setID(n2);
			record.setName(s1);
			record.setEmail(s2);
			record.setUnits(n3);
			record.setProgram(s3);
			record.setLevel(s4);

			headPtr = insert(headPtr, record);
		}
		return headPtr;
	}

	*/

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
			tokens.clear(); //resetting vector every record
			getline(input, line);
			std::istringstream s(line);
			for (int i = 0; i < 7; i++) {
				//looping through vector 
				getline(s, token, ',');
				size_t pos;
				tokens.push_back(token);
				switch (i)
				{
				case 0:
					cout << token << "|i: " << i << endl;
					token1 = std::stoi(token);
					record.setRecordNumber(token1);

					line.erase(line.find(token), token.length()); //im kind of a genius for this one tbh let me cook youll see
					break;
				case 1:
					cout << token << "|i: " << i << endl;
					token1 = std::stoi(token);
					record.setID(token1);
					line.erase(line.find(token), token.length());
					break;
				case 2:
					cout << token << "|i: " << i << endl;
					name.append(token);
					line.erase(line.find(token), token.length());
					break;
				case 3:
					cout << token << "|i: " << i << endl;
					//add last name to first
					name.append(token);
					record.setName(token);
					line.erase(line.find(token), token.length());
					break;
				case 4:
					cout << token << "|i: " << i << endl;
					record.setEmail(token);
					line.erase(line.find(token), token.length());
					break;
				case 5:
					cout << token << "|i: " << i << endl;
					token1 = std::stoi(token);
					record.setUnits(token1);
					line.erase(line.find(token), token.length());
					break;
				case 6:
					cout << token << "|i: " << i << endl;
					record.setProgram(token);
					line.erase(line.find(token), token.length());
					break;
				}
			}
			//and now that weve removed everything in the original getline() string, it should ONLY be the final field in the record,
			//notably the one without the comma delimeter! >:)
			line.erase(0, 7);
			record.setLevel(line);

			cout << line << "\n\n\n";

			//TO THE ME OF TOMMOROW: THE PROBLEM IS SOMETIMES THE UNIT IS NOT AN INTEGER! MAKE IT CHECK IF ITS A INTEGER OR STRING
		}
		return headPtr;

	}


	void printList() {
		NodeT<T>*curr = headPtr;
		while (curr!=nullptr) {
			cout << "num: " << curr->data.getRecordNumber() << curr->data.getID() << curr->data.getName() << "\n";
			//cout << curr->data.getEmail() << curr->data.getUnits() << curr->data.getProgram() << curr->data.getLevel() << std::endl;
			curr = curr->next;
		}
	}

	
};


#endif