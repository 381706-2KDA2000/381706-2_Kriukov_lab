#ifndef __POLINOM_H
#define __POLINOM_H
#include "TMonom.h"
#include "TDatList.h"

class TPolinom : protected TDatList<TMonom> 
{
public:
  TPolinom();
  TPolinom(const TPolinom &q); // конструктор копирования
  TPolinom(const TDatList<TMonom> &q); // конструктор приведения типа
  TPolinom operator+(const TPolinom &q); // сложение полиномов
  TPolinom operator-(TPolinom &q);
  TPolinom operator*(TPolinom &q);
  TPolinom & operator+=(TMonom &m);
  TMonom & operator[](int) const;
  TPolinom & operator=(TPolinom &q); // присваивание
  friend ostream& operator<<(ostream &os, TPolinom &q);
};
#endif