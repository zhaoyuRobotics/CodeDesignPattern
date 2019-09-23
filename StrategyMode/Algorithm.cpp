#include <iostream>
using namespace std;

class Algorithm
{
public:

      Algorithm(){};
      ~Algorithm(){};
      virtual void AlgorithmOpera()=0;
};

class A_Algorithm:public Algorithm
{
public:
      A_Algorithm(){};
      ~A_Algorithm(){};
      virtual void AlgorithmOpera()
      {
	cout << "Using A Algorithm--------"<<endl;
      }
};

class B_Algorithm:public Algorithm
{
public:
      B_Algorithm(){};
      ~B_Algorithm(){};
      virtual void AlgorithmOpera()
      {
	cout << "Using B Algorithm--------"<<endl;
      }
};

class C_Algorithm:public Algorithm
{
public:
      C_Algorithm(){};
      ~C_Algorithm(){};
      virtual void AlgorithmOpera()
      {
	cout << "Using C Algorithm--------"<<endl;
      }
};
