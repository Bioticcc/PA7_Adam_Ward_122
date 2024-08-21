#ifndef MENU_H
#define MENU_H

#include "Header.h"
#include "ListT.h"

#pragma once

class Menu
{
private:

	int choice;
	ListT<Data> list;

public:


	Menu() : choice(0) {}

	int getChoice() {
		fflush(stdin);
		int choice = 0;
		cout << "| Attendance! The best time of year! |\n";
		cout << "| (1) Import Course List\n";
		cout << "| (2) Load Master List\n";
		cout << "| (3) Store Master List\n";
		cout << "| (4) Mark Absences\n";
		cout << "| (5) Edit Absences\n";
		cout << "| (6) Generate Report\n";
		cout << "| (7) Exit\n";
		cout << "|(1-7): ";
		cin >> choice;
		return choice;
	}

	int getChoice2() {
		system("cls");
		cout << "| Attendance! The best time of year! |\n";
		cout << "| (1) Import Course List\n";
		cout << "| (2) Load Master List\n";
		cout << "| (3) Store Master List\n";
		cout << "| (4) Mark Absences\n";
		cout << "| (5) Edit Absences\n";
		cout << "| (6) Generate Report\n";
		cout << "|    (6.1) Generate Report for all Students\n";
		cout << "|    (6.2) Generate Report for all Students of Specified Absences\n";
		cout << "| (7) Exit\n";
		cout << "|(1-2): ";
		cin >> choice;
		return choice;
	}

	int markAbsences(ListT<Data> list) {
		//given code by assignment. what does it do? f*ck if i know lol
		time_t t = time(0); // get time now
		struct tm* now = localtime(&t);
		cout << "CURRENT DATE: " << (now->tm_year + 1900) << '-'
			<< (now->tm_mon + 1) << '-'
			<< now->tm_mday
			<< endl;

		//jesus christ how do I make this amalgamation above me into a single string???? this is HORRID (will take 5 minutes)
		string timeSTR = "";
		timeSTR.append(std::to_string(now->tm_year + 1900));
		timeSTR.append("-");
		timeSTR.append(std::to_string(now->tm_mon + 1));
		timeSTR.append("-");
		timeSTR.append(std::to_string(now->tm_mday));
		
		//traversing list and asking if student is marked absent, yae or nae
		NodeT<Data>* curr = list.headPtr;
		char a;
		while (curr != nullptr) {

			cout << "|STUDENT: " << curr->data.getName() << "\n|ID: " << curr->data.getID() << "\n";
			cout << "Absent? (Y/N)";
			cin >> a;

			if (a == 'Y' || a == 'y') {
				//student was indeed absent! 
				//we now increase that students data.numAbsences by 1, as well as logging the date of absence in Stack datesOfAbsences
				curr->data.setNumAbsences(1); //doesnt actually set it to 1, but increase the counter by the number given.
				curr->data.setDateOfAbsence(timeSTR);
			}

			curr = curr->next;
		}
		return 1;
	}

	NodeT<Data>* importMaster(string fileName) {
		//free(list.headPtr);
		if (list.headPtr != nullptr) {
			list.headPtr = list.deleteList();
		}
		Data record; vector<string> tokens;
		string token, line, name;
		int token1;
		ifstream input(fileName);
		while (!input.eof()) {
			name = "";
			tokens.clear();
			getline(input, line);
			if (line == "") {
				break;
			}
			std::istringstream s(line);
			for (int i = 0; i < 9; i++) {
				getline(s, token, ',');
				size_t pos;
				tokens.push_back(token);
				switch (i)
				{
				case 0:
					token1 = std::stoi(token);
					record.setRecordNumber(token1);

					line.erase(line.find(token), token.length());
					break;
				case 1:

					token1 = std::stoi(token);
					record.setID(token1);
					line.erase(line.find(token), token.length());
					break;
				case 2:
					name.append(token);
					name.append(", ");
					line.erase(line.find(token), token.length());
					break;
				case 3:
					name.append(token);
					record.setName(name);
					line.erase(line.find(token), token.length());
					break;
				case 4:
					record.setEmail(token);
					line.erase(line.find(token), token.length());
					break;
				case 5:
					record.setUnits(token);
					line.erase(line.find(token), token.length());
					break;
				case 6:
					record.setProgram(token);
					line.erase(line.find(token), token.length());
					break;

				case 7:
					record.setLevel(token);
					line.erase(line.find(token), token.length());
					break;
				case 8:
					record.setNumAbsences(stoi(token));
					line.erase(line.find(token), token.length());
					break;
				}

			}
			line.erase(0, 9);
			std::stringstream ss(line);
			string tok;

			while (getline(ss, tok, ' ')) {
				record.setDateOfAbsence(tok); //oops gotta split this up and thats gonna require actual effort :( sadge
			}
			list.headPtr = list.insert(list.headPtr, record);
		}
		return list.headPtr;
	}

