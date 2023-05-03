#include "Date.h"

ostream& operator<<(ostream& output, const Date& date){
	output << date.day << "/" << date.month << "/" << date.year;
	return output;
}
