#include <iostream>
using namespace std;

class Stack
{
public:
	struct mystack
	{
		int data;
		mystack* pred;
	};
	mystack* top;

public:
	Stack();
	~Stack();
	void make(int n);
	void print();
	void add();
};
