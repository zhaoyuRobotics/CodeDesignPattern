#include <iostream>

using namespace std;


//***********************************************

class AbstractProduct
{
public:
	AbstractProduct(){}
	virtual ~AbstractProduct(){}
	virtual void  operation()=0;
};



//***********************************************

class ProductA:public AbstractProduct
{
public:
	ProductA(){}
	~ProductA(){}
	void operation()
	{
	  cout << "create a ProductA" << endl;
	}
};


//***********************************************

class ProductB:public AbstractProduct
{
public:
	ProductB(){}
	~ProductB(){}
	void operation()
	{
	  cout << "create a ProductB" << endl;
	}
};

