#ifndef JOB_H
#define JOB_H

#include <sstream>
#include <string>
#include "Record.h"
#include "Customer.h"

using namespace std;

class Job : public Record
{
	private:
		Customer* customer;			// Customer Assigned to this Job
		bool paid;					// True if paid for, false otherwise
		double amtPaid;				// Amount Paid towards this job
		
	public:
		Job(string, double, string, Customer* = NULL, bool = false, double = 0.0);
		virtual ~Job(){}
		virtual string toString();
};

#endif
