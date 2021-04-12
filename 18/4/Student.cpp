#include "Student.h"
Student::Student(void) :Person()
{
	subject = "";
	grade = 0;
}
Student::~Student(void)
{

}
Student::Student(string M, int C, string P, int G):Person(M,C)
{
	subject = P;
	grade = G;
}
Student::Student(const Student&L)
{
	name = L.name;
	age = L.age;
	subject = L.subject;
	grade = L.grade;
}
void Student::set_subject(string P)
{
	subject = P;
}
void Student::set_grade(int G)
{
	grade = G;
}
Student& Student::operator=(const Student&l)
{
	if (&l == this)return *this;
	name = l.name;
	age = l.age;
	subject = l.subject;
	grade = l.grade;
	return *this;
}
istream& operator>>(istream&in, Student&l)
{
	cout << "\nname: "; in >> l.name;
	cout << "\nage: "; in >> l.age;
	cout << "\nsubject: "; in >> l.subject;
	cout << "\ngrade: "; in >> l.grade;
	return in;
}
ostream& operator<<(ostream&out, const Student&l)
{
	out << "\nNAME: " << l.name;
	out << "\nAGE: " << l.age;
	out << "\nSUBJECT: " << l.subject;
	out << "\nGRADE: " << l.grade;
	return out;
}
