#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <sstream>
#include <string>

//Includes Current Date at runtime and and attribute named daysSince which holds the number of days since the last cut

using namespace std;

class Customer
{
	private:
		string name;			// Name of Customer
		string address;			// Address of Customer
		string phone;			// Phone Number of Customer
		double price;			// Normal Price for Full Cut
		double owed;			// Amount Owed Currently
		double paid;			// Total Amount Paid
		
	public:
		Customer(string = "", string = "", string = "", double = 0.0, double = 0.0, double = 0.0);
		string toString();
		
		string getName() { return name; }
		string getAddress() { return address; }
		string getPhone() { return phone; }
		double getPrice() { return price; }
		double getOwed() { return owed; }
		double getPaid() { return paid; }
		
		void setName(string n = "") { name = n; }
		void setAddress(string a = "") { address = a; }
		void setPhone(string p = "") { phone = p; }
		void setPrice(double p = 0.0) { price = p; }
		void setOwed(double o = 0.0) { owed = o; }
		void setPaid(double p = 0.0) { paid = p; }
};

#endif
