#ifndef __TTABRECORD_H__
#define __TTABRECORD_H__

#include <iostream>
#include <TExeption.h>
#include <TKey.h>
#include <string.h>

template <class ValType> class TScanTable;
template <class ValType> class TSortTable;

template<class ValType>
class TTabRecord
{
protected:
  TKey key;
  ValType* value;
  bool toDel;//  нужно ли удалить *value после удаления записи
public:
  TTabRecord(TKey k = "", ValType* val = NULL);
  TTabRecord(char*, ValType* val = NULL);
  TTabRecord(TTabRecord<ValType> &tr);
  ~TTabRecord();
  void SetKey(TKey k);
  void SetValue(ValType* val);
  TKey GetKey();
  ValType* GetVal();
  bool operator == (const TTabRecord& tr);
  bool operator > (const TTabRecord& tr);
  bool operator < (const TTabRecord& tr);
  TTabRecord& operator = (const TTabRecord& tr);
  template <class ValType> friend class TScanTable;
  template <class ValType> friend class TSortTable;
};

template<class ValType>
TTabRecord<ValType>::TTabRecord(TKey k, ValType* val)
{
  key = k;
  value = val;
  toDel = 0;
}

template<class ValType>
TTabRecord<ValType>::TTabRecord(char * ch, ValType * val)
{
  key = ch;
  value = val;
  toDel = 0;
}

template<class ValType>
TTabRecord<ValType>::TTabRecord(TTabRecord<ValType>& tr)
{
  toDel = 1;
  key = tr.key;
  value = new ValType();
  *value = *tr.value;
}

template<class ValType>
TTabRecord<ValType>::~TTabRecord()
{
  if (toDel)
    delete value;
}

template<class ValType>
void TTabRecord<ValType>::SetKey(TKey k)
{
  key = k;
}

template<class ValType>
void TTabRecord<ValType>::SetValue(ValType * val)
{
  value = val;
}

template<class ValType>
TKey TTabRecord<ValType>::GetKey()
{
  return key;
}

template<class ValType>
ValType * TTabRecord<ValType>::GetVal()
{
  return value;
}

template<class ValType>
bool TTabRecord<ValType>::operator==(const TTabRecord & tr)
{
  return(key == tr.key);
}

template<class ValType>
bool TTabRecord<ValType>::operator>(const TTabRecord & tr)
{
  return (key > tr.key);
}

template<class ValType>
bool TTabRecord<ValType>::operator<(const TTabRecord & tr)
{
  return (key < tr.key);
}

template<class ValType>
TTabRecord<ValType>& TTabRecord<ValType>::operator =(const TTabRecord & tr)
{
  key = tr.key;
  value = tr.value;
  return *this;
}
#endif
