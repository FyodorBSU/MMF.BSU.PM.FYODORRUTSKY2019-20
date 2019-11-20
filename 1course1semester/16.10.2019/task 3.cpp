#include <iostream>

using namespace std;

int enterNumber();
short digitsInNumber(int);
void counter(int, short, int&, int&, int&);
int logic(int a, int b, int c);
void menu();
void console();
void display(int, short);
void runTest();
void testing(int, int, int, int, int, int);


int main()
{
	menu();
	return 0;
}
int enterNumber()
{
	int number;
	cout << "Enter the number.\n";
	cin >> number;
	number = abs(number);
	return number;
}
short digitsInNumber(int number)
{
	int i = 0;
	while (number != 0)
	{
		number /= 10;
		i++;
	}
	return i;
}
void counter(int number, short i, int& a, int& b, int& c)
{

	int k = i;
	for (int z = 1; z < k; z++, i--)
	{
		int x = number / (int)pow(10, i - 1);
		int y = (number / (int)pow(10, i - 2)) - (int)10 * x;
		if (x > y)
		{
			a = a + 1;
			number = number % (int)pow(10, i - 1);
			continue;
		}
		if (x < y)
		{
			b = b + 1;
			number = number % (int)pow(10, i - 1);
			continue;
		}
		if (x == y)
		{
			c = c + 1;
			number = number % (int)pow(10, i - 1);
			continue;
		}


	}

}
int logic(int a, int b, int c)
{
	int type = 0;
	if (a == 0 && b == 0)
		type = 1;
	else if (b > 0 && c == 0 && a == 0)
		type = 2;
	else if (b > 0 && c > 0 && a == 0)
		type = 3;
	else if (b == 0 && c == 0 && a > 0)
		type = 4;
	else if (b == 0 && c > 0 && a > 0)
		type = 5;
	else
		type = 6;
	return type;
}
void menu()
{
	while (true)
	{
		cout << "Press 1 to work with console.\n";
		cout << "Press 2 to start test.\n";
		cout << "Press 3 to exit.\n";
		char operation;
		cin >> operation;
		system("cls");
		switch (operation)
		{
		case 'c':
			console();
			break;
		case 't':
			runTest();
			break;
		case 'r':
			return;
		default:
			cout << "Invalid operation. Try again.\n";
			system("pause");
			system("cls");
		}
	}


}
void console()
{
	int number = enterNumber();
	short i = digitsInNumber(number);
	display(number, i);


}
void display(int number, short i)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int& a1 = a;
	int& b1 = b;
	int& c1 = c;
	counter(number, i, a, b, c);
	int type = logic(a, b, c);
	switch (type)
	{
	case 1:
		cout << "Monotonous sequence.\n";
		break;
	case 2:
		cout << "Strictly increasing sequence.\n";
		break;
	case 3:
		cout << "Increasing sequence.\n";
		break;
	case 4:
		cout << "Stricly decreasing sequence.\n";
		break;
	case 5:
		cout << "Decreasing sequence.\n";
		break;
	case 6:
		cout << "Sequence type undefined.\n";
		break;
	}
}
void runTest()
{
	int testNumber = 1;
	testing(testNumber++, 12345, 0, 4, 0, 2);
	testing(testNumber++, 1, 0, 0, 1, 1);
	testing(testNumber++, 12331345, 1, 5, 1, 6);
	testing(testNumber++, 6543210, 6, 0, 0, 4);
	testing(testNumber++, 1223, 0, 2, 1, 3);
	testing(testNumber++, 6661, 1, 0, 2, 5);



}
void testing(int testNumber, int number, int a, int b, int c, int type)
{
	int act = logic(a, b, c);
	if (act == type)
	{
		cout << "Case # " << testNumber << " is correct.\n";
	}
	else
	{
		cout << "Case # " << testNumber << " isn't correct.\n";
		cout << "Actual is " << act << " ,but expected " << type << endl;
	}
}