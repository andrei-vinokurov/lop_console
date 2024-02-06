#include <iostream>
#include <string>
#include <limits>
#include "Product.h"
using namespace std;

Product::Product ()
{
    cout << "Please, enter the name of product:\n";
	cin >> m_Name;
	do
	{
	cout << "Please, enter the price of product:\n";
	cin >> m_Price;
	if (cin.fail()) 
	{
		cout << "Input Error!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	}
	}
	while (!m_Price);
	do
	{
	cout << "Please, enter the amount of product:\n";
	cin >> m_Amount;
	if (cin.fail())
	{
		cout << "Input Error!" << endl;
		cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	}
	while (!m_Amount);
}

Product::~Product ()
	{
		cout << "Product " << m_Name << " deleted.\n";
	}