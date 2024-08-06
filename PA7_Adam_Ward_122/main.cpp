#include "Header.h";
#include "ListT.h"

int main(void) {

	/*
	Alriiiiight this one is a DOOZY, but like not really? idk doesnt seem that bad so far but I spose we shall see.
	Anywho, just putting this here so I dont have to keep alt-tabbing to the assignment and I know damn well I wont remember it 
	class:
	1. NODE class (template)
	2. LIST class (template of type node(T))
	3. DATA class (NOT template!)
	4. STACK class (NOT template but uhhhhh what does this one even do??? who knows we will get to it when we get to it i guess)
	For now just gonna make these 4, get the .csv imported into my linked list and get that workin before I continue with anything else! ;3
	*/
	//Data data;
	//NodeT<Data> headPtr(data);
	ListT<Data> list;
	list.importCsv("classList.csv");
	//list.printList();


}
