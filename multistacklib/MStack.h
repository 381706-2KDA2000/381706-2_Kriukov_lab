#ifndef __MSTACK_H
#define __MSTACK_H

#include <TStack.h> 

template <class ValType>
class MStack : public TStack<ValType>
{
public:
	MStack(ValType* ind = NULL, int Size = 0);
	void SetMem(ValType* ind, int Size);
};

template<class ValType>
MStack<ValType>::MStack(ValType * ind, int Size)
{
	Mem = ind;
	Top = -1;
	MemSize = Size;
}


template<class ValType>
void MStack<ValType>::SetMem(ValType * ind, int Size)
{
	Mem = ind;
	MemSize = Size;
}
#endif
