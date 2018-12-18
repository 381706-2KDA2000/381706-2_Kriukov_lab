#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

using namespace std;



template <class ValType>
class TVector 
{
	protected:
		ValType* pVector;
		int Size; // размер вектора
		int StartIndex; // индекс первого элемента вектора
	public:
		TVector(int s = 10, int si = 0);
		TVector(const TVector &v); // конструктор копирования 
		~TVector(); 
		int GetSize() { return Size; } // размер вектора
		int GetStartIndex() { return StartIndex; } // индекс первого элемента
		ValType & GetValue(int pos); // доступ с контролем индекса
		ValType & operator[] (int pos); // доступ
		int operator==(const TVector &v); // сравнение
		TVector & operator= (const TVector &v); // присванивание
											// скалярные операции
		TVector operator* (const ValType &val); // умножить на скаляр
											// векторные операции
		TVector operator+ (const ValType &val);
		TVector operator- (const ValType &val);
		TVector operator+ (const TVector &v); // сложение 
		TVector operator- (const TVector &v); // вычитание
		ValType operator* (const TVector &v); // скалярное произведение
										  // ввод-вывод
		friend istream & operator>>(istream &in, TVector &v);
		friend ostream & operator<<(ostream &out, const TVector &v);
};

template<class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if ((s < 0) || (si < 0))
		throw 1;
	if (s == 0)
	{
		pVector = NULL;
		Size = 0;
		StartIndex = 0;
	}
	else
	{
		pVector = new ValType[s];
		for (int i = 0; i < s; i++)
			pVector[i] = 0;
	}
	Size = s;
	StartIndex = si;
}

template<class ValType>
TVector<ValType>::TVector(const TVector & v)
{
	if (v.pVector != pVector)
	{
		Size = v.Size;
		StartIndex = v.StartIndex;
		pVector = new ValType[Size];
		for (int i = 0; i < Size; i++)
			pVector[i] = v.pVector[i];
	}
}


template<class ValType>
TVector<ValType>::~TVector()
{
		delete[]pVector;
}


template<class ValType>
ValType & TVector<ValType>::GetValue(int pos)
{
	if ((pos < 0) || (pos >= Size))
		throw 1;
	return pVector[pos - StartIndex];
}

template<class ValType>
ValType & TVector<ValType>::operator[](int pos)
{
	return pVector[pos - StartIndex];
}

template<class ValType>
int TVector<ValType>::operator==(const TVector & v)
{
	if (v.Size == Size)
	{
		int res = 0;
		for (int i = 0; i < Size; i++)
			res |= (pVector[i] ^ v.pVector[i]);
		return (res == 0);
	}
	return 0;
}

template<class ValType>
TVector<ValType> & TVector<ValType>::operator=(const TVector &v)
{
	if (v.pVector != pVector)
	{
		Size = v.Size;
		StartIndex = v.StartIndex;
		if (pVector)
			delete[]pVector;
		pVector = new ValType[Size];
		for (int i = 0; i < Size; i++)
			pVector[i] = v.pVector[i];
	}
	return *this;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType & val)
{
	TVector<ValType> res(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		res[i] *= val;
	return res;
}
template<class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType & val)
{
	TVector<ValType> res(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		res[i] += val;
	return res;
}
template<class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType & val)
{
	TVector<ValType> res(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		res[i] -= val;
	return res;
}
template<class ValType>
 TVector<ValType> TVector<ValType>::operator+(const TVector & v)
{
	TVector<ValType> res(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		res.pVector[i] = v.pVector[i] + pVector[i];
	return res;
}
 template<class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector & v)
 {
	 TVector<ValType> res(Size, StartIndex);
	 for (int i = 0; i < Size; i++)
		 res.pVector[i] = pVector[i] - v.pVector[i];
	 return res;
 }

template<class ValType>
ValType TVector<ValType>::operator*(const TVector & v)
 {
	ValType res = 0;
	for (int i = 0; i < Size; i++)
		res += v.pVector[i] * pVector[i];
	return res;
 }

template<class ValType>
istream & operator>>(istream & in, TVector<ValType> & v)
{
	for (int i = 0; i < v.Size; i++)
		in >> v.pVector[i];
	return in;
}

template<class ValType>
istream & operator<<(ostream & out, TVector<ValType> & v)
{
	for (int i = 0; i < v.Size; i++)
		out << v.pVector[i] << ' ';
	return out;
}
#endif