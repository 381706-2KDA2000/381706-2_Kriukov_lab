#include <iostream>
#include <TListStack.h>
#include <ctime>
#include <cstdlib>

int main()
{
  setlocale(LC_ALL, "");
  srand(time(NULL));
  TListStack<int> mst;
  int code, temp, val = 0;
  cout << "������������ ������� ��������� ������(������)" << endl;
  cout << "������� ����� �������" << endl;
  while (val < 100)
  {
    val++;
    code = rand() % 4;
    if (code<2)
      mst.Put(val);
    else if (!mst.IsEmpty())
      temp = mst.Get();
  }
  cout << "������ �����" << endl;
  mst.Print();
  return 0;
}