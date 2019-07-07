#include "Algorithm.cpp"

enum OperaIndex{Opera_A,Opera_B,Opera_C};

class context
{

public:
   context(OperaIndex m_opera)
   {
	switch (m_opera)
	{
	
          case Opera_A: m_AlgorithmOpera = new A_Algorithm();break;
	  case Opera_B: m_AlgorithmOpera = new B_Algorithm();break;
          case Opera_C: m_AlgorithmOpera = new C_Algorithm();break;
        }
   }
   ~context()
  {
	delete m_AlgorithmOpera;
  }

  void call_Algorithm()
  {
	m_AlgorithmOpera->AlgorithmOpera();
  } 


private:
   Algorithm *m_AlgorithmOpera;

};
