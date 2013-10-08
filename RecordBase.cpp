#include "RecordBase.h"

RecordBase::RecordBase()
{
	totalSize = 0;
	numExpenses = 0;
	numLawncuts = 0;
	numHourlys = 0;
	
	ifstream inputStream;
	inputStream.open("expenses.csv");
	if(!inputStream.fail())
	{
		cout << "Expenses file opened successfully" << endl;
		
		string title;
		getline(inputStream, title);
		
		while(!inputStream.eof())
		{
			string date;
			getline(inputStream, date, ',');
			
			string pr = "";
			getline(inputStream, pr, ',');
			double price = 0;
			stringstream ssPrice(pr);
			ssPrice >> price;
			
			string description;
			getline(inputStream, description, ',');
			
			string who;
			getline(inputStream, who, ',');
			who = who.erase(0, who.find_first_not_of(' '));
			
			addRecord(date, price, description, who);
		}
	}
	else
		cout << "Expenses file failed to open" << endl;
	inputStream.close();
	
	inputStream.open("lawncuts.csv");
	if(!inputStream.fail())
	{
		cout << "Lawncuts file opened successfully" << endl;
		
		string title;
		getline(inputStream, title);
		
		while(!inputStream.eof())
		{
			string date;
			getline(inputStream, date, ',');
			
			string pr = "";
			getline(inputStream, pr, ',');
			double price = 0;
			stringstream ssPrice(pr);
			ssPrice >> price;
			
			string description;
			getline(inputStream, description, ',');
			
			string name;
			getline(inputStream, name, ',');
			name = name.erase(0, name.find_first_not_of(' '));
			
			string pa = "";
			bool isPaid = false;
			getline(inputStream, pa, ',');
			if(pa == " true")
				isPaid = true;
				
			string p = "";
			getline(inputStream, p, ',');
			double amtPaid = 0;
			stringstream ssPaid(p);
			ssPaid >> amtPaid;
			
			string days = "";
			getline(inputStream, days, ',');
			double daysSince = 0;
			stringstream ssDays(days);
			ssDays >> daysSince;
			
			addRecord(date, price, description, customerBase.getCustomer(name), isPaid, amtPaid, daysSince);
		}
	}
	else
		cout << "Lawncuts file failed to open" << endl;
	inputStream.close();
	
	inputStream.open("hourlys.csv");
	if(!inputStream.fail())
	{
		cout << "Hourlys file opened successfully" << endl;
		
		string title;
		getline(inputStream, title);
		
		while(!inputStream.eof())
		{
			string date;
			getline(inputStream, date, ',');
			
			string pr = "";
			getline(inputStream, pr, ',');
			double price = 0;
			stringstream ssPrice(pr);
			ssPrice >> price;
			
			string description;
			getline(inputStream, description, ',');
			
			string name;
			getline(inputStream, name, ',');
			name = name.erase(0, name.find_first_not_of(' '));
			
			string pa = "";
			bool isPaid = false;
			getline(inputStream, pa, ',');
			if(pa == " true")
				isPaid = true;
				
			string p = "";
			getline(inputStream, p, ',');
			double amtPaid = 0;
			stringstream ssPaid(p);
			ssPaid >> amtPaid;
			
			string hours;
			getline(inputStream, hours, ',');
			hours = hours.erase(0, hours.find_first_not_of(' '));
			
			string r = "";
			getline(inputStream, r, ',');
			double rate = 0;
			stringstream ssRate(r);
			ssRate >> rate;
			
			addRecord(date, price, description, customerBase.getCustomer(name), isPaid, amtPaid, hours, rate);
		}
	}
	else
		cout << "Hourlys file failed to open" << endl;
	inputStream.close();
}

