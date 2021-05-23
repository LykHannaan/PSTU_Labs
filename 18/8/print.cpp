#include "Print.h"
#include "Event.h"
#include <iostream>
using namespace std;

Print::Print()
{
	_name = "";
	_author = "";
}

Print::Print(string name, string author)
{
	_name = name;
	_author = author;
}

Print::Print(const Print& print)
{
	_name = print._name;
	_author = print._author;
}

Print::~Print()
{
}

string Print::getName()
{
	return _name;
}

string Print::getAuthor()
{
	return _author;
}

void Print::setName(string name)
{
	_name = name;
}

void Print::setAuthor(string author)
{
	_author = author;
}

Print& Print::operator = (const Print& print)
{
	if (&print == this)
		return *this;
	_author = print._author;
	_name = print._name;
	return *this;
}

void Print::Show()
{
	cout << "Magazine name: " << _name << endl;
	cout << "Author: " << _author << endl;
}

void Print::Input()
{
	cout << "Magazine name: "; cin >> _name;
	cout << "Author: "; cin >> _author;
}

void Print::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmdName:
		{
			cout << "Magazine Name: " << getName() << endl;
			break;
		}
		}
	}
}