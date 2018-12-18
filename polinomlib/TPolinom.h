#ifndef __POLINOM_H
#define __POLINOM_H
#include "TMonom.h"
#include "TDatList.h"

class TPolinom : public TDatList<TMonom> 
{
public:
  TPolinom();
  TPolinom(const TPolinom &q); // конструктор копирования
  TPolinom(const TDatList<TMonom> &q); // конструктор приведения типа
  TPolinom & operator+(TPolinom &q); // сложение полиномов
  TPolinom & operator-(TPolinom &q);;
  TPolinom & operator=(TPolinom &q); // присваивание
  friend ostream& operator<<(ostream &os, TPolinom &q);
};
#endif