#ifndef __TMONOM_H
#define __TMONOM_H
#include <iostream>
#include "TExeption.h"

using namespace std;

class TMonom 
{
protected:
  int coeff; // коэффициент монома
  int count; // число членов монома
  int* power; // массив степеней
  //TMonom* pNextMonom; // указатель на следующий моном
public:
  TMonom(int cval = 1, int ival = 0, int* powerarr = NULL);
  TMonom(TMonom& monom);
  ~TMonom();

  void SetCoeff(int cval);
  int GetCoeff();
  int GetPower(int pos);
  void SetPower(int val, int pos);
  //TMonom* GetNext();
  void SetCount(int countval);
  int GetCount();
  //void SetNext(TMonom* _next);

  TMonom& operator = (TMonom& monom);
  TMonom operator + (TMonom& monom);
  TMonom operator - (TMonom& monom);
  TMonom operator * (TMonom& monom);
  bool operator > (TMonom& monom);
  bool operator < (TMonom& monom);
  bool operator == (TMonom& monom);
  friend ostream& operator<<(ostream &os, TMonom &tm);
  friend class TPolinom;
};
#endif
