#pragma once
#include<iostream>
#include<ostream>

using namespace std;

class LinckedListDuo
{
public:
	LinckedListDuo() : head(nullptr), tail(nullptr) {};
	LinckedListDuo(int*, int);
	~LinckedListDuo();

	int size() const;
	void addFirst(int);
	void addBeforeItem(int, int);
	void addAfterItem(int, int);
	void addLast(int);
	void removeItem(int);
	void clear();

	friend std::ostream& operator << (ostream&, const LinckedListDuo&);

private:
	inline bool isEmpty() const;

	struct Node
	{
		Node() : next(nullptr), previous(nullptr) { };
		Node(int value) : item(value), next(nullptr), previous(nullptr) { }
		friend std::ostream& operator << (ostream& stream, const Node& node)
		{
			stream << node.item << "->";
			return stream;
		}

		int item{ 0 };
		Node *next, *previous;
	};
	
	Node *head, *tail;
};


