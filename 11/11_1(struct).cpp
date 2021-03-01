//однонаправленный список через структуры

#include <iostream>
#include <windows.h>
using namespace std;

struct List {
	double data;
	List* next;
};
List* make(int size)
{
	if (size == 0)
	{
		cout << "Список не может быть создан" << endl;
		return 0;
	}
	List* first, *p;
	first = NULL;
	cout << "Введите 1 элемент: " << endl;
	p = new List;
	cin >> p->data;
	first = p;
	for (int i = 2; i <= size; i++)
	{
		List* h = new List;
		p->next = h;
		p = p->next;
		cout << "Введите " << i << "элемент: ";
		cin >> p->data;
		p->next = NULL;
	}
	return first;
}

void print(List* first)
{
	if (first == NULL)
		cout << "Список пустой" << endl;
	else
	{
		List* p = first;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void add(List* first)
{
	List* p = first;
	List* q = new List;

	while (p != NULL)
	{
		if (p->data < 0) {
			List* r = new List;
			q = p->next;
			p->next = r;
			p = p->next;
			p->data = 0;
			p->next = q;
		}
		p = p->next;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	cout << "Введите размер списка: ";
	cin >> size;
	List* list = make(size);
	cout << "Ваш список: " << endl;
	print(list);
	add(list);
	cout << "Ваш список после добавления: " << endl;
	print(list);

	return 0;
} 
