#include <iostream>
#include "Vector.h"
#include "Print.h"
#include "Magazin.h"
using namespace std;

Vector::Vector()
{
	_begin = nullptr;
	_current = 0;
	_size = 0;
}

Vector::Vector(int count)
{
	_begin = new Object * [count];
	_current = 0;
	_size = count;
}

Vector::~Vector()
{
	if (_begin != nullptr)
		delete[] _begin;
	_begin = nullptr;
}

void Vector::Add()
{
	if (_size == 0)
	{
		cout << "Пусто!" << endl;
		return;
	}

	Object* p;
	cout << "Выберите один из классов: " << endl;
	cout << "1) Печатное издание (print)" << endl;
	cout << "2) Журнал (magazine)" << endl;
	int choise;
	cin >> choise;
	if (choise == 1)
	{
		Print* t = new Print;
		t->Input();
		p = t;
	}
	else
	{
		Magazine* t = new Magazine;
		t->Input();
		p = t;
	}

	if (_current < _size)
	{
		_begin[_current] = p;
		_current++;
	}
}

void Vector::Show()
{
	if (_current == 0)
	{
		cout << "Пусто!" << endl;
	}
	else
	{
		Object** p = _begin;
		for (int i = 0; i < _current; i++)
		{
			(*p)->Show();
			p++;
			cout << endl;
		}
	}
}

void Vector::Del()
{
	if (_size == 0)
	{
		cout << "Пусто!" << endl;
	}
	if (_current > 0)
		_current--;
}

int Vector::operator ()()
{
	return _current;
}

void Vector::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		Object** p = _begin;
		for (int i = 0; i < _current; i++)
		{
			(*p)->HandleEvent(event);
			p++;
		}
	}
}