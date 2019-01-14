/*
Name: Jaime Landers
Class: CS162
Assignement: 1
Date Started: 6/24/16 
Sources: http://www.isocpp.org for input failure guard on newtab function.  
*/

#include <iomanip>
#include <iostream>

const double BURGER_COST = 11.75;
const double FRY_COST = 3.49;
const double SHAKE_COST = 5.65;
const double SODA_COST = 2.99;
const int MAX_TAB = 100;

struct menu_items
{
	int burger_qty;
	int fry_qty;
	int shake_qty; 
	int soda_qty;
	double tab_ttl;
};

using namespace std;

int newtab (menu_items tab_number[100], int current_tab)
{
	int user_qty = 0;

	if (current_tab < MAX_TAB)
	{
		cout << "Entering order #" << current_tab + 1 << endl;

		while (cout << fixed << showpoint << setprecision(2) << "Burgers are $" << BURGER_COST << " each. How many would you like?: " && !(cin >> user_qty) || user_qty < 0)
		{
			cout << "You did not enter a valid number, try again... \n" << endl;
			cin.clear();
			cin.ignore(200, '\n');
		}
 		tab_number[current_tab].burger_qty = user_qty;
		user_qty = 0;

		while (cout << fixed << showpoint << setprecision(2) << "Fries are $" << FRY_COST << " each. How many would you like?: " && !(cin >> user_qty) || user_qty < 0)
		{
			cout << "You did not enter a valid number, try again... \n" << endl;
			cin.clear();
			cin.ignore(200, '\n');
		}
 		tab_number[current_tab].fry_qty = user_qty;
		user_qty = 0;

		while (cout << fixed << showpoint << setprecision(2) << "Shakes are $" << SHAKE_COST << " each. How many would you like?: " && !(cin >> user_qty) || user_qty < 0)
		{
			cout << "You did not enter a valid number, try again... \n" << endl;
			cin.clear();
			cin.ignore(200, '\n');
		}
 		tab_number[current_tab].shake_qty = user_qty;
		user_qty = 0;

		while (cout << fixed << showpoint << setprecision(2) << "Sodas are $" << SODA_COST << " each. How many would you like?: " && !(cin >> user_qty) || user_qty < 0)
		{
			cout << "You did not enter a valid number, try again... \n" << endl;
			cin.clear();
			cin.ignore(200, '\n');
		}
 		tab_number[current_tab].soda_qty = user_qty;
		user_qty = 0;

		tab_number[current_tab].tab_ttl = (tab_number[current_tab].burger_qty * BURGER_COST) + (tab_number[current_tab].fry_qty * FRY_COST) + (tab_number[current_tab].shake_qty * SHAKE_COST) + (tab_number[current_tab].soda_qty * SODA_COST); 

		cout << "\nThank you for your order: " << endl;
		cout << tab_number[current_tab].burger_qty << " burgers at $" << fixed << showpoint << setprecision(2) << BURGER_COST << ", ";
		cout << fixed << showpoint << setprecision(2) << "charge = $" << tab_number[current_tab].burger_qty * BURGER_COST << endl;

		cout << tab_number[current_tab].fry_qty << fixed << showpoint << setprecision(2) << " fries at $" << FRY_COST << ", ";
		cout << fixed << showpoint << setprecision(2) << "charge = $" << tab_number[current_tab].fry_qty * FRY_COST << endl;

		cout << tab_number[current_tab].shake_qty << " shakes at $" << fixed << showpoint << setprecision(2) << SHAKE_COST << ", ";
		cout << fixed << showpoint << setprecision(2) << "charge = $" << tab_number[current_tab].shake_qty * SHAKE_COST << endl;

		cout << tab_number[current_tab].soda_qty << " soda at $" << fixed << showpoint << setprecision(2) << SODA_COST << ", ";
		cout << fixed << showpoint << setprecision(2) << "charge = $" << tab_number[current_tab].soda_qty * SODA_COST << endl;

		cout << fixed << showpoint << setprecision(2) << "Total charge = $" << tab_number[current_tab].tab_ttl << "\n" << endl;

		current_tab++;
		return current_tab;

	} // closes do while

	else if (current_tab >= MAX_TAB)
	{
		cout << "You have entered the maximum amount of orders for the day, please exit the program to clear memory and start over... " << endl;

		return current_tab;
	}

} // closes newtab

int totaltab (menu_items tab_number[100], int current_tab)
{
	int i = 0; 
	double sales_total = 0.0;

	for (i = 0; i < current_tab; i++)
	{
		sales_total += tab_number[i].tab_ttl; 
	}

	cout << "There were " << current_tab << " total customer(s) today and $" << fixed << showpoint << setprecision(2) << sales_total << " dollars made total. \n" << endl;  
	
	return 0;
} // closes totaltab

int viewtab (menu_items tab_number[100], int current_tab)
{
	int user_tab = 0;
	
	if (current_tab <= 0)
	{
		cout << "There are not any orders yet, enter an order before viewing...\n" << endl;
		return 0;
	}
	cout << "There have been " << current_tab << " orders today, what tab would you like to view? ";
	cin >> user_tab;

	if (user_tab > current_tab || user_tab <= 0) 
	{
		cout << user_tab << " is not a valid choice, returing to menu...\n" << endl;
	}
	else
	{
		current_tab = user_tab - 1;

		cout << "\nHere is information for order #" << current_tab + 1 << "." << endl;
		cout << tab_number[current_tab].burger_qty << " burgers at $" << fixed << showpoint << setprecision(2) << BURGER_COST << ", ";
		cout << fixed << showpoint << setprecision(2) << "charge = $" << tab_number[current_tab].burger_qty * BURGER_COST << endl;

		cout << tab_number[current_tab].fry_qty << " fries at $" << fixed << showpoint << setprecision(2) << FRY_COST << ", ";
		cout << fixed << showpoint << setprecision(2) << "charge = $" << tab_number[current_tab].fry_qty * FRY_COST << endl;

		cout << tab_number[current_tab].shake_qty << " shakes at $" << fixed << showpoint << setprecision(2) << SHAKE_COST << ", ";
		cout << fixed << showpoint << setprecision(2) << "charge = $" << tab_number[current_tab].shake_qty * SHAKE_COST << endl;

		cout << tab_number[current_tab].soda_qty << " soda at $" << fixed << showpoint << setprecision(2) << SODA_COST << ", ";
		cout << fixed << showpoint << setprecision(2) << "charge = $" << tab_number[current_tab].soda_qty * SODA_COST << endl;

		cout << fixed << showpoint << setprecision(2) << "Total charge = $" << tab_number[current_tab].tab_ttl << "\n" << endl;

	} // closes else

	return 0;
} // closes viewtab

int main ()
{
	char user_choice = 0;
	int current_tab = 0;
	menu_items tab_number [100];

	cout << "Welcome to Jailbait Surprise Burgers and Fries! \n" << endl;
	
	while (user_choice != 'q')
	{	
		cout << "What would you like to do: (e)nter a new tab, (v)iew previous tab, or (q)uit? ";
		cin >> user_choice; 
		cout << "\n";

		if (user_choice == 'e')
		{
			current_tab = newtab(tab_number, current_tab);
		}
		else if (user_choice == 'v')
		{
			viewtab(tab_number, current_tab);
		}
		else if (user_choice == 'q')
			totaltab(tab_number, current_tab);
		else 
			cout << "You did not enter a valid selection, try again... \n" << endl;

		cout << "===== \n" << endl;

	} // closes menu

	return 0;

} // closes main
