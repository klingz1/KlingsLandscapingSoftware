#ifndef HOURLY_H
#define HOURLY_H

#include <sstream>
#include <string>
#include "Customer.h"
#include "Job.h"

class Hourly : public Job
{
	private:
		string hours;				// Hours spent on this Hourly Job
		double rate;				// Dollar rate per hour
		
	public:
		Hourly(string, double, string, Customer*, bool, double, string = "", double = 0.0);
		string toString();
};

#endif
