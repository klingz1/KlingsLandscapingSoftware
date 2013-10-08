#include "CustomerBase.h"

CustomerBase::CustomerBase()
{
	size = 0;
	
	ifstream inputStream;
	inputStream.open("customers.csv");
	if(!inputStream.fail())
	{
		cout << "Customers file opened successfully" << endl;
		
		string title;
		getline(inputStream, title);
		
		while(!inputStream.eof())
		{
			string name;
			getline(inputStream, name, ',');
			
			string address;
			getline(inputStream, address, ',');
			
			string phone;
			getline(inputStream, phone, ',');
			
			string pr = "";
			getline(inputStream, pr, ',');
			double price = 0.0;
			stringstream ssPrice(pr);
			ssPrice >> price;
			
			string ow = "";
			getline(inputStream, ow, ',');
			double owed = 0.0;
			stringstream ssOwed(ow);
			ssOwed >> owed;
			
			string pa = "";
			getline(inputStream, pa, ',');
			double paid = 0.0;
			stringstream ssPaid(pa);
			ssPaid >> paid;
			
			addCustomer(name, address, phone, price, owed, paid);
		}
	}
	else
		cout << "Customers file failed to open" << endl;
	inputStream.close();
}

CustomerBase::~CustomerBase()
{
	ofstream outputStream;
	outputStream.open("customersOut.csv");
	if(!outputStream.fail())
	{
		outputStream << "Name, Address, Phone Number, Price, Owed, Paid" << endl
					 << toString();
		cout << "Customers output complete" << endl;
	}
	else
		cout << "Customers output failed" << endl;
	outputStream.close();
	
	for(int i = 0; i < size; i++)
		delete customers[i];
}

CustomerBase::CustomerBase(const CustomerBase& rhs)
{
	size = rhs.size;
	for(int i = 0; i < size; i++)
		customers[i] = rhs.customers[i];
}

const CustomerBase CustomerBase::operator=(const CustomerBase& rhs)
{
	size = rhs.size;
	for(int i = 0; i < size; i++)
		customers[i] = rhs.customers[i];
	return *this;
}

void CustomerBase::addCustomer(string n, string a, string ph, double pr, double o, double pa)
{
	size++;
	
	if(size < MAX_SIZE)
		customers[size - 1] = new Customer(n, a, ph, pr, o, pa);
}

Customer* CustomerBase::getCustomer(int i)
{
	return customers[i];
}

Customer* CustomerBase::getCustomer(string crit)
{
	Customer* result = NULL;
	for(int i = 0; i < size; i++)
	{
		if(customers[i] -> getName() == crit)
			return customers[i];
		if(customers[i] -> getAddress() == crit)
			return customers[i];
		if(customers[i] -> getPhone() == crit)
			return customers[i];
	}
	return NULL;
}

string CustomerBase::toString()
{
	ostringstream os;	
	
	for(int i = 0; i < size; i++)
		if(i != size - 1)
			os << customers[i] -> toString() << ",\n";
		else if(i == size - 1)
			os << customers[i] -> toString();
	
	return os.str();
}
