#include <iostream>

using namespace std;

int main()
{
	int n;
	char ok = 'p';

	while (ok='p')
	{
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
		int i = 1, fact = 1;
		double sum = 0, sum1 = 0, k = 1;

		while (i <= n)
		{
			sum1 = sum1 + ((double)k / i);
			i = i + 1;
			sum = sum + (fact / sum1);
			fact = fact * i;



		}

		cout << "summa =" << sum << endl;
		cout << "enter 'p' to continue" << endl;
		cin >> ok;

	}
	return 0;
}