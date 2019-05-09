#include <TKey.h>

TKey::TKey(char * k)
{
  key = k;
  len = strlen(k);
}

void TKey::SetKey(char * k)
{
  key = k;
  len = strlen(k);
}

char * TKey::GetKey()
{
  return key;
}

TKey& TKey::operator=(const TKey & tr)
{
  key = tr.key;
  len = tr.len;
  return *this;
}

TKey& TKey::operator=(char * str)
{
  key = str;
  len = strlen(str);
  return *this;
}

bool TKey::operator==(const TKey & tr)
{
  if (len != tr.len)
    return false;
  for (int i = 0; i < len; i++)
  {
    if (key[i] != tr.key[i])
      return false;
  }
  return true;
}

bool TKey::operator>(const TKey & tr)
{
  int clamp = len;
  if (tr.len < len)
    clamp = tr.len;
  for (int i = 0; i < clamp; i++)
  {
    if (key[i] < tr.key[i])
      return true;
    else if (key[i] > tr.key[i])
      return false;
  }
  if (len < tr.len)
    return true;
  return false;
}

bool TKey::operator<(const TKey & tr)
{
  int clamp = len;
  if (tr.len < len)
    clamp = tr.len;
  for (int i = 0; i < clamp; i++)
  {
    if (key[i] > tr.key[i])
      return true;
    else if (key[i] < tr.key[i])
      return false;
  }
  if (len > tr.len)
    return true;
  return false;
}

ostream & operator<<(ostream & os, TKey & q)
{
  os << q.key;
  return os;
}
