#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;
void f1(Person& c)
{
	c.set_name("Dmitriy");
	cout << c;
}
Person f2()
{
	Student l("Alex", 14, "Math", 4);
	return l;
}
void main()
{
	Person a;
	cin >> a;
	cout << a;
	Person b("Ivan", 16);
	cout << b;
	a = b;
	cout << a;

	Student c;
	cin >> c;
	cout << c;
	f1(c);
	a = f2();
	cout << a;

}
