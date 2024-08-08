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
		//traversing list and asking if student is marke absent, yae or nae
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

	int runProgram() {
		while (1) {
			system("cls");
			getChoice();
			switch (choice) {
			case 1:
				//load list (read from classList.csv)
				list.importCsv("classList.csv");
				break;
			case 2:
				//load master list (read from master.csv into linked list? or completely seperate list idk)
				break;
			case 3:
				//store master list (write to master.csv from linked list or completely sepereate list idk)
			case 4:
				//goes through master list, printing info and giving option to mark each student present or absent as well as the current day
				markAbsences(list);
				//list.printList();
				break;
			case 5:
				//extra credit: lets ya edit current lists students as well as their absences! pretty easy imo but i gotta make the rest of this work first lmao
				break;
			case 6:
				//generates report of the absent students, and the REALLY absent students
				break;
			case 7:
				exit(1);
			
			
			}
			
		}
	}

};

#endif

