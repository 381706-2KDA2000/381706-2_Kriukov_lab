#include "TMonom.h"

TMonom::TMonom(int coeffval, int countval, int * powerarr)
{
  if (countval <= 0)
    throw TExeption(DataErr);
  count = countval;
  coeff = coeffval;
  power = new int[count];
  if (powerarr)
    for (int i = 0; i < count; i++)
      power[i] = powerarr[i];
  else
    for (int i = 0; i < count; i++)
      power[i] = 0;
//  pNextMonom = NULL;
}

TMonom::TMonom(TMonom & monom)
{
  count = monom.count;
  coeff = monom.coeff;
//  pNextMonom = monom.pNextMonom;
  power = new int[count];
  for (int i = 0; i < count; i++)
    power[i] = monom.power[i];
}

TMonom::~TMonom()
{
  if (power)
    delete[]power;
}


inline void TMonom::SetCoeff(int cval)
{
  coeff = cval;
}

inline int TMonom::GetCoeff()
{
  return coeff;
}

int TMonom::GetPower(int pos)
{
  if ((pos > count - 1) || (pos < 0))
    throw TExeption(DataErr);
  return power[pos];
}

void TMonom::SetPower(int val, int pos)
{
  if ((pos > count - 1) || (pos < 0))
    throw TExeption(DataErr);
  power[pos] = val;
}

//inline TMonom* TMonom::GetNext()
//{
//  return pNextMonom;
//}


void TMonom::SetCount(int countval)
{
  if (countval <= 0)
    throw TExeption(DataErr);
  unsigned* tmp = new unsigned int[count];
  for (int i = 0; i < count; i++)
    tmp[i] = power[i];
  delete[] power;
  power = new int[countval];
  for (int i = 0; i < (count > countval ? countval : count); i++)
    power[i] = tmp[i];
  delete[] tmp;
}


inline int TMonom::GetCount()
{
  return count;
}

template<class ValType>
inline void TMonom<ValType>::SetNext(TMonom * _next)
{
  pNextMonom = _next;
}

template<class ValType>
TMonom & TMonom<ValType>::operator=(TMonom & monom)
{
  if (this != &monom)
  {
    if (n != monom.n)
    {
      delete[] power;
      power = new int[n];
    }
    count = monom.count;
    coeff = monom.coeff;
    pNextMonom = monom.pNextMonom;
    power = new int[n];
    for (int i = 0; i < n; i++)
      power[i] = monom.power[i];
  }
  return *this;
}

template<class ValType>
TMonom TMonom<ValType>::operator+(TMonom & monom)
{
  if (n != monom.n)
    throw TExeption(DataErr);
  TMonom tmp(monom);
  if (*this == monom)
    tmp.coeff = coeff + monom.coeff;
  else
    throw TExeption(DataErr);
  return tmp;
}

template<class ValType>
inline TMonom TMonom<ValType>::operator-(TMonom & monom)
{
  if (n != monom.n)
    throw TExeption(DataErr);
  TMonom tmp(monom);
  if (*this == monom)
    tmp.coeff = coeff - monom.coeff;
  else
    throw TExeption(DataErr);
  return tmp;
}

template<class ValType>
TMonom TMonom<ValType>::operator*(TMonom & monom)
{
  if (n != monom.n)
    throw TExeption(DataErr);
  TMonom tmp(monom);
  tmp.coeff = coeff * monom.coeff;
  for (int i = 0; i < count; i++)
    tmp.power[i] = power[i] + monom.power[i];
  return tmp;
}

template<class ValType>
bool TMonom<ValType>::operator>(TMonom & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  for (int i = 0; i < count; i++)
    if (power[i] > monom.power[i])
      return true;
    else if (power[i] < monom.power[i])
      return false;
  return false;
}

template<class ValType>
bool TMonom<ValType>::operator<(TMonom & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  for (int i = 0; i < count; i++)
    if (power[i] > monom.power[i])
      return true;
    else if (power[i] < monom.power[i])
      return false;
  return false;
}
template<class ValType>
bool TMonom<ValType>::operator==(TMonom & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  for (int i = 0; i < count; i++)
    if (power[i] != monom.power[i])
      return false;
  return true;
}

ostream & operator<<(ostream & os, TMonom & tm)
{
  os << tm.coeff;
  for (int i = 0; i < tm.count; i++)
    os << "x" << i << "^" << tm.power[i];
  cout << endl;
  return os;
}
