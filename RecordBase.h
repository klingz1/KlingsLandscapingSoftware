#ifndef RECORDBASE_H
#define RECORDBASE_H

#include <iostream>
#include <fstream>
#include "Record.h"
#include "Expense.h"
#include "Lawncut.h"
#include "Hourly.h"
#include "CustomerBase.h"

class RecordBase
{
	private:
		const static int MAX_SIZE = 2000;
		Record* records[MAX_SIZE];
		CustomerBase customerBase;
		int totalSize;
		int numExpenses;
		int numHourlys;
		int numLawncuts;
		
	public:
		RecordBase();
		~RecordBase();
		RecordBase(const RecordBase&);
		const RecordBase operator=(const RecordBase&);
		CustomerBase getCustomerBase();
		void addRecord(string, double, string, Customer*, bool, double, string, double);		// Hourly
		void addRecord(string, double, string, Customer*, bool, double, int);					// Lawncut
		void addRecord(string, double, string, string);											// Expense
		string getHourlys();
		string getLawncuts();
		string getExpenses();
		string toString();
};

#endif
