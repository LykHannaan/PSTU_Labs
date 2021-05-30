#pragma once
#include <iostream>
using namespace std;
class Pair
{
	int first;
	double second;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair() {};
	Pair& operator=(const Pair&);
	Pair operator +(const Pair&);
	Pair operator /(const int&);
	Pair operator +=(const Pair&);
	bool operator < (const Pair&) const;
	bool operator > (const Pair&) const;
	bool operator == (const Pair&);
	friend ostream& operator << (ostream& out, const Pair&);
	friend istream& operator >> (istream& in, Pair&);
};