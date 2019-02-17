#ifndef __POLISH_H
#define __POLISH_H
#include <TExeption.h>
#include<iostream>
#include<cstdlib>
#include<TListStack.h>
#include<TStack.h>

using namespace std;

class TInfixToPolish {
protected:
  int GetOperationPrt(char op); // �������� ��������� ��������
  int IsOperation(char op); // �������� �� ���� ��������
public:
  double Calculate(char* mem, int len);
  char* ConvertToPolish(char * exp, int len); // �������������� � �������� ������
};
#endif
