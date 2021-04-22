#include <iostream>
#include "Pair.h"
using namespace std;

void main()
{
	Pair a;
	Pair b;
	Pair c;
	double z;
	cin >> a;
	cin >> b;
	c = a - b;
	cout << "Enter constant: ";
	cin >> z;
	a + z;
	b + z;
	cout << "c= " << c << endl;
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}
