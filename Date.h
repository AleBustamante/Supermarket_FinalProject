#pragma once
#include <iostream>



using namespace std;

class Date
{
public:
	int day;
	int month;
	int year;

	friend ostream& operator<<(ostream& output, const Date& date);
};

