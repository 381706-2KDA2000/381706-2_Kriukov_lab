#ifndef __DATLINK_H
#define __DATLINK_H
#include <iostream>

template<class ValType>
class TDatLink {
protected:
	ValType Value; // значение
	TDatLink* pNext; // указатель на следующее звено
public:
	TDatLink(ValType Val = 0, TDatLink* next = NULL);
	void SetDatValue(ValType Val);
	ValType GetDatValue();
	void SetNextLink(TDatLink* pLink);
	TDatLink* GetNextLink();
};
#endif

template<class ValType>
inline TDatLink<ValType>::TDatLink(ValType Val, TDatLink* next)
{
	Value = Val;
	pNext = next;
}

template<class ValType>
inline void TDatLink<ValType>::SetDatValue(ValType Val)
{
	Value = Val; 
}

template<class ValType>
inline ValType TDatLink<ValType>::GetDatValue()
{
	return Value;
}

template<class ValType>
inline void TDatLink<ValType>::SetNextLink(TDatLink * pLink)
{
	pNext = pLink; 
}

template<class ValType>
inline TDatLink<ValType> * TDatLink<ValType>::GetNextLink()
{
	return pNext;
}
