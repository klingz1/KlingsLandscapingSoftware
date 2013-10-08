#ifndef EXPENSE_H
#define EXPENSE_H

#include "Record.h"
#include <sstream>
#include <string>

using namespace std;

class Expense : public Record
{
	private:
		string toWho;				// Who the expense was paid to
		
	public:
		Expense(string, double, string, string = "");
		string toString();
};

#endif
