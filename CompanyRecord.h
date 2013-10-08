#ifndef COMPANYRECORD_H
#define COMPANYRECORD_H

#include "RecordBase.h"
#include "CustomerBase.h"

class CompanyRecord
{
	private:
		RecordBase recordBase;
		
	public:
		CompanyRecord(){}
		RecordBase getRecordBase() { return recordBase; }
		CustomerBase getCustomerBase() { return recordBase.getCustomerBase(); }
		void addRecord(string date = "", double price = 0.0, string description = "", string custName = "", bool isPaid = false, double amtPaid = 0.0, string hours = "", double rate = 0.0);
		void addRecord(string date = "", double price = 0.0, string description = "", string custName = "", bool isPaid = false, double amtPaid = 0.0, int daysSince = 0);
		void addRecord(string date = "", double price = 0.0, string description = "", string who = "");
		void addCustomer(string name = "", string address = "", string phone = "", double price = 0.0, double owed = 0.0, double paid = 0.0);
		
};

#endif
