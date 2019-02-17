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
  TPolinom operator+(const TPolinom &q); // сложение полиномов
  TPolinom operator-(const TPolinom &q); // вычитание полиномов
  TPolinom operator*(const TPolinom &q); // умножение полиномов
  TPolinom & operator+=(const TMonom &m); // добавить моном
  TMonom & operator[](int) const;
  TPolinom & operator=(const TPolinom &q); // присваивание
  friend ostream& operator<<(ostream &os, TPolinom &q);
};
#endif