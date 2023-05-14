#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>

#include "Searchable.h"


using namespace std;

template<class T, class Enable = enable_if<is_base_of<Searchable, T>::value>>
void searchPrintResults(vector<T*> objectsList) {
	string search;
	char input;

	while (input = _getch()) {
		system("CLS");
		if (input == '\b' && search.size() == 0) {}

		else if (input == '\b') {
			search.pop_back();
		}
		else {
			search.push_back(input);
		}
		cout << search;
		for (Searchable* s : objectsList) {
			if (s->isInName(search)) {
				cout << '\n' << s->searchedName() << " -> " << s->searchedIdentifier();
			}
			
			if (s->isInIdentifier(atoi(search.c_str()))) {
				cout << '\n' << s->searchedName() << " -> " << s->searchedIdentifier();
			}
		}
	}
}


