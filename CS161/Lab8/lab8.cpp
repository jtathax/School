#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int SEATS = 100;
const double ZONEA = 75.0;
const double ZONEB = 55.0;
const double ZONEC = 30.0;
//const string fileName = "ticketholders";
struct ticketHolder
	{
		string firstName;
		string lastName;
		char section;
		double charge;
	};  
//ifstream inFile;
int getHolders(ticketHolder, ifstream&);
//struct ticketHolder; 
//int getHolders(ticketHolder, int);

int main()
{
	char section;
	double charge, totalSales;
	ifstream inFile;
	int i, ticketsSold = 0, ticketTtl = 0;
	ofstream outFile;
	string firstName, lastName;

/*	struct ticketHolder
	{
		string firstName;
		string lastName;
		char section;
		double charge;
	}; */ 

	ticketHolder audience[SEATS];

	cout << "Hello, welcome to movie ticket analyzer 1.0! \n" << endl;
//	cout << "What is the name of the file you would like to import? " << endl;
//	getline (cin, fileName);
	
	cout << "Importing and analyzing data file...\n" << endl << endl;

	inFile.open("ticketholders");
	outFile.open("tickettotals");

	cout << "First:" << "\t \t" << "Last:" << "\t \t" << "Zone:" << "\t" << "Cost:" << endl;// "\t" << "Subtotal: " << endl; 
	outFile << "First:" << "\t \t" << "Last:" << "\t \t" << "Zone:" << "\t" << "Cost:" << "\t" << "Subtotal: " << endl; 
//	cout << setprecision(3) << showpoint << ZONEA << " " << ZONEB << " " << ZONEC << endl;

//	while (!inFile.eof())
//	{

/*	for (i=0; i < SEATS; i++)
	{
	while (!inFile.eof())
	{
		inFile >> audience[i].firstName >> audience[i].lastName >> audience[i].section;  
		if(!inFile)
			break;
//		cout << audience[i].firstName << " " << audience[i].lastName << " " << audience[i].section << endl;
		if (audience[i].section == 'A')
		{
	       		audience[i].charge = ZONEA ;
//	       		cout << audience[i].charge << endl;
		}
		else if (audience[i].section == 'B')
		{
	       		audience[i].charge = ZONEB  ;	       
//	       		cout << audience[i].charge << endl;
		}
		else if (audience[i].section == 'C')
		{
	       		audience[i].charge = ZONEC ; 	       
//	       		cout << audience[i].charge << endl;
		}

		ticketsSold++;
		totalSales = totalSales + audience[i].charge;
//		cout << totalSales << endl;

	cout << showpoint << setprecision(4) << audience[i].firstName << "\t \t \t" << audience[i].lastName << "\t \t" << audience[i].section << "\t \t \t" << "$" << audience[i].charge << endl;// "\t" << "$" << totalSales << endl;
*/	
//	outFile << showpoint << setprecision(4) << audience[i].firstName << "\t \t \t" << audience[i].lastName << "\t \t" << audience[i].section << "\t \t \t" << "$" << audience[i].charge << "\t" << "$" << totalSales << endl;
//	cout << "\n" << endl;
	
//	} // Closes while loop 
//	} // Closes for loop

	cout << showpoint << setprecision(5) << "\nTotal sales were $" << totalSales << " dollars and " << ticketsSold << " tickets were sold.\n " << endl;
//	outFile << showpoint << setprecision(5) << "Total sales: $" << totalSales << endl;

	ticketsSold = getHolders(audience[SEATS], inFile);//, &inFile); 
//	ticketTtl = getHolders(ticketTtl);//, &inFile); 
	
//	cout << ticketTtl << endl;

	inFile.close();
	outFile.close();

	return 0;
}

//int getHolders(int ticketTtl)

int getHolders(ticketHolder audience[SEATS], ifstream& inFile)
{
	int i, ticketsSold;
	
	for (i=0; i < SEATS; i++)
	{
	while (!inFile.eof())
	{
		inFile >> audience[i].firstName >> audience[i].lastName >> audience[i].section;  
		if(!inFile)
			break;
//		cout << audience[i].firstName << " " << audience[i].lastName << " " << audience[i].section << endl;
		if (audience[i].section == 'A')
		{
	       		audience[i].charge = ZONEA ;
//	       		cout << audience[i].charge << endl;
		}
		else if (audience[i].section == 'B')
		{
	       		audience[i].charge = ZONEB  ;	       
//	       		cout << audience[i].charge << endl;
		}
		else if (audience[i].section == 'C')
		{
	       		audience[i].charge = ZONEC ; 	       
//	       		cout << audience[i].charge << endl;
		}

		ticketsSold++;
//		totalSales = totalSales + audience[i].charge;
//		cout << totalSales << endl;

	} // closes for loop
	} // close while loop

	cout << showpoint << setprecision(4) << audience[i].firstName << "\t \t \t" << audience[i].lastName << "\t \t" << audience[i].section << "\t \t \t" << "$" << audience[i].charge << endl;// "\t" << "$" << totalSales << endl;
	return ticketsSold;
//	return 0; 
} 


void getPrice()
{
	return;
}

void totalOut ()
{
	return;
}
