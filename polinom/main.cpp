#include <conio.h>
#include "TPolinom.h"
#include <iostream>

int main() 
{
  setlocale(LC_ALL, "");
  cout << "������������ ���������" << endl;
  TPolinom p;
  for (int i = 0; i < 5; i++)
  {
    int ms[] = { i+1, i+2, i+3 };
    TMonom m(i*2, 3, ms);
    p += m;
  }
  cout << "1 �������" << endl << p;
  TPolinom q;
  for (int i = 0; i < 5; i++)
  {
    int ms[] = { i + 1, i + 2, i + 3 };
    TMonom m(i+ 5, 3, ms);
    q += m;
  }
  cout << "2 �������" << endl << q;
  TPolinom r = p + q;
  cout << "�������-���������" << endl << r;
  return 0;
}