#ifndef CUSTOMERBASE_H
#define CUSTOMERBASE_H

#include <sstream>
#include <fstream>
#include <iostream>
#include "Customer.h"

using namespace std;

class CustomerBase
{
	private:
		const static int MAX_SIZE = 50;
		Customer* customers[MAX_SIZE];
		int size;
		
	public:
		CustomerBase();
		~CustomerBase();
		CustomerBase(const CustomerBase&);
		const CustomerBase operator=(const CustomerBase&);
		void addCustomer(string, string, string, double, double, double);
		Customer* getCustomer(string = "");
		Customer* getCustomer(int = 0);
		string toString();
};

#endif
