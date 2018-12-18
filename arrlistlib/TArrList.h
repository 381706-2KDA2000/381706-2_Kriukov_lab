#ifndef __ARRLIST_H
#define __ARRLIST_H
#include <TExeption.h>
#include <iostream>

template<class ValType>
class TArrList
{
protected:
	ValType * Mem;
	int* index;
	int size;
	int count;
	int FirstInd;
	int FreeDataInd;
private:
	int NextFreeInd();
public:
	TArrList(int n = 0);
	TArrList(TArrList& al);
	~TArrList();
	void InsFirst(ValType val);
	void InsLast(ValType val);
	ValType GetFirst();
	ValType GetDatValue(int num);
	ValType GetLast();
	void DelFirst();
	void DelLast();
	void Del();
	bool IsFull();
	int GetListLength();
	bool IsEmpty();
};

template<class ValType>
inline int TArrList<ValType>::NextFreeInd()
{
	for (int i = 0; i < size; i++)
		if (index[i] == -2)
		{
			return i;
		}
	return -2;
}

template<class ValType>
TArrList<ValType>::TArrList(int n)
{
	if (n < 0)
		throw TExeption(DataErr);
	else if ( n == 0)
	{
		size = 0;
		count = 0;
		Mem = 0;
		index = NULL;
		FirstInd = -1;
		FreeDataInd = 0;
	}
	else
	{
		size = n;
		count = 0;
		FirstInd = -1;
		FreeDataInd = 0;
		index = new int[size];
		for (int i = 0; i < size; i++)
			index[i] = -2;
		Mem = new ValType[size];
	}
}

template<class ValType>
TArrList<ValType>::TArrList(TArrList & al)
{
	if (size == 0)
	{
		size = 0;
		count = 0;
		Mem = NULL;
		index = NULL;
		FirstInd = -1;
		FreeDataInd = 0;
	}
	else
	{
		size = al.size;
		count = al.count;
		FirstInd = al.FirstInd;
		FreeDataInd = al.FreeDataInd;
		index = new int[size];
		Mem = new ValType[size];
		for (int i = 0; i < size; i++)
		{
			index[i] = al.index[i];
			Mem[i] = al.Mem[i];
		}
	}
}

template<class ValType>
TArrList<ValType>::~TArrList()
{
	delete[]index;
	delete[]Mem;
}

template<class ValType>
void TArrList<ValType>::InsFirst(ValType val)
{
	if (IsFull())
		throw TExeption(DataFull);
	Mem[FreeDataInd] = val;
	index[FreeDataInd] = FirstInd;
	FirstInd = FreeDataInd;
	FreeDataInd = NextFreeInd();
	count++;
}
template<class ValType>
void TArrList<ValType>::InsLast(ValType val)
{
	if (IsFull())
		throw TExeption(DataFull);
	if (IsEmpty())
		InsFirst(val);
	else
	{
		int i = FirstInd;
		while (index[i] != -1)
			i = index[i];
		Mem[FreeDataInd] = val;
		index[FreeDataInd] = -1;
		index[i] = FreeDataInd;
		FreeDataInd = NextFreeInd();
		count++;
	}
}
template<class ValType>
ValType TArrList<ValType>::GetFirst()
{
	if (IsEmpty())
		throw TExeption(DataEmpty);
	return Mem[FirstInd];
}

template<class ValType>
ValType TArrList<ValType>::GetDatValue(int num)
{
	if ((num < 0) || (num > count - 1))
		throw TExeption(DataErr);
	int Ind = FirstInd;
	for(int i = 0; i < num; i++)
	{
		Ind = index[Ind];
	}
	return Mem[Ind];
}

template<class ValType>
ValType TArrList<ValType>::GetLast()
{
	int LastInd = FirstInd;
	while (index[LastInd] != -1)
	{
		LastInd = index[LastInd];
	}
	return Mem[LastInd];
}

template<class ValType>
void TArrList<ValType>::DelFirst()
{
	if (IsEmpty())
		throw TExeption(DataEmpty);
	FirstInd = index[FirstInd];
	index[tmp] = -2;
	count--;
}

template<class ValType>
void TArrList<ValType>::DelLast()
{
	int LastInd = FirstInd;
	int PrevInd;
	while (index[LastInd] != -1)
	{
		PrevInd = LastInd;
		LastInd = index[LastInd];
	}
	index[LastInd] = -2;
	index[PrevInd] = -1;
	count--;
}

template<class ValType>
void TArrList<ValType>::Del()
{
	if ((num < 0) || (num > count - 1))
		throw TExeption(DataErr);
	else if (num == 0)
		return DelFirst();
	int Ind = FirstInd;
	int PrevInd;
	for (int i = 0; i < num, index[Ind] != -1; i++)
	{
		PrevInd = Ind;
		Ind = index[Ind];
	}
	index[Ind] = -2;
	index[PrevInd] = -1;
	count--;
}

template<class ValType>
inline bool TArrList<ValType>::IsFull()
{
	return (count == size);
}

template<class ValType>
inline int TArrList<ValType>::GetListLength()
{
	return size;
}

template<class ValType>
inline bool TArrList<ValType>::IsEmpty()
{
	return (FirstInd == -1);
}
#endif