RecordBase::~RecordBase()
{
	ofstream outputStream;
	outputStream.open("expensesOut.csv");
	if(!outputStream.fail())
	{
		outputStream << "Date, Price, Description, To Who" << endl
					 << getExpenses();
		cout << "Expenses output complete" << endl;
	}
	else
		cout << "Expenses output failed" << endl;
	outputStream.close();
	
	outputStream.open("lawncutsOut.csv");
	if(!outputStream.fail())
	{
		outputStream << "Date, Price, Description, Customer Name, isPaid, Amount Paid, Days Since" << endl
					 << getLawncuts();
		cout << "Lawncuts output complete" << endl;
	}
	else
		cout << "Lawncuts output failed" << endl;
	outputStream.close();
	
	outputStream.open("hourlysOut.csv");
	if(!outputStream.fail())
	{
		outputStream << "Date, Price, Description, Customer Name, isPaid, Amount Paid, Hours, Rate" << endl
					 << getHourlys();
		cout << "Hourlys output complete" << endl;
	}
	else
		cout << "Hourlys output failed" << endl;
	outputStream.close();
	
	for(int i = 0; i < totalSize; i++)
		delete records[i];
}

RecordBase::RecordBase(const RecordBase& rhs)
{
	totalSize = rhs.totalSize;
	for(int i = 0; i < totalSize; i++)
		records[i] = rhs.records[i];
}

const RecordBase RecordBase::operator=(const RecordBase& rhs)
{
	totalSize = rhs.totalSize;
	for(int i = 0; i < totalSize; i++)
		records[i] = rhs.records[i];
	return *this;
}

CustomerBase RecordBase::getCustomerBase()
{
	return customerBase;
}

void RecordBase::addRecord(string date, double price, string des, Customer* cust, bool pa, double amtPaid, string hrs, double rate)
{
	totalSize++;
	numHourlys++;
	
	if(totalSize < MAX_SIZE)
		records[totalSize - 1] = new Hourly(date, price, des, cust, pa, amtPaid, hrs, rate);
}

void RecordBase::addRecord(string date, double price, string des, Customer* cust, bool pa, double amtPaid, int days)
{
	totalSize++;
	numLawncuts++;
	
	if(totalSize < MAX_SIZE)
		records[totalSize - 1] = new Lawncut(date, price, des, cust, pa, amtPaid, days);
}

void RecordBase::addRecord(string date, double price, string des, string who)
{
	totalSize++;
	numExpenses++;
	
	if(totalSize < MAX_SIZE)
		records[totalSize - 1] = new Expense(date, price, des, who);
}

string RecordBase::getHourlys()
{
	ostringstream os;
	
	int count = 0;
	for(int i = 0; i < totalSize; i++)
		if(dynamic_cast<Hourly*>(records[i]) != NULL)
		{		
			if(count != numHourlys - 1)
				os << records[i] -> toString() << ",\n";
			else if(count == numHourlys - 1)
				os << records[i] -> toString();
				
			count++;
		}
	
	return os.str();
}

string RecordBase::getLawncuts()
{
	ostringstream os;
	
	int count = 0;
	for(int i = 0; i < totalSize; i++)
		if(dynamic_cast<Lawncut*>(records[i]) != NULL)
		{
			cout << "Here1 - " << i << endl;
			if(count <= numLawncuts - 1)
			{
				cout << "Here2" << endl;
				cout << records[i] -> toString() << endl;
				os << records[i] -> toString() << ",\n";
				cout << "Here3" << endl;
			}
			else if(count == numLawncuts)
			{
				cout << "Here4" << endl;
				if(records[i] != NULL)
					os << records[i] -> toString();
				cout << "Here5" << endl;
			}
				
			cout << "Here6" << endl;
			count++;
			cout << "Here7" << endl;
		}
	
	return os.str();
}

string RecordBase::getExpenses()
{
	ostringstream os;
	
	int count = 0;
	for(int i = 0; i < totalSize; i++)
		if(dynamic_cast<Expense*>(records[i]) != NULL)
		{		
			if(count != numExpenses - 1)
				os << records[i] -> toString() << ",\n";
			else if(count == numExpenses - 1)
				os << records[i] -> toString();
				
			count++;
		}
	
	return os.str();
}

string RecordBase::toString()
{
	ostringstream os;
	
	for(int i = 0; i < totalSize; i++)
		if(i != totalSize - 1)
			if(records[i] != NULL)
				os << records[i] -> toString() << ",\n";
		else if(i == totalSize - 1)
			if(records[i] != NULL)
			{
				os << records[i] -> toString();
				break;
			}
	
	return os.str();
}
