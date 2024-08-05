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
	NodeT<T>* importCsv(string fileName) {
		//stores read data to be inserted into list
		T record; 
		//opening csv
		ifstream input;
		input.open(fileName, 'r');
		//reading csv and saving to string
		string line;
		getline(input, line); //skipping first line

		while (getline(input, line)) {
			
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

	void printList() {
		NodeT<T>*curr = headPtr;
		while (curr!=nullptr) {
			cout <<"num: " << curr->data.getRecordNumber() << std::endl;
			curr = curr->next;
		}
	}

	
};


#endif