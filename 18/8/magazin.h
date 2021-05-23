#pragma once
#include "Print.h"
#include <iostream>
using namespace std;

class Magazine : public Print
{
protected:
	int pages_count;

public:
	Magazine() : Print(), pages_count(0) {}
	Magazine(string name, string author, int pages) : Print(name, author), pages_count(pages) {}
	Magazine(const Magazine& b)
	{
		this->_author = b._author;
		this->_name = b._name;
		this->pages_count = b.pages_count;
	}
	~Magazine() {}
	void Show()
	{
		cout << "Magazine name: " << _name << endl;
		cout << "Author: " << _author << endl;
		cout << "Pages count: " << pages_count << endl;
	}
	void Input()
	{
		cout << "Magazine name: "; cin >> _name;
		cout << "Author: "; cin >> _author;
		cout << "Pages count: "; cin >> pages_count;
	}
};
