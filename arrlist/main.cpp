#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  srand(time(0));
  TArrList<int> st(10);
  int pVal;
  int temp;
  cout << "������������ ������ �� �������" << endl;
  for (int i = 0; i<10; i++)
  {
    pVal = rand() % 100;
    st.InsLast(pVal);
    cout << "�������� � ������ �������� " << pVal << endl;
  }
  // ������ ������
  for (int i = 0; i < st.GetListLength(); i++)
  {
    if (!st.IsEmpty())
    {
      pVal = st.GetDatValue(i);
      cout << "����� �� ������ �������� "
        << pVal << endl;
    }
  }
  return 0;
}