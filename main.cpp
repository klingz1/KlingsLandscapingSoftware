#include <iostream>
#include "CompanyRecord.h"

using namespace std;

int main()
{	
	CompanyRecord companyRecord;
	//companyRecord.getCustomerBase();
	//companyRecord.getRecordBase();
	
	/**
	cout << customerBase.getCustomer("Fred") -> getPrice();
	cout << customerBase.getCustomer("14 William st") -> getPrice();
	cout << customerBase.getCustomer(0) -> getName();
	cout << customerBase.getCustomer(3) -> getName();
	
	int total = 0;
	for(int i = 0; i < customerBase.getSize(); i++)
		total += customerBase.getCustomerByIndex(i) -> getPrice();
	cout << "The total is: " << total << endl;
	*/
	
	//if(customerBase.getCustomerByName("Ryan and Lisa") != NULL)
	//	cout << customerBase.getCustomerByName("Ryan and Lisa") -> toString() << endl;
	
	//for(int i = 0; i < customerBase.getSize(); i++)
	//	cout << customerBase.getCustomerByIndex(i) -> toString() << endl;
	
	//cout << customerBase.toString();
	
	
	// Record base filling complete	
	// Display menu options
	// 1. Edit information for a customer
	// 2. Edit information for a record
	// 3. Search for customer information by all attributes
	// 4. Search for record information by all attributes
	// 5. Sort customers by all criteria
	// 6. Sort records by all criteria
	
	// Before exiting program, update info by pushing to output file
	
/**
	outputStream.open("expensesOut.csv");
	if(!outputStream.fail())
	{
		outputStream << "Date, Price, Description, To Who" << endl
					 << recordBase.getExpenses();
		cout << "Expenses output complete" << endl;
	}
	else
		return 1;
	outputStream.close();
	
	outputStream.open("lawncutsOut.csv");
	if(!outputStream.fail())
	{
		outputStream << "Date, Price, Description, Customer Name, isPaid, Amount Paid, Days Since" << endl
					 << recordBase.getLawncuts();
		cout << "Lawncuts output complete" << endl;
	}
	else
		return 1;
	outputStream.close();

	outputStream.open("hourlysOut.csv");
	if(!outputStream.fail())
	{
		outputStream << "Date, Price, Description, Customer Name, isPaid, Amount Paid, Hours, Rate" << endl
					 << recordBase.getHourlys();
		cout << "Hourlys output complete" << endl;
	}
	else
		return 1;
	outputStream.close();
*/
}
