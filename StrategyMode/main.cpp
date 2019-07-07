#include <iostream>
#include "context.cpp"

using namespace std;

int main()
{
  context m_context(Opera_A);
  m_context.call_Algorithm();
  return 0;
}
