#include "Record.h"

#include <iostream>

Record::Record(string d, double pr, string des)
{
	date = d.erase(0, d.find_first_not_of("\n"));
	price = pr;
	description = des.erase(0, des.find_first_not_of(' '));
}

string Record::toString()
{
	ostringstream os;
	os << date << ", " << price << ", " << description;
	return os.str();
}
