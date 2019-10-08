#include <iostream>

using namespace std;

int main()
{
	char ok = 'p';
	while (ok)
	{
		double a, b;
		char operation;
		bool doo = true;

		cout << "calculator for asaps and groopies!!!" << endl;
		cout << "entar numerals to count:" << endl;
		cin >> a; cin >> operation;

		double result;

		switch (operation)
		{

		case '+':

			cin >> b;
			result = a + b;
			break;

		case '-':

			cin >> b;
			result = a - b;
			break;
		case '*':
			cin >> b;
			result = a * b;
			break;

		case '/':

			cin >> b;
			result = a / b;
			break;

		default:

			doo = false;
		}

		if (doo)
		{
			cout << "the result is " << result << endl;

		}
		cout << "press 'p' to restart " << endl;
		cin >> ok;
		system("cls");


	}
	system("pause");
	return 0;
}