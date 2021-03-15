//двунаправленный список через структуры

#include <iostream>
#include <windows.h>
using namespace std;

struct Node {

    int data;
    Node* prev, * next;

};

Node* make(int size)
{
	if (size == 0)
	{
		cout << "Список не может быть создан" << endl;
		return 0;
	}
	Node* first, * p;
	first = NULL;
	cout << "Введите 1 элемент: " << endl;
	p = new Node;
	cin >> p->data;
	first = p;
	p->next = NULL;
	p->prev = NULL;

	for (int i = 2; i <= size; i++)
	{
		Node* h = new Node;
		Node* q = p;
		p->next = h;
		p = p->next;
		cout << "Введите " << i << "элемент: ";
		cin >> p->data;
		p->next = NULL;
		p->prev = q;
	}
	return first;
}

void print(Node* first)
{
	if (first == NULL)
		cout << "Список пустой" << endl;
	else
	{
		Node* p = first;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}


void del_nodes(Node* first)
{
	Node* p = first->next;
	Node* prev = first;

	while (p ->next != NULL)
	{
		Node* even = p;
		p = p ->next;
		delete even;
		prev->next = p;
		prev = p;
		if (p ->next != NULL) 
			p = p ->next;
	}
	if (prev->next == p)
	{
		delete p;
		prev->next = NULL;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	cout << "Введите размер списка: ";
	cin >> size;
	Node* list = make(size);
	cout << "Ваш список: " << endl;
	print(list);
	del_nodes(list);
	cout << "Ваш список после удаления: " << endl;
	print(list);

	return 0;
}
