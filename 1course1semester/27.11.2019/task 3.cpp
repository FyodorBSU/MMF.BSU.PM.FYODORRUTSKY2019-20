#include <iostream>

using namespace std;

void console();
void findingWords(char*, char*);
int getLength(char*);

int main()
{
	console();

	return 0;
}

void console()
{
	int const size = 256;
	char* string = new char[size];
	cout << "enter string:" << endl;
	cin.getline(string, size, '\n');


	char* word = new char[size];
	cout << "enter the word to replace:" << endl;
	cin.getline(word, size, '\n');


	findingWords(string, word);
	cout << "changed string:" << endl;
	for (int i = 0; i < getLength(string); i++)
	{
		cout << string[i];
	}
}
void findingWords(char* string, char* word)
{
	int i = 0, letters = 0, k = 0;
	for (; i < getLength(string); i++)
	{
		if (string[i] != ' ')
		{
			k = i;
			for (int j = i; string[j] != ' ' && string[j] != '\0'; j++, i++)
			{
				letters++;
			}
		}
		if (letters == getLength(word))
		{
			for (int n = 0; n < getLength(word); n++, k++)
			{
				string[k] = word[n];
			}
		}
		k = 0;
		letters = 0;
	}
}
int getLength(char* source)
{
	if (source == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}

	int length = 0;
	while (source[length])
	{
		length++;
	}
	return length;
}