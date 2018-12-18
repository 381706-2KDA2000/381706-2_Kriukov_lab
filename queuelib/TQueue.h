#ifndef __QUEUE_H
#define __QUEUE_H
#include "TStack.h"

template <class ValType>
class TQueue : public TStack<ValType> 
{
protected:
	int Li; // ������ ������� �������� ���������
	int GetNextIndex(int index); // �������� ��������� ������
public:
	TQueue(int Size = 1) : TStack(Size) { Li = 0; };
	ValType Get(); // ����� �� ������� � ��������� (#�1)
};
#endif

template<class ValType>
int TQueue<ValType>::GetNextIndex(int index)
{
	return (++index % MemSize);
}

template<class ValType>
inline ValType TQueue<ValType>::Get()
{
	ValType temp;
	if (IsEmpty() == 1)
		throw DataEmpty;
	else
	{
		temp = Mem[Li];
		Li = GetNextIndex(Li);
		Top--;
	}
	return temp;
}
