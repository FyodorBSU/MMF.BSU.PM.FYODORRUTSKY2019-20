#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

const int M = 16;

class CountWords
{
public:
	CountWords();
	CountWords(char*, int);
	inline char* getWord();
	inline int getCount();
	void  setWord(char*);
	void setCount(int);

	friend ostream& operator<<(ostream&, CountWords&);
private:
	char word[M];
	int count;
};


