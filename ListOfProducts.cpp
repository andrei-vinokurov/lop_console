#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include "ListOfProducts.h"
using namespace std;

ListOfProducts::ListOfProducts(string lN): m_LopName(lN)
{
	int Answer = 1;
	while (Answer != 2)
	{
		cout << "Do you want to add a new product to the list? Enter ""1"", if your answer is ""Yes"", enter ""2"", if your answer is ""No"".\n";
		cin >> Answer;
		if (Answer == 1)
		{
			Product* pProduct = new Product;             
			m_pProducts.push_back(pProduct);            
		}
    	else if(Answer == 2)
		{
    		if (m_pProducts.size()==0)           
	    	{
	        	cout << "Your list of products is empty.\n";
	    	}
	    	else
	    	{
	        	GetInfo();			
	    	}
			int AnswerEdit = 1;
			while (AnswerEdit != 2)
			{
				cout << "Do you want to edit the list? Enter ""1"", if your answer is ""Yes"", enter ""2"", if your answer is ""No"".\n";
				cin >> AnswerEdit;
				if (AnswerEdit == 1)
				{
					int AnswerAddDel = 0;
					cout << "If you want to add then enter ""1"", if you want to delete then enter ""2"", if you change your mind about making changes, then enter ""0"".\n";
					cin >> AnswerAddDel;
					if (AnswerAddDel == 1)
					{
						Product* pProduct = new Product;
						m_pProducts.push_back(pProduct);
						GetInfo();
					}
					else if (AnswerAddDel == 2)
					{
						if (m_pProducts.size()==0)
						{
							cout << "Your list of products is empty. You cannot delete anything.\n";
						}
						else
						{
							int j = 1;
							cout << "Enter the serial number of the product to be removed from the list.\n";
							cin >> j;
							if (j > 0 && j <= m_pProducts.size())
							{
								delete m_pProducts[j-1];
								m_pProducts.erase((m_pProducts.begin()+(j-1)));
								GetInfo();
							}
							else if(cin.fail())
							{
	    						cout << "Your answer is not available.\n";
	    						cin.clear();
	    						cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							else
							{
								cout << "Your answer " << j << " is not available.\n";
							}		
							
						}					
					}
					else if (AnswerAddDel == 0)
					{
						cout << "There were no changes.\n";
					}
					else if(cin.fail())
					{
	    				cout << "Your answer is not available.\n";
	    				cin.clear();
	    				cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else
					{
						cout << "Your answer " << AnswerAddDel << " is not available.\n";
					}	
				}
				else if (AnswerEdit == 2)
				{
					if (m_pProducts.size()!=0)
					{
						GetInfo();
					}
					else
					{
						cout << "Your list of products is empty.\n";
					}
				}
				else if(cin.fail())
				{
	    			cout << "Your answer is not available.\n";
	    			cin.clear();
	    			cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
				{
					cout << "Your answer " << AnswerEdit << " is not available.\n";
				}	
			}
		}
		
	
		else if(cin.fail())
		{
	    	cout << "Your answer is not available.\n";
	    	cin.clear();
	    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			cout << "Your answer " << Answer << " is not available.\n";
		}
	}
}
ListOfProducts::~ListOfProducts()
{
	for (unsigned int i = 0; i < m_pProducts.size(); ++i)
	{
		delete m_pProducts[i];
		m_pProducts[i] = 0;
	}
	cout << "ListOfProducts " << m_LopName << " deleted.\n";
}
ListOfProducts::ListOfProducts (const ListOfProducts& c)
{
	for (unsigned int i = 0; i < m_pProducts.size(); ++i)
	{
		delete m_pProducts[i];
	}
	m_pProducts.clear();
	for (unsigned int i = 0; i < c.m_pProducts.size(); ++i)
	{
		m_pProducts.push_back(new Product (*(c.m_pProducts[i])));
	}
	cout << "ListOfProducts copied with constructor of copy.\n";
	GetInfo();
}
ListOfProducts& ListOfProducts::operator=(const ListOfProducts& c)
{
	if (this != &c)
	{
		for (unsigned int i = 0; i < m_pProducts.size(); ++i)
		{
			delete m_pProducts[i];
		}
		m_pProducts.clear();
		for (unsigned int i = 0; i < c.m_pProducts.size(); ++i)
		{
			m_pProducts.push_back(new Product (*(c.m_pProducts[i])));
		}
	}
	cout << "ListOfProducts copied with operator =.\n";
	GetInfo();
	return *this;
}
void ListOfProducts::GetInfo()
{
    int Sum = 0;
	ofstream list ("MyList.txt");
	list << "Your list of products " << m_LopName << "(N/Name/Price/Amount/Sum):\n";
	for (unsigned int i = 0; i < m_pProducts.size(); ++i)     
    {
        list << i+1 << "| " << m_pProducts[i]->GetName() 
		<<"| " << m_pProducts[i]->GetPrice() << "| " << m_pProducts[i]->GetAmount() << "| " << m_pProducts[i]->GetPrice()*m_pProducts[i]->GetAmount() << ".\n";     
		list << "----------------------------------------------\n";
		Sum = Sum + m_pProducts[i]->GetPrice()*m_pProducts[i]->GetAmount();
	}
	list << "Total " << Sum << ".\n";
}