#include <TQueue.h>
#include <iostream>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  TQueue<int> st(100);
  int temp;
  cout << "������������ �������� ��������� ��������� ���� �������" << endl;
  for (int i = 0; i<16; i++) {
    st.Put(i);
    cout << "�������� �������� " << i << endl;
  }
  int k;
  while (!st.IsEmpty()) {
    temp = st.Get();
    cout << "����� �������� " << temp << endl;
  }
  return 0;
}