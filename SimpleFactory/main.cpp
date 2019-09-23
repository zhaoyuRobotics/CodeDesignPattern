#include <iostream>
#include "SimpleFactory.cpp"
using namespace std;


int main()
{
  cout << "hello" <<endl;

  AbstractFactory *factory = new SimpleFactory();
  AbstractProduct *product = factory->CreateProduct(1);
  product->operation();
  delete product;
  product = NULL; 
}
