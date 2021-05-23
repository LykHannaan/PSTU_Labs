#pragma once
#include "Object.h"

class Vector
{
protected:
	Object** _begin;
	int _size;
	int _current;
public:
	Vector();
	Vector(int count);
	~Vector();

	void Add();
	void Del();
	void Show();
	void HandleEvent(TEvent& event);

	int operator () ();
};
