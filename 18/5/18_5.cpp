#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
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
	Vector v(5);
	Person a;
	cin >> a;
	cout << a << endl;
	Student b;
	cin >> b;
	cout << b << endl;
	Object*p = &a;
	p->Show();
	v.Add(p);
	p = &b;
	p->Show();
	v.Add(p);
	cout << v;
}
