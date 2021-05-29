#include "Pair.h" 
Pair::Pair()
{
	first = 0;
	second = 0.0;
}
Pair::Pair(int f, double s)
{
	first = f;
	second = s;
}
Pair::Pair(const Pair& t)
{
	first = t.first;
	second = t.second;
}
Pair& Pair ::operator=(const Pair& t)
{
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	return *this;
}
Pair Pair ::operator+(const Pair& t)
{
	first += t.first;
	second += t.second;
	return *this;
}
bool Pair:: operator<(const Pair& t)
{
	if (first != t.first) {
		return first < t.first;
	}
	else {
		return second < t.second;
	}
}
bool Pair:: operator>(const Pair& t)
{
	if (first != t.first) {
		return first > t.first;
	}
	else {
		return second > t.second;
	}
}
Pair Pair :: operator /(const int& t)
{
	first /= t;
	second /= t;
	return *this;
}
Pair Pair :: operator +=(const Pair& t)
{
	first += t.first;
	second += t.second;
	return *this;
}
bool Pair :: operator == (const Pair& t)
{
	return first == t.first && second == t.second;
}
ostream& operator << (ostream& out, const Pair& t)
{
	out << t.first << " : " << t.second;
	return out;
}
istream& operator >> (istream& in, Pair& t)
{
	cout << "First?" << endl;
	in >> t.first;
	cout << "Second?" << endl;
	in >> t.second;
	return in;
}