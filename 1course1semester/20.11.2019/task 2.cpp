#include <iostream>

using namespace std;

void menu();
void menuText();
void menuConsole();
int ratioOfArrays(char*, char*);
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
	char arrayString1[] = " NO HOMO!! ";
	char* string1 = arrayString1;

	char arrayString2[] = " NO HOMO! ";
	char* string2 = arrayString2;

	ratioOfArrays(string1, string2);
	int result = ratioOfArrays(string1, string2);
	displayResult(result);


}
int ratioOfArrays(char* string1, char* string2)
{
	int result = 0;

	for (int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++)
	{
		if (string1[i] == string2[i])
		{
			result = 1;

		}
		
	}
	if (sizeof(*string1) > sizeof(*string1))
	{
		result = 2;
	}
	else
	{
		result = 3;
	}
	return result;
}
void displayResult(int result)
{
	switch (result)
	{
	case 1:
		cout << "Arrays are equal!!" << endl;
		break;

	case 2:
		cout << "First array is bigger than second***" << endl;
		break;
	case 3:
		cout << "First array is less than second***" << endl;

	}

}