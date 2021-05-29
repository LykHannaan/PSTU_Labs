#include <iostream> 
#include "pair.h"
#include "list.h"
#include <cstdlib> 
using namespace std;
typedef List<Pair> lst;
int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		lst l;
		cout << "N?";
		int n; cin >> n;
		l.make(n);
		cout << "Созданный список: " << endl;
		l.print();
		l.add_average();
		cout << "Список после добавления среднего арифметического: " << endl;
		l.print();
		Pair k1, k2;
		cin >> k1 >> k2;
		l.del_key_inRange(k1, k2);
		cout << "Список после удаления: " << endl;
		l.print();
		l.sumMaxMin();
		cout << "Список после добавления к элементам суммы максимального и минимального: " << endl;
		l.print();
	}
	catch (int)
	{
		cout << "error!";
	}
}
