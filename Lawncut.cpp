#include "Lawncut.h"

Lawncut::Lawncut(string da, double pr, string des, Customer* cust, bool pa, double amtPa, int days) : Job(da, pr, des, cust, pa, amtPa)
{
	daysSince = days;
}

string Lawncut::toString()
{
	ostringstream os;
	os << Job::toString() << ", " << daysSince;
	return os.str();
}
