#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <TExeption.h>

template <class ValType>
class TStack : public TDataCom
{
protected: // поля
	ValType* Mem; // память для СД
	int Top; // индекс последнего занятого в Mem
	int MemSize;
public:
	TStack(int Size = 32);
	~TStack();
	int IsEmpty(); // контроль пустоты
	int GetSize();
	int GetCount();// число элементов в стеке
	int IsFull(); // контроль переполнения
	void Put(const int Val); // добавить значение
	ValType Get(); // извлечь значение
	void Print();
};

template<class ValType>
TStack<ValType>::TStack(int Size)
{
	if (Size < 0)
		throw TExeption(DataErr);
	else if (Size == 0)
		Mem = NULL;
	else
		Mem = new ValType[Size];
	Top = -1;
	MemSize = Size;
}

template<class ValType>
TStack<ValType>::~TStack()
{
	delete[]Mem;
}

template<class ValType>
inline int TStack<ValType>::IsEmpty()
{
	return Top == -1;
}

template<class ValType>
inline int TStack<ValType>::GetSize()
{
	return MemSize;
}

template<class ValType>
inline int TStack<ValType>::GetCount()
{
	return Top + 1;
}

template<class ValType>
inline int TStack<ValType>::IsFull()
{
	return Top == (MemSize - 1);
}

template<class ValType>
inline void TStack<ValType>::Put(const int Val)
{
	if (IsFull())
		throw TExeption(DataFull);
	Mem[++Top] = Val;
}

template<class ValType>
inline ValType TStack<ValType>::Get()
{
	if (IsEmpty())
		throw TExeption(DataEmpty);
	return Mem[Top--];
}

template <class ValType>
void TStack<ValType>::Print() { // печать значений стека
	for (int i = 0; i< Top + 1; i++)
		printf("%d ", Mem[i]);
	printf("\n");
}

#endif
