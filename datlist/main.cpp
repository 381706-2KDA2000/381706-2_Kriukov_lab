
#include "TDatList.h"
#include <iostream>
#include <conio.h>
#include "time.h"

using namespace std;

void main() 
{
	setlocale(LC_ALL, ""); 
	srand(time(0));
	TDatList<int> st;
	int pVal;
	int temp;
	cout << "Тестирование списка" << endl;
	for (int i = 0; i<10; i++)
	{
		pVal = rand()%100;
		st.InsLast(pVal);
		cout << "Положили в список значение "<< pVal << endl;
	}
	// печать списка
	for (int i = 0; i < st.GetListLength(); i++) {
		pVal = st.GetDatValue(i);
		cout << "Взяли из списка значение "
			<< pVal << endl;
	}
	st.DelList();
	cout << "Нажмите любую клавишу" << endl;
	getch();
}