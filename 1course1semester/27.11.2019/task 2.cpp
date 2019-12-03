#include <iostream>

using namespace std;


void menu();
void menuText();
void menuConsole();
int enterNumber();
int chooseTheScale();
char* transferToAnoterSystem(int, int);
void swap(char*, int);
int getLength(char*);

int main()
{
	menuConsole();

	return 0;
}
void menu()
{
	while (true)
	{
		char operation;
		menuText();
		cin >> operation;
		switch (operation)
		{
		case 'c':
			menuConsole();
			break;
		case 'r':
			return;
		default:
			cout << "Invalid operation. Try again." << endl;
		}
		system("pause");
		system("cls");

	}
}
void menuText()
{
	cout << "press 'c' to work with console" << endl;
	cout << "press 't' to test program" << endl;
	cout << "press 'r' to exit" << endl;
}
int enterNumber()
{
	int number;
	cout << "enter number to translate:" << endl;
	cin >> number;

	return number;
}
int chooseTheScale()
{
	int scale;
	cout << "enter scale for translation:" << endl;
	cin >> scale;
	return scale;
}
char* transferToAnoterSystem(int number, int scale)
{
	const int size = 128;
	char* changedNumber = new char[size];
	char remainder;
	int j = 0;
	while (number)
	{
		remainder = number % scale;
		number /= scale;
		if (remainder >= 0 && remainder <= 9)
		{
			remainder += 48;
		}
		else
		{
			remainder += 55;
		}
		changedNumber[j] = remainder;
		j++;
	}
	changedNumber[j] = '\0';
	int length = getLength(changedNumber);
	swap(changedNumber, length);
	return changedNumber;

}
void swap(char* array, int b)
{
	for (int i = 0, t = 0, k = b - 1; k > i; i++, k--)
	{
		t = array[i];
		array[i] = array[k];
		array[k] = t;
	}

}
int getLength(char* arrayString)
{
	if (arrayString == nullptr)
	{
		throw std::invalid_argument("string cant be null!!");
	}

	int length = 0;

	while (arrayString[length])
	{
		length++;
	}
	return length;
}
void menuConsole()
{
	int number = enterNumber();
	int scale = chooseTheScale();

	char* changedNumber = transferToAnoterSystem(number, scale);
	cout << "transferd number is: " << changedNumber;
}


