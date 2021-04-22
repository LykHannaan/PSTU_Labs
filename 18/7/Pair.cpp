#include "Pair.h" 
Pair::Pair()
{
	first = 0;
	second = 0.0;
}


Pair::Pair(int M, double S)
{
	first = M;
	second = S;
}
Pair::Pair(const Pair& t)
{
	first = t.first;
	second = t.second;
}
Pair& Pair::operator =(const Pair& t)
{
	first = t.first;
	second = t.second;
	return *this;
}
Pair& operator*(Pair& x, Pair& y)
{
	Pair p;
	p.first = x.first * y.first;
	p.second = x.second * y.second;
	return p;
}
ostream& operator<<(ostream& out, const Pair& t)
{
	out << t.first << " : " << t.second << "\t";
	return out;
}
istream& operator>>(istream& in, Pair& t)
{
	cout << "\nfirst?";
	in >> t.first;
	cout << "\nsecond?";
	in >> t.second;
	return in;
}
