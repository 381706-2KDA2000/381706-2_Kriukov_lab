#include "TPolinom.h"

TPolinom::TPolinom() : TDatList<TMonom>()
{
}

TPolinom::TPolinom(const TPolinom & q) : TDatList<TMonom>(q)
{
}

TPolinom::TPolinom(const TDatList<TMonom>& q) : TDatList<TMonom>(q)
{
}

TPolinom & TPolinom::operator+(TPolinom & q)
{
  if (listLen != q.listLen)
    throw TExeption(DataErr);
  TDatLink<TMonom>* tmp1 = pFirst;
  TDatLink<TMonom>* tmp2 = q.pFirst;
  TPolinom res;
  while (tmp1 && tmp2)
    if (tmp1 == tmp2)
    {
      res.InsLast(tmp1->GetDatValue() + tmp2->GetDatValue());
      tmp1 = tmp1->GetNextLink();
      tmp2 = tmp2->GetNextLink();
    }
    else if (tmp1 > tmp2)
    {
      res.InsLast(tmp1->GetDatValue());
      tmp1 = tmp1->GetNextLink();
    }
    else
    {
      res.InsLast(tmp2->GetDatValue());
      tmp2 = tmp2->GetNextLink();
    }
  if (!tmp1)
    tmp1 = tmp2;
  while (tmp1)
  {
    res.InsLast(tmp1->GetDatValue());
    tmp1 = tmp1->GetNextLink();
  }
  return res;
}

TPolinom & TPolinom::operator-(TPolinom & q)
{
  if (listLen != q.listLen)
    throw TExeption(DataErr);
  TDatLink<TMonom>* tmp1 = pFirst;
  TDatLink<TMonom>* tmp2 = q.pFirst;
  TPolinom res;
  while (tmp1 && tmp2)
    if (tmp1 == tmp2)
    {
      res.InsLast(tmp1->GetDatValue() - tmp2->GetDatValue());
      tmp1 = tmp1->GetNextLink();
      tmp2 = tmp2->GetNextLink();
    }
    else if (tmp1 > tmp2)
    {
      res.InsLast(tmp1->GetDatValue());
      tmp1 = tmp1->GetNextLink();
    }
    else
    {
      res.InsLast(tmp2->GetDatValue());
      tmp2 = tmp2->GetNextLink();
    }
  if (!tmp1)
    tmp1 = tmp2;
  while (tmp1)
  {
    res.InsLast(tmp1->GetDatValue());
    tmp1 = tmp1->GetNextLink();
  }
  return res;
}

TPolinom & TPolinom::operator=(TPolinom & q)
{
  if (this != &q)
  {
    TDatLink<TMonom>* pTemp = q.pFirst;
    pFirst = new TDatLink<TMonom>(pTemp->GetDatValue(), NULL);
    TDatLink<TMonom>* TmpLast = pFirst;
    TDatLink<TMonom>* TmpCurr;
    for (int i = 1; i < q.listLen; i++)
    {
      pTemp = pTemp->GetNextLink();
      TmpCurr = new TDatLink<TMonom>(pTemp->GetDatValue(), NULL);
      TmpLast->SetNextLink(TmpCurr);
      TmpLast = TmpCurr;
    }
    pLast = TmpCurr;
  }

  return *this;
}

