#include "Person.h"
Person::Person(void)
{
	name = "";
	age = 0;
}
Person::~Person(void)
{

}
Person::Person(string M, int C)
{
	name = M;
	age = C;
}
Person::Person(const Person& person)
{
	name = person.name;
	age = person.age;
}
void Person::set_name(string M)
{
	name = M;
}
void Person::set_age(int C)
{
	age = C;
}
Person& Person::operator=(const Person& c)
{
	if (&c == this)return *this;
	name = c.name;
	age = c.age;
	return *this;
}
istream& operator>>(istream& in, Person& c)
{
	cout << "\nname: "; in >> c.name;
	cout << "\nage: "; in >> c.age;
	return in;
}
ostream& operator<<(ostream& out, const Person& c)
{
	out << "\nNAME: " << c.name;
	out << "\nAGE: " << c.age;
	return out;
}
