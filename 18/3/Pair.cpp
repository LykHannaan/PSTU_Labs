#include "Pair.h"
#include <iostream>
using namespace std;

Pair& Pair::operator=(const Pair& t)
{
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	return *this;
}

Pair& operator+(Pair& t, double z)
{
	t.second += z;
	return t;
}

Pair& operator+(Pair& t, int z)
{
	t.first += z;
	return t;
}

Pair Pair::operator-(const Pair& t)
{
	int temp1 = first;
	double temp2 = second;
	int temp3 = t.first;
	double temp4 = t.second;
	Pair p; 
	p.first = temp1 - temp3;
	p.second = (temp2 - temp4);
	return p;
}

istream& operator>>(istream& in, Pair& t)
{
	cout << "first? : "; in >> t.first;
	cout << "second? : "; in >> t.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& t)
{
	return(out << t.first << " : " << t.second);
}
