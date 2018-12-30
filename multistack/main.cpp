#include <iostream>
#include "TMultiStack.h"
#include "TQueue.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  int CurrCount = 1;
  TMultiStack<int> mst(100, 10);
  mst.Put(0, 10);
  srand(time(0));
  int ms = 10, ns, code, temp, val = 0;
  cout << "Тестирование системы N стеков" << endl;
  while (CurrCount != 99)
  {
    val++;
    code = rand() % 4; // операция
    ns = rand() % ms; // номер стека
    if (code < 3)
    {
      CurrCount++;
      mst.Put(ns, val);
    }
    else if (!mst.IsEmpty(ns))
    {
      CurrCount--;
      temp = mst.Get(ns);
    }
    if (val % 1 == 0)
    {
      mst.Print();
      cout << "Циклов - " << val << ", Перепаковок - " << mst.GetRelocationCount() << endl;
      cout << "На данный момент в мультистеке:" << CurrCount << endl;
    }
  }
  return 0;
}