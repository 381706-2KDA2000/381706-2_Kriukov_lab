#include <conio.h>
#include <iostream>
#include <TListStack.h>
#include <time.h>

void main() 
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	TListStack<int> mst;
	int code, temp, val = 0;
	cout << "������������ ������� ��������� ������(������)" << endl;
	cout << "������� ����� �������" << endl;
	while (1)
	{
		val++;
		code = rand()%4;
		if (code<2)
			mst.Put(val);
		else if(!mst.IsEmpty()) 
		temp = mst.Get();
		if (kbhit()) break;
	}
	getch();
	cout << "������ �����" << endl;
	mst.Print();
}