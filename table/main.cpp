#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <TScanTable.h>

using namespace std;

int main()
{
  TScanTable<int> table(10);
  bool flag = true;
  int cmd = 0;
  int * val;
  std::cout << "Press Enter to Start";
  while (flag)
  {
    char buff[256];
    std::cout << endl;
    std::cout << "0 - exit" << endl;
    std::cout << "1 - add record" << endl;
    std::cout << "2 - delete record" << endl;
    std::cout << "3 - find record" << endl;
    scanf_s("%d", &cmd);
    switch (cmd)
    {
    case 0:
      flag = false;
      break;
    case 1:
      val = new int;
      scanf_s("%d", val);
      cin >> buff;
      table.Add(new TTabRecord<int>(buff, val, true));
      break;
    case 2:
      cin >> buff;
      table.Delete(buff);
      break;
    case 3:
      cin >> buff;
      table.Search(buff);
      break;
    }
    std::cout << table;
  }

  return 0;
}