#include "TDatList.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  srand(time(0));
  TDatList<int> st;
  int pVal;
  int temp;
  cout << "������������ ������" << endl;
  for (int i = 0; i<10; i++)
  {
    pVal = rand() % 100;
    st.InsLast(pVal);
    cout << "�������� � ������ �������� " << pVal << endl;
  }
  // ������ ������
  for (int i = 0; i < st.GetListLength(); i++) {
    pVal = st.GetDatValue(i);
    cout << "����� �� ������ �������� "
      << pVal << endl;
  }
  st.DelList();
  return 0;
}