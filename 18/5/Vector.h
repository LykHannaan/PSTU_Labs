#pragma once
#include <iostream>
#include <string>
#include "Object.h"

using namespace std;
class Vector
{
public:
	Vector();
	Vector(int);
	~Vector(void);
	void Add(Object *);
	friend ostream& operator<< (ostream& out, const Vector&);
private:
	Object** beg;
	int size;
	int cur;
};
