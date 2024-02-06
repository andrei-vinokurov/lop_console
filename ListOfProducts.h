#ifndef _LIST_OF_PRODUCTS_
#define _LIST_OF_PRODUCTS_

#include <string>
#include <vector>
#include "Product.h"
using namespace std;

class ListOfProducts
{
	public:
	ListOfProducts(string lN = "noName");
	~ListOfProducts();
	ListOfProducts (const ListOfProducts& c);
	ListOfProducts& operator=(const ListOfProducts& c);
	void GetInfo();
	private:
	vector<Product*> m_pProducts;    
	string m_LopName;
};

#endif