#pragma once
#include <iostream>
#include <fstream> 
using namespace std;
class Pair
{
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	Pair operator =(const Pair&);
	bool operator >(const Pair&);
	bool operator <(const Pair&);
	bool operator!=(const Pair&);
	bool operator ==(const Pair&);
	Pair operator-(const Pair&);
	friend Pair& operator+(Pair& t, int z);
	friend Pair& operator+(Pair& t, double z);
	friend ostream& operator <<(ostream& out, const Pair& p);
	friend istream& operator>>(istream& in, Pair& p);
	friend fstream& operator>>(fstream& fin, Pair& p);
	friend fstream& operator <<(fstream& fout, const Pair& p);
public:
	~Pair();
private:
	int first;
	double second;
};