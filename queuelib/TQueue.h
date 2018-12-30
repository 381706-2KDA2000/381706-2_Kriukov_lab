#ifndef __QUEUE_H
#define __QUEUE_H
#include "TStack.h"
#include "TExeption.h"

template <class ValType>
class TQueue : public TStack<ValType>
{
protected:
  int li; // ������ ������� �������� ���������
  int GetNextIndex(int index); // �������� ��������� ������
public:
  TQueue(int Size = 1) : TStack<ValType>(Size) { li = 0; };
  ValType Get(); // ����� �� ������� � ��������� (#�1)
};

template<class ValType>
int TQueue<ValType>::GetNextIndex(int index)
{
  return (++index % this->memSize);
}

template<class ValType>
ValType TQueue<ValType>::Get()
{
  ValType temp;
  if (this->IsEmpty() == 1)
    throw TExeption(DataEmpty);
  else
  {
    temp = this->mem[li];
    li = GetNextIndex(li);
    this->top--;
  }
  return temp;
}

#endif