	NodeT<Data>* loadMaster(string fileName) {
		ifstream input(fileName);
		string line;
		if (!getline(input, line)) {
			cout << "No previously saved master list!\n";
			input.close();
			return list.headPtr;
		}
		else {
			//list.importCsv("master.csv"); AGH I NEED TO MAKE ANOTHER ONE (I realize I could just edit importCsv, but 
			//too be entirely honest with you it would look ugly and take a lot longer so im gonna just do the boring easy route 
			list.headPtr = importMaster("master.csv");

			/*NodeT<Data>* curr = list.headPtr;
			cout << "TEST: " << curr->data.datesOfAbsences.peek();
			IT WORKS RAHHHHHHHHHHHHH (I was expecting this to be a weekend long thing but NAY)*/
			input.close();
			return list.headPtr;
		}
	}

	int storeMaster(string fileName) {
		ofstream output(fileName);
		string line;
		NodeT<Data>* curr = list.headPtr;

		while (curr != nullptr) {
			output << curr->data.getRecordNumber() << ",";
			output << curr->data.getID() << ",";
			output << curr->data.getName() << ",";
			output << curr->data.getEmail() << ",";
			output << curr->data.getUnits() << ",";
			output << curr->data.getProgram() << ",";
			output << curr->data.getLevel() << ",";
			output << curr->data.getNumAbsences() << ",";
			vector<string> dates = curr->data.getDatesOfAbsences();
			for (int i = 0; i<dates.size(); i++) {
				output << dates[i] << " ";
			}
			output << endl;
			curr = curr->next;
		}
		output.close();
		return 1;

	}

	int generateReport() {
		int choice = getChoice2();
		if (choice == 1) {
			//all students, using .peek() to see most recent absence for each
			system("cls");
			cout << "|VIEWING REPORT: All Students, Most Recent Absence:\n\n";

			NodeT<Data>* curr = list.headPtr;
			while (curr != nullptr) {
				if (curr->data.datesOfAbsences.peek() != "") {
					cout << "|Student: " << curr->data.getName() << "\n";
					cout << "|---->Last Absence: " << curr->data.datesOfAbsences.peek() << "\n";
					cout << "|---->Total Absences: " << curr->data.getNumAbsences() << "\n";
					cout << "|------------------------------------------->\n\n";
					curr = curr->next;
				}
			}
		}
		else if (choice == 2) {
			//all students with absences that match or exceed given x
			int i = 0;
			cout << "|VIEWING REPORT: All Students, Specified Absence Threshold (Enter Absence Threshold): ";
			cin >> i;
			NodeT<Data>* curr = list.headPtr;
			while (curr != nullptr) {
				if (curr->data.getNumAbsences() >= i) {
					cout << "|Student: " << curr->data.getName() << "\n";
					cout << "|---->Number of absences: " << curr->data.getNumAbsences() << "\n";
				}
				curr = curr->next;
			}
		}
		return 1;
	}

	int runProgram() {
		while (1) {
			system("cls");
			choice = getChoice();
			switch (choice) {
			case 1:
				//load list (read from classList.csv)
				//list.headPtr = list.deleteList();
				list.importCsv("classList.csv");
				break;
			case 2:
				//load master list (read from master.csv into linked list? or completely seperate list idk)
				list.headPtr = loadMaster("master.csv");
				break;
			case 3:
				//store master list (write to master.csv from linked list or completely sepereate list idk)
				storeMaster("master.csv");
				break;
			case 4:
				//goes through master list, printing info and giving option to mark each student present or absent as well as the current day
				markAbsences(list);
				//list.printList();
				break;
			case 5:
				list.printList();
				//extra credit: lets ya edit current lists students as well as their absences! pretty easy imo but i gotta make the rest of this work first lmao
				break;
			case 6:
				generateReport();
				//generates report of the absent students, and the REALLY absent students
				break;
			case 7:
				exit(1);
				break;
			//default:
				//cout << "\nError, invalid input.\n";
				//break;
			}
			system("pause");
		}
	}

};

#endif

