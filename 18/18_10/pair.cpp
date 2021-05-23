#include "Pair.h" 
Pair::Pair()
{
	first = 0;
	second = 0.0;
}
Pair::Pair(int N, double A)
{
	first = N;
	second = A;
}
Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}
Pair Pair::operator =(const Pair& p)
{
	if (&p == this)
		return *this;
	first = p.first;
	second = p.second;
	return*this;
}
Pair::~Pair()
{
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << p.first << " : " << p.second << "\n";
	return out;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "first?";
	in >> p.first;

	cout << "second?";
	in >> p.second;
	return in;
}
fstream& operator>>(fstream& fin, Pair& p)
{
	fin >> p.first;
	fin >> p.second;
	return fin;
}
fstream& operator<<(fstream& fout, const Pair& p)
{
	fout << p.first << "\n" << p.second << "\n";
	return fout;
}

Pair Pair::operator-(const Pair& p)
{
	first -= p.first;
	second -= p.second;
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

bool Pair::operator!=(const Pair& p)
{
	return (first != p.first && second != p.second);
}
bool Pair::operator<(const Pair& p)
{
	return (first < p.first&& second < p.second);
}
bool Pair::operator>(const Pair& p)
{
	return (first > p.first && second > p.second);
}
bool Pair::operator==(const Pair& p)
{
	return (first == p.first && second == p.second);
}