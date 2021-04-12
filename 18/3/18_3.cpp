#include <iostream>
#include "Pair.h"
using namespace std;
const int z = 22;

void main()
{
	Pair a;
	Pair b;
	Pair c;
	cin >> a;
	cin >> b;
	c = a - b;
	cout << "c=" << c << endl;
	cout << "a=" << a + z << endl;
	cout << "b=" << b + z << endl;
}
