#include <iostream>
#include <list>
#include "Pair.h"
#include <cstdlib>
using namespace std;
typedef list<Pair>lst;

lst make_list(int n)
{
	lst l;
	for (int i = 0; i < n; i++)
	{
		Pair a; cin >> a;
		l.push_back(a);
	}
	return l;
}

lst print_list(lst l)
{
	copy(l.begin(), l.end(), ostream_iterator<Pair>(cout, " \t "));
	cout << endl;
	return l;
}

void add_average(lst& l)
{
	Pair s;
	list<Pair>::iterator it;
	int j = 0;
	for (it = l.begin(); it != l.end(); ++it)
		s += *it;
	int n = l.size();
	l.push_back(s / n);
}

void Add_sumMaxMin(lst& l)
{
	list<Pair>::iterator it;
	Pair max = *l.begin();
	Pair min = *l.begin();
	for (it = l.begin(); it != l.end(); ++it)
		if (max < *it) max = *it;
		else if (min > *it) min = *it;

	Pair sum = min + max;
	for (it = l.begin(); it != l.end(); ++it)
		*it = *it + sum;
}

lst del_key_inRange(lst l, Pair key1, Pair key2) {
	lst tmp;
	list<Pair>::iterator it;
	for (it = l.begin(); it != l.end(); ++it) {
		if (!(key1 < *it && *it < key2)) {
			tmp.push_back(*it);
		}
	}
	return tmp;
}

int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		list<Pair>l;
		list<Pair>::iterator it = l.begin();
		int n;
		cout << "N?"; cin >> n;
		l = make_list(n);
		cout << "Созданный список: " << endl;
		print_list(l);
		add_average(l);
		cout << "Список после добавления в конец среднего арифметического: " << endl;
		print_list(l);
		Add_sumMaxMin(l);
		cout << "Список после прибавления к элементам суммы максимального и минимального: " << endl;
		print_list(l);
		cout << "Введите диапазон значений ключа для удаления: " << endl;
		Pair key1, key2;
		cin >> key1 >> key2;
		l = del_key_inRange(l, key1, key2);
		cout << "Список после удаления: " << endl;
		print_list(l);
	}
	catch (int)
	{
		cout << "error!";
	}
}