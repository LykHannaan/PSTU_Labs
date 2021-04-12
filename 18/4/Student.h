#pragma once
#include "Person.h"
class Student : public Person
{
public:
	Student(void);
public:
	~Student(void);
	Student(string, int, string, int);
	Student(const Student&);
	string get_subject() { return subject; }
	double get_grade() { return grade; }
	void set_subject(string);
	void set_grade(int);
	Student& operator=(const Student&);
	friend istream& operator >> (istream& in, Student& l);
	friend ostream& operator << (ostream& out, const Student& l);
protected:
	string subject;
	int grade;
};
