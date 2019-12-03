#include <iostream>

using namespace std;


void menu();
void menuText();
void menuConsole();
int findIndexOfUpperString(char*, char*, int, int);
int getLength(char*);
bool isAlphabet(char);
bool isLower(char);
char toUpper(char);





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
		case 't':
			testing();
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
void menuConsole()
{
	const int size = 256;

	cout << "enter array:" << endl;
	char* arrayString = new char[size];
	cin.getline(arrayString, size, '\n');

	char* upperString = new char[size];
	cout << "enter upper array:" << endl;
	cin.getline(upperString, size, '\n');

	int length = getLength(arrayString);
	int upperLength = getLength(upperString);

	findIndexOfUpperString(arrayString, upperString, length, upperLength);

	int inc = findIndexOfUpperString(arrayString, upperString, length, upperLength);

	cout << "first enty of upper string is: " << inc << endl;




}
void testing()
{

}
int findIndexOfUpperString(char* arrayString, char* upperString, int length, int upperLength)
{
	int inc = -1;
	int sum = 0;

	for (int j = 0; j < length; j++)
	{
		if (toUpper(upperString[0]) == toUpper(arrayString[j]))
		{
			inc = j;
			int m = j++;
			sum++;

			for (int i = 1; i < upperLength; i++, m++)
			{
				if (toUpper(arrayString[m]) == toUpper(upperString[i]))
				{
					sum++;
					continue;
				}
				else
				{
					inc = -2;
					sum = 0;
					break;
				}
			}
			if (sum == upperLength)
			{
				return m - upperLength;
			}
		}
		else
		{
			continue;
		}
		
		return inc;
	}
	return inc;
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
bool isAlphabet(char symbol)
{
	return 'A' <= symbol && symbol <= 'Z' || 'a' <= symbol && symbol <= 'z';
}
bool isLower(char symbol)
{
	return 'a' <= symbol && symbol <= 'z';
}
char toUpper(char symbol)
{
	if (isAlphabet(symbol) && isLower(symbol))
	{
		return symbol - 32;
	}
	return symbol;
}