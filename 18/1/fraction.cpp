#include <iostream>
#include "fraction.h"

using namespace std;

void progression::Init(double a0, int r)
{
	first = a0;
	second = r;
}
void progression::Read()
{
	cout << "\nfirst";
	cin >> first;
	cout << "\nsecond";
	cin >> second;
	cout << "\nj";
}
void progression::Show()
{
	cout << "\nfirst=" << first;
	cout << "\nsecond=" << second;
	cout << "\n";
}
double progression::element(int j)
{
	return (first * pow(second, j));
}
