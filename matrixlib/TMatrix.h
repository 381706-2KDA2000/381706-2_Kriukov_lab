#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include "TVector.h"

using namespace std;



template <class ValType>
class TMatrix : public TVector<TVector<ValType>> 
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &mt); // ����������� 
	TMatrix(const TVector<TVector<ValType> > &mt); // �������������� ���� 
	int operator==(const TMatrix &mt); // ��������� 
	TMatrix & operator= (const TMatrix &mt); // ������������ 
	TMatrix operator+ (const TMatrix &mt); // �������� 
	TMatrix operator- (const TMatrix &mt); // ��������� 
	TMatrix operator* (const TMatrix &mt); // ��������� 
										   // ���� / �����
	friend istream & operator>>(istream &in, TMatrix &mt) 
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream & operator<<(ostream &out, const TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
};


template<class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType>>(s)
{
	for (int i = 0; i < s; i++)
		pVector[i] = TVector<ValType>(s - i, i);
}

template<class ValType>
TMatrix<ValType>::TMatrix(const TMatrix & mt) : TVector<TVector<ValType>>(mt)
{
}



template<class ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType>>& mt) : TVector<TVector<ValType>>(mt)
{
}

template<class ValType>
int TMatrix<ValType>::operator==(const TMatrix & mt)
{
	int res = 1;
	for (int i = 0; i < Size; i++)
		res *= (pVector[i] == mt.pVector[i]);
	return res;
}

template<class ValType>
TMatrix<ValType> & TMatrix<ValType>::operator=(const TMatrix & mt)
{
	if (mt.pVector != pVector)
	{
		if (Size != mt.Size)
		{
			delete[]pVector;
			pVector = new TVector<ValType>[mt.Size];
			Size = mt.Size;
		}
		StartIndex = mt.StartIndex;
		for (int i = 0; i < Size; i++)
			pVector[i] = mt.pVector[i];
	}
	return *this;
}
template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix & mt)
{
	if (Size != mt.Size)
		throw 1;
	TMatrix res;
	for (int i = 0; i < Size; i++)
		res.pVector[i] = pVector[i] + mt.pVector[i];
	return res;
}

template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix & mt)
{
	if (Size != mt.Size)
		throw 1;
	TMatrix res;
	for (int i = 0; i < Size; i++)
		res.pVector[i] = pVector[i] - mt.pVector[i];
	return res;
}
template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix & mt)
{
	if (Size != mt.Size)
		throw 1;
	TMatrix res(Size);
	for (int i = 0; i < Size; i++)
		for (int j = i; j < Size; j++)
			for (int k = i; k < j + 1; k++)
				res.pVector[i][j] += pVector[i][k] * mt.pVector[k][j];
	return res;
}
#endif
