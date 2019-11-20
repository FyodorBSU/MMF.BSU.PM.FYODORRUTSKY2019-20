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
		cout << "n must be more than 0.\n";
		system("pause");
		system("cls");
	}

	double sum = 0, sum1 = 0;
	int i = 1;


	while (i <= n)
	{
		sum = sqrt(sum + 2);
		i = i + 1;

	}

	cout << "sum(" << n << ")= " << sum << endl;
	system("pause");
	return 0;

}