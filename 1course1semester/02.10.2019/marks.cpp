#include <iostream>

using namespace std;

int main()
{

	char ok = 'p';

	int n, i;
	while (ok)
	{


		while (true)
		{
			cout << "enter mark for translation:" << endl;
			cin >> n;

			if (n >= 1 && n <= 10)
			{
				i = n;
				break;
			}
			cout << "mark must be in a range of 1 to 10" << endl;
			system("pause");
			system("cls");
		}


		switch (i)
		{
		case 1:
		case 2:

			cout << "was absent" << endl;

			break;

		case 3:
		case 4:

			cout << "not satisfactorily" << endl;

			break;

		case 5:
		case 6:

			cout << "satisfactorily" << endl;

			break;

		case 7:
		case 8:

			cout << "good" << endl;

			break;

		case 9:
		case 10:

			cout << "exellent" << endl;

			break;

		default:

			cout << "not exist!!!" << endl;

		}

		cout << "press 'p' to restart " << endl;
		cin >> ok;
		system("cls");

	}
	system("pause");
	return 0;
}
