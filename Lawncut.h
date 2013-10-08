#ifndef LAWNCUT_H
#define LAWNCUT_H

#include "Job.h"
#include "Customer.h"
#include <sstream>
#include <string>

using namespace std;

class Lawncut : public Job
{
	private:
		int daysSince;				// Days Since this cut
		
	public:
		Lawncut(string, double, string, Customer*, bool, double, int = 0);
		string toString();
};

#endif
