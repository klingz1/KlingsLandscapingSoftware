#include "CompanyRecord.h"

void CompanyRecord::addRecord(string date, double price, string description, string custName, bool isPaid, double amtPaid, string hours, double rate)
{
     recordBase.addRecord(date, price, description, recordBase.getCustomerBase().getCustomer(custName), isPaid, amtPaid, hours, rate);
}

void CompanyRecord::addRecord(string date, double price, string description, string custName, bool isPaid, double amtPaid, int daysSince)
{
     recordBase.addRecord(date, price, description, recordBase.getCustomerBase().getCustomer(custName), isPaid, amtPaid, daysSince);
}

void CompanyRecord::addRecord(string date, double price, string description, string who)
{
     recordBase.addRecord(date, price, description, who);
}

void CompanyRecord::addCustomer(string name, string address, string phone, double price, double owed, double paid)
{
     recordBase.getCustomerBase().addCustomer(name, address, phone, price, owed, paid);
}
