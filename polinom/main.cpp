#include <conio.h>
#include "TPolinom.h"
#include <iostream>

int main() 
{
  setlocale(LC_ALL, "");
  cout << "Тестирование полиномов" << endl;
  TPolinom p;
  for (int i = 0; i < 5; i++)
  {
    int ms[] = { i+1, i+2, i+3 };
    TMonom m(i*2, 3, ms);
    p += m;
  }
  cout << "1 полином" << endl << p;
  TPolinom q;
  for (int i = 0; i < 5; i++)
  {
    int ms[] = { i + 1, i + 2, i + 3 };
    TMonom m(i+ 5, 3, ms);
    q += m;
  }
  cout << "2 полином" << endl << q;
  TPolinom r = p + q;
  cout << "Полином-результат" << endl << r;
  return 0;
}