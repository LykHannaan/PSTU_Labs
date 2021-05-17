#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	setlocale(0, "");
	int n;
	cout << "Введите количество элементов в стеке: ";
	cin >> n;

	Stack s;

	s.make(n);

	cout << "Введенный стек: ";
	s.print();

	s.add();

	cout << "Стек после добавления: ";
	s.print();

	return 0;
}
