#include <iostream>

using namespace std;

int main()

{
	double s, h, k, m;

	cout << "Enter the numerals for comparing" << endl;
	cout << "s = ";
	cin >> s;
	cout << "h = ";
	cin >> h;
	cout << "k = ";
	cin >> k;

	if (s < k)
	{
		if (s < h) m = s;

		else m = h;
	}

	else {
		if (k < h) m = k;

		else m = h;

	}

	cout << "The smallest numeral is " << m << endl;
	system("pause");
	return 0;
}



