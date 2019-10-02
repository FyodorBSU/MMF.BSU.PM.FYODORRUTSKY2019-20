#include <iostream>
using namespace std;

int main()
{
	double x, y;
	cout << "inter coordinates" << endl;
	cout << "x=" << endl;
	cin >> x;
	cout << "y=" << endl;
	cin >> y;

	if ((x <= 0 && x >= -1 && y >= -1 && y <= 1) || (x * x + y * y == 1))
		cout << "belongs";

	else
		cout << "dont belongs";
	return 0;
}