
#include <iostream>
#include <string>

using namespace std;
class ZP
{
	string FIO;
	double salary;
	int percent;

public:
	ZP();
	ZP(string, double, int);
	ZP(const ZP&);
	~ZP();
	string get_FIO();
	void set_FIO(string);
	double get_salary();
	void set_salary(double);
	int get_percent();
	void set_percent(int);
	void show();
};
