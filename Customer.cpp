#include "Customer.h"

Customer::Customer(string n, string a, string ph, double pr, double o, double pa)
{
	name = n.erase(0, n.find_first_not_of("\n"));
	address = a.erase(0, a.find_first_not_of(' '));
	phone = ph.erase(0, ph.find_first_not_of(' '));
	owed = o;
	price = pr;
	paid = pa;
}

string Customer::toString()
{
	ostringstream os;
	os << name << ", " << address << ", " << phone << ", " << price << ", " << owed << ", " << paid;
	return os.str();
}
