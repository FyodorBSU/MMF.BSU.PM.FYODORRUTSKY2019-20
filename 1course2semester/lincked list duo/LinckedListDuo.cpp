#include "LinckedListDuo.h"

LinckedListDuo::LinckedListDuo(int* values, int size)
{
	if (!values)
	{
		throw std::invalid_argument("Array doesn't exist.");
	}
	for (int i = size - 1; i >= 0; --i)
	{
		addFirst(values[i]);
	}
}
int LinckedListDuo::size() const
{
	int size = 0;
	Node* current = head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return size;
}
bool LinckedListDuo::isEmpty() const
{
	return !head;
}
void LinckedListDuo::addFirst(int value)
{
	Node* node = new Node(value);
	if (isEmpty())
	{
		node->previous = nullptr;
		head = tail = node;
		return;
	}
	node->next = head;
	head = node;
}
void LinckedListDuo::addBeforeItem(int value, int tag)
{
	if (isEmpty())
	{
		return;
	}
	Node* current = head,
		* previous = current;
	while (current)
	{
		if (current->item == tag)
		{
			if (current == head)
			{
				addFirst(value);
			}
			else
			{
				Node* node = new Node(value);
				previous->next = node;
				node->next = current;
				node->previous = previous;
			}
			return;
		}
		previous = current;
		current = current->next;

	}

}
void LinckedListDuo::addLast(int value)
{
	Node* node = new Node(value);                                     

	if (isEmpty())                    
	{
		node->previous = nullptr;               
		head = tail = node;                   
	}
	else 
	{
		node->previous = tail;               
		tail->next = node;               
		tail = node;            
	}
}
void LinckedListDuo::addAfterItem(int value, int tag)
{
	if (isEmpty())
	{
		return;
	}
	Node* current = head;
	while (current)
	{
		if (current->item == tag)
		{
			Node* node = new Node(value);
			node->next = current->next;
			current->next = node;
			node->previous = current->previous;
			return;
		}
		current = current->next;
	}
}
ostream& operator<<(ostream& stream, const LinckedListDuo& list)
{
	LinckedListDuo::Node* current = list.head;
	while (current)
	{
		stream << *current;
		current = current->next;
	}

	stream << endl;
	return stream;
}

void LinckedListDuo::clear()
{
	while (head)                       
	{
		tail = head->next;             
		delete head;                   
		head = tail;                   
	}
}
LinckedListDuo::~LinckedListDuo()
{
	clear();
}
void LinckedListDuo:: removeItem(int value)
{
	if (isEmpty())
	{
		return;
	}
	Node* current = head, * previous = head, * buffer = nullptr;
	while (head->item == value)
	{
		previous = head;
		head = head->next;
		if (!head)
		{
			return;
		}
		delete previous;
	}
	previous = head,
		current = previous->next;
	while (current)
	{
		if (current->item == value)
		{
			buffer = current;
			current = current->next;
			delete buffer;
			previous->next = current;
			current->previous = previous;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}
