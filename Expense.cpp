#include "Expense.h"

Expense::Expense(string d, double pr, string des, string who) : Record(d, pr, des)
{
	toWho = who.erase(0, who.find_first_not_of(' '));
	toWho = toWho.erase(toWho.find_last_not_of("\n")+1);
}

string Expense::toString()
{
	ostringstream os;
	os << Record::toString() << ", " << toWho;
	return os.str();
}
