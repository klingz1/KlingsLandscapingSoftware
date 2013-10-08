#include "Job.h"

Job::Job(string d, double pr, string des, Customer* cust, bool pa, double amtPa) : Record(d, pr, des)
{
	customer = cust;
	paid = pa;
	amtPaid = amtPa;
}

string Job::toString()
{
	ostringstream os;
	
	os << Record::toString();
	if(customer != NULL)
		os << ", " << customer -> getName();
	
	if(paid == true)
		os << ", true";
	else
		os << ", false";
		
	os << ", " << amtPaid;
	
	return os.str();
}
