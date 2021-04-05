#include <iostream>
#include "fraction.h"

using namespace std;

void fraction::Init(double a0, int r, int t)
{
	first = a0;
	second = r;
	j = t;
}
void fraction::Read()
{
	cout << "\nfirst";
	cin >> first;
	cout << "\nsecond";
	cin >> second;
	cout << "\nj";
	cin >> j;
}
void fraction::Show()
{
	cout << "\nfirst=" << first;
	cout << "\nsecond=" << second;
	cout << "\n";
	cout << "\nj=" << j;
}
double fraction::element()
{
	return (first * pow(second, j));
}