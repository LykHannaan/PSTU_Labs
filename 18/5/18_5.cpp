#include <iostream>
#include <string>
#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
using namespace std;

int main()
{
	Vector v(5);
	Person a;
	cin >> a;
	Student b;
	cin >> b;
	cout << "=================" << endl;
	cout << a << endl;
	cout << b << endl;
	b.for_grade();
	cout << endl;
	cout << "=================";
	cout << endl;

	Object* p = &a;
	p->Show();
	v.Add(p);
	p = &b;
	p->Show();
	v.Add(p);
	cout << v;
	return 0;
}
