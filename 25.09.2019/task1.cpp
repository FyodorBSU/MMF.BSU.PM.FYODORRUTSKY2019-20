#include <iostream>

using namespace std;

int main()
{
	int n;
	while (true)
	{
		cout << "enter n.\n";
		cin >> n;
		if (n > 0)
		{
			break;
		}
		cout << "not valid symbols.\n";
		system("pause");
		system("cls");
	}

	double sum = 0;
	int i = 1,k=-1;



	while (i <= n)
	{
		sum = sum + (double)k / (2*i+1);
		k = -k;
		i = i + 1;

	}

	cout << "sum(" << n << ")= " << sum << endl;
	system("pause");
	system("cls");
	return 0;

}