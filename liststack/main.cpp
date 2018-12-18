#include <iostream>
#include <TListStack.h>
#include <time.h>

void main()
{
  setlocale(LC_ALL, "");
  srand(time(NULL));
  TListStack<int> mst;
  int code, temp, val = 0;
  cout << "Тестирование системы поддержки стеков(списки)" << endl;
  cout << "Нажмите любую клавишу" << endl;
  while (val < 100)
  {
    val++;
    code = rand() % 4;
    if (code<2)
      mst.Put(val);
    else if (!mst.IsEmpty())
      temp = mst.Get();
  }
  cout << "Печать стека" << endl;
  mst.Print();
}