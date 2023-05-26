#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>

#include "Searchable.h"
#include "PrintToConsole.h"
#include "PrintToConsole.h"

using namespace std;


enum SearchType{
	product,
	client,
	worker
};

template<class T, class Enable = enable_if<is_base_of<Searchable, T>::value>>
void searchPrintResults(vector<T*> objectsList, const char& input, string& search, Searchable*& object) {
	bool objectFound = false;
	
	print::setCursorToInputPos();
	if (input == '\b' && search.size() == 0) {}

	else if (input == '\b') {
		search.pop_back();
	}
	else {
		search.push_back(input);
	}
	cout << search;
	print::setCursorToOutputPos();
	for (Searchable* s : objectsList) {
		if (s->isInName(search)) {
			cout << '\n' << s->searchedName() << " -> " << s->searchedIdentifier();
			if (!objectFound) {
				object = s;
				objectFound = true;
			}
		}

		if (s->isInIdentifier(atoi(search.c_str()))) { //CAREFULL, this double conversion results in search = "0" Forbidden use of 0 as ID
			cout << '\n' << s->searchedName() << " -> " << s->searchedIdentifier();
			if (!objectFound) {
				object = s;
				objectFound = true;
			}
		}
	}
}


