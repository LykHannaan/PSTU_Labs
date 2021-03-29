#include<iostream>
#include<string>
#include "zarplata.h"
using namespace std;

ZP::ZP()
{
	FIO = "";
	salary = 0.0;
	percent = 0;
	cout << "Constructor bez parametrov dlya objecta " << this << endl;
}
ZP::ZP(string N, double S, int A)
{
	FIO = N;
	salary = S;
	percent = A;
	cout << "Constructor s parametrami dlya objecta " << this << endl;
}
ZP::ZP(const ZP& t)
{
	FIO = t.FIO;
	salary = t.salary;
	percent = t.percent;
	cout << "Constructor copirovania dlya objecta " << this << endl;
}
ZP::~ZP()
{
	cout << "Destrucktor dlya objecta " << this << endl;
}
string ZP::get_FIO()
{
	return FIO;
}
double ZP::get_salary()
{
	return salary;
}
int ZP::get_percent()
{
	return percent;
}
void ZP::set_FIO(string N)
{
	FIO = N;
}
void ZP::set_salary(double S)
{
	salary = S;
}
void ZP::set_percent(int A)
{
	percent = A;
}
void ZP::show()
{
	cout << "FIO: " << FIO << endl;
	cout << "salary: " << salary << endl;
	cout << "percent: " << percent << endl;
}
