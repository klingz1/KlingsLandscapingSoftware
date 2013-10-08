#include "Hourly.h"

Hourly::Hourly(string da, double pr, string des, Customer* cust, bool pa, double amtPa, string hrs, double ra) : Job(da, pr, des, cust, pa, amtPa)
{
	hours = hrs;
	rate = ra;
}

string Hourly::toString()
{
	ostringstream os;
	
	os << Job::toString() << ", " << hours << ", " << rate;
	return os.str();
}
