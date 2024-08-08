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

	int runProgram() {
		while (1) {
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
				list.printList();
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

