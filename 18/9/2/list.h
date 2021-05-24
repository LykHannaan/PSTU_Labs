#pragma once
#include <iostream>

using namespace std;

const int MAX_SIZE = 20;
class Iterator
{
	friend class List;
public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it)
	{
		elem = it.elem;
	}
	bool operator==(const Iterator& it)
	{
		return elem == it.elem;
	}
	bool operator!=(const Iterator& it)
	{
		return elem != it.elem;
	};
	void operator++()
	{
		++elem;
	}
	void operator--()
	{
		--elem;
	}
	Iterator& operator+(int n)
	{
		if (n < 0)
			throw 2;
		elem += n;
		return *this;
	}
	int& operator *() const { return*elem; }
private:
	int* elem;
};

class List
{
public:
	List(int s, int k = 0);
	List(const List& a);
	~List();
	Iterator first() {
		return beg;
	}
	Iterator last() {
		return end;
	}
	List& operator=(const List& a);
	int& operator[](int index);
	List operator+(const int k);
	int operator() ();
	friend List& operator*(List& x, List& y);
	friend ostream& operator<<(ostream& out, const List& a);
	friend istream& operator>>(istream& in, List& a);
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};