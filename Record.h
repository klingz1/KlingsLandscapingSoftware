#ifndef RECORD_H
#define RECORD_H

#include <sstream>
#include <string>

using namespace std;

class Record
{
	private:
		string date;				// Date of the Record
		double price;				// Price of the Record
		string description;			// Description of the Record
		
	public:
		Record(string = "", double = 0.0, string = "");
		virtual ~Record(){}
		virtual string toString();
};

#endif
