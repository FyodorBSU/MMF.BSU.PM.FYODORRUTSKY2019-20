#include <iostream>
#include "LinckedListDuo.h"


int main()
{
	int* array = new int[10];
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % 100;
	}
	LinckedListDuo list(array, 10);
	cout << list;
	list.addFirst(14);
	cout << list;
	list.addFirst(14);
	cout << list;
	list.addFirst(14);
	cout << list;
	list.addLast(14);
	cout << list;
	int k = 0;
	cin >> k;
	list.removeItem(k);
	cout << list;
	
}