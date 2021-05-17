#include "stack.h"
#include <iostream>

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{
	mystack* p = new mystack;
	while (top != NULL)
	{
		p = top;
		top = top->pred;
		delete p;
	}
	delete top;
}

void Stack::make(int n)
{
	double a;
	if (n <= 0)
	{
		cout << "Стек не может быть создан";
	}
	mystack* p = new mystack;
	cin >> a;
	p->data = a;
	p->pred = NULL;
	top = p;
	for (int i = 2; i <= n; i++)
	{
		mystack* h = new mystack;
		cin >> a;
		h->data = a;
		h->pred = top;
		top = h;
	}
}

void Stack::print()
{
	if (top == NULL) cout << "Стек пуст" << endl;
	else {
		mystack* p = top;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->pred;
		}
		cout << endl;
	}
}

void Stack::add()
{
	mystack* p = top;
	mystack* q = new mystack;

	while (p != NULL)
	{
		if (p->data < 0) {
			mystack* r = new mystack;
			q = p->pred;
			p->pred = r;
			p = p->pred;
			p->data = 0;
			p->pred = q;
		}
		p = p->pred;
	}

}
