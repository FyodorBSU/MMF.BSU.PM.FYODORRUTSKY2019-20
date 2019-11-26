#include <iostream>

using namespace std;

void menu();
void menuText();
void menuConsole();
int areArraysEqual(char*, char*);
void displayResult(int);


int main()
{
	menu();

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
	cout << "press 'r' to exit" << endl;
}
void menuConsole()
{
	char arrayString1[] = " NO HOMO! ";
	char* string1 = arrayString1;

	char arrayString2[] = " NO HOMO! ";
	char* string2 = arrayString2;

	areArraysEqual(string1, string2);
	int result = areArraysEqual(string1, string2);
	displayResult(result);


}
int areArraysEqual(char* string1, char* string2)
{
	int result = 0;

	for (int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++)
	{
		if (string1[i] == string2[i])
		{
			result = 2;

		}
		else
		{
			result = 1;
			break;

		}
	}

	if (sizeof(*string1) != sizeof(*string2))
	{
		result = 1;
	}

	return result;
}
void displayResult(int result)
{
	switch (result)
	{
	case 1:
		cout << "Arrays are not equal!!" << endl;
		break;

	case 2:
		cout << "arrays are equal!!" << endl;
		break;

	}

}