#include <iostream>
#include "Product.cpp"

using namespace std;

class AbstractFactory
{
public:
	AbstractFactory(){}
	virtual ~AbstractFactory(){}
	virtual AbstractProduct *CreateProduct(int type)=0;
};


class SimpleFactory:public AbstractFactory
{
public:
	SimpleFactory(){}
        ~SimpleFactory(){}
	AbstractProduct *CreateProduct(int type)
	{
		AbstractProduct *tmp = NULL;
		switch(type)
		{
			case 1:
				tmp = new ProductA;
				break;
			case 2:
				tmp = new ProductB;
				break;
			default:
				break;
		}
		return tmp;
	}
};
