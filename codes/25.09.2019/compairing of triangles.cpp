#include <iostream>

using namespace std;

int main()

{
	double s, h, k;
	char l = 'y';

	while (l=='y')
	{

		while (true)
		{
			cout << "Enter the sides of triangle" << endl;
			cout << "s = ";
			cin >> s;
			cout << "h = ";
			cin >> h;
			cout << "k = ";
			cin >> k;

			if (s + h <= k || h + k <= s || s + k <= h)
			{
				cout << "not triangle.\n";

			}
			else
			{
				break;
			}
		}

		if (s == k)
		{
			if (s == h) cout << "Triangle is equilateral" << endl;

			else cout << "Triangle is isosceles" << endl;
		}
		else {
			if (k == h) cout << "Triangle is isosceles ";

			else cout << "Triangle is versalite";
		}

		cout<<"press y to continue.\n";
		cin >> l;
		system("cls");

	}
	system("pause");
	return 0;
}
