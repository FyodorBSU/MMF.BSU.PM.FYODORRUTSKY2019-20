#include <iostream>

using namespace std;

int main()
{
	char ok = 'p';
	while (ok)
	{
		int n, month;

		while (true)
		{
			cout << "enter numbaer of month to know the season:" << endl;
			cin >> n;

			if (n >= 1 && n <= 12)
			{
				month = n;
				break;
			}
			cout << "no such month!!!" << endl;
			system("pause");
			system("cls");
		} 

		

		switch (month)
		{

		case 1:
		case 2:
		case 12:

			cout << "winter***" << endl;
			break;

		case 3:
		case 4:
		case 5:

			cout << "spring+++" << endl;
			break;

		case 6:
		case 7:
		case 8:

			cout << "summer!!!" << endl;
			break;

		case 9:
		case 10:
		case 11:

			cout << "autumn///" << endl;
			break;

		default:

			cout << "no such month!!!" << endl;
			break;
		}
		cout << "press 'p' to restart " << endl;
		cin >> ok;
		system("cls");


	}
	system("pause");
	return 0;
}
