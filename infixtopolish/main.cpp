#include "InfixToPolish.h"
#include <iostream>

using namespace std;

int main()
{
  setlocale(LC_ALL, ""); 
  TInfixToPolish ExpConvertor;
  char Expression[80], *PolishExpression;
  cout << "������� �����. ��������� �� ��������� � ����������� ������" << endl;
  cout << "������� ���������" << endl;
  cin >> Expression;
  PolishExpression = ExpConvertor.ConvertToPolish(Expression, strlen(Expression));
  cout << "��������� � ��������� ������ - " << Expression << endl;
  cout << "��������� � �������� �������� ������ - " << PolishExpression << endl;
  cout << "��������� - " << ExpConvertor.Calculate(PolishExpression, strlen(Expression)) << endl;
  delete PolishExpression;
}