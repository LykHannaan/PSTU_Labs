#include<iostream>
#include<string>
#include "zarplata.h"
using namespace std;
ZP make_zarplata()
{
	string s;
	double i;
	int d;
	cout << "Enter FIO: ";
	cin.get();
	getline (cin, s);
	cout << "Enter salary: ";
	cin >> i;
	cout << "Enter percent: ";
	cin >> d;
	ZP t(s, i, d);
	return t;
}
void print_zarplata(ZP t)
{
	t.show();
}
void main()
{
	ZP t1;
	t1.show();
	ZP t2("Karelov D.S.", 120.5, 30);
	t2.show();
	ZP t3 = t2;
	t3.set_FIO("Avronin M.A.");
	t3.set_salary(240.7);
	t3.set_percent(21);
	print_zarplata(t3);
	t1 = make_zarplata();
	t1.show();
}
