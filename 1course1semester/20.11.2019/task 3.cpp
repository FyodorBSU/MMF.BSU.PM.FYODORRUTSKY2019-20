#include <iostream>

using namespace std;

void menu();
void menuText();
void menuConsole();
int findingOfUnderstring(char*, char*);
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
	char arrayString[] = "NO HOMO!!";
	char* string = arrayString;

	char underString[] = "HOMO";
	char* under = underString;

	findingOfUnderstring(string, under);
	int n= findingOfUnderstring(string, under);
	displayResult(n);



}
int findingOfUnderstring(char* string, char* under)
{
	int notFound = 0;
	int n = -1;

	for (int i = 0; under[i] != '\0'; i++)
		for (int j = 0; string[j] != '\0'; j++)
		{
			if (under[i] == string[j])
			{
				n = j;
				
				
			}
		
		}
	return n;
	
}
void displayResult(int n)
{
	if (n >= 0)
	{
		cout << "the position of understring is " << (n+1) << endl;
	}
	else
	{
		cout << "understring is not found" << endl;
	}

}