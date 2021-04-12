#include "Pair.h"
#include <iostream>
using namespace std;
const int z = 22;

Pair& Pair::operator=(const Pair& t)
{
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	return *this;
}

Pair Pair::operator+(double z)
{
	second + z;
	return *this;
}

Pair Pair::operator+(int z)
{
	first + z;
	return *this;
}

Pair Pair::operator-(const Pair& t)
{
	double temp1 = first - second;
	double temp2 = t.first - t.second;
	Pair p; 
	p.first = temp1 - temp2;
	p.second = temp1 - temp2;
	return p;
}

istream& operator>>(istream& in, Pair& t)
{
	cout << "first?"; in >> t.first;
	cout << "second?"; in >> t.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& t)
{
	return(out << t.first << " : " << t.second);
}
