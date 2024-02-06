#ifndef _PRODUCT_
#define _PRODUCT_

#include <string>
using namespace std;
class Product 
{
	public:
	Product();
	~Product();
    string GetName() {return m_Name;};
	int GetPrice() {return m_Price;};
	int GetAmount() {return m_Amount;};
	private:
	string m_Name;
	int m_Price;
	int m_Amount;
};
#endif