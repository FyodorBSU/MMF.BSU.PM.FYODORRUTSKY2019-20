#include <iostream>
#include "LinckedList.h"

using namespace std;

int main()
{
	const int N = 60;
	int* array = new int[N] {0};

	for (int i = 0; i < N; ++i)
	{
		array[i] = rand() % 100;
	}

	LinckedList list(array, N);
	cout << list << endl;
	list.removeItem(7);
	cout << list;

	delete[] array;
	return 0;
}