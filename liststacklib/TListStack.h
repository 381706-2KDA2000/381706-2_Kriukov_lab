#ifndef __STACKLIST_H
#define __STACKLIST_H
#include <TExeption.h>
#include <TDatLink.h>
#include<iostream>

using namespace std;

template<class ValType>
class TListStack
{
protected:
  TDatLink<ValType>* pFirst; // ��������� �� ������ ����� ������
public:
  TListStack();
  ~TListStack();
  int IsEmpty() const; // �������� ������������ ��
  void Put(ValType Val); // �������� �������� � ����
  ValType Get(); // ������� �������� �� �����
  void Print();
};

template<class ValType>
TListStack<ValType>::TListStack()
{
  pFirst = NULL;
}
template<class ValType>
TListStack<ValType>::~TListStack()
{
  while (!IsEmpty())
  {
    TDatLink<ValType>* tmp = pFirst;
    pFirst = pFirst->GetNextLink();
    delete tmp;
  }
}

template<class ValType>
int TListStack<ValType>::IsEmpty() const
{
  return pFirst == 0;
}
template<class ValType>
void TListStack<ValType>::Put(ValType Val)
{
  TDatLink<ValType>* pTemp = new TDatLink<ValType>;
  pTemp->SetDatValue(Val);
  pTemp->SetNextLink(pFirst);
  pFirst = pTemp;
}
template<class ValType>
ValType TListStack<ValType>::Get()
{
  if (IsEmpty())
    throw TExeption(DataEmpty);
  TDatLink<ValType>* pTemp = new TDatLink<ValType>;
  ValType Val = pFirst->GetDatValue();
  pFirst = pFirst->GetNextLink();
  delete pTemp;
  return Val;
}

template<class ValType>
void TListStack<ValType>::Print()
{
  TDatLink<ValType>* pTemp = pFirst;
  while (pTemp != NULL) {
    cout << pTemp->GetDatValue() << " ";
    pTemp = pTemp->GetNextLink();
  }
}
#endif
