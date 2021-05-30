#include <iostream>
#include <list>
#include "Pair.h"
#include <cstdlib>
#include <queue>
using namespace std;
typedef priority_queue<Pair> pq;
typedef list<Pair>lst;

pq make_pq(int n)
{
	pq q;
	Pair p;
	for (int i = 0; i < n; ++i) {
		cin >> p;
		q.push(p);
	}
	return q;
}
lst copy_pq_to_lst(pq q) {
	lst l;
	while (!q.empty()) {
		l.push_back(q.top());
		q.pop();
	}
	return l;
}

pq copy_lst_to_pq(lst l) {
	pq q;
	while (!l.empty()) {
		q.push(l.back());
		l.pop_back();
	}
	return q;
}

void print_pq(pq& q) {
	while (!q.empty()) {
		cout << q.top() << " \t ";
		q.pop();
	}
	cout << endl;
}

void add_average(pq& q)
{
	lst l = copy_pq_to_lst(q);
	Pair s;
	list<Pair>::iterator it;
	int j = 0;
	for (it = l.begin(); it != l.end(); ++it)
		s += *it;
	int n = l.size();
	q.push(s / n);
}

pq Add_sumMaxMin(pq q)
{
	lst l = copy_pq_to_lst(q);
	list<Pair>::iterator it;
	Pair max = *l.begin();
	Pair min = *l.begin();
	pq tmp;
	for (it = l.begin(); it != l.end(); ++it)
		if (max < *it) max = *it;
		else if (min > * it) min = *it;

	Pair sum = min + max;
	for (it = l.begin(); it != l.end(); ++it)
		tmp.push(*it + sum);

	return tmp;
}

pq del_key_inRange(pq q, Pair key1, Pair key2) {
	lst l = copy_pq_to_lst(q);
	pq tmp;
	list<Pair>::iterator it;
	for (it = l.begin(); it != l.end(); ++it) {
		if (!(key1 < *it && *it < key2)) {
			tmp.push(*it);
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
		pq q;
		q = make_pq(n);
		cout << "Созданный список: " << endl;
		print_pq(q);
		add_average(q);
		cout << "Список после добавления в конец среднего арифметического: " << endl;
		print_pq(q);
		q = Add_sumMaxMin(q);
		cout << "Список после прибавления к элементам суммы максимального и минимального: " << endl;
		print_pq(q);
		cout << "Введите диапазон значений ключа для удаления: " << endl;
		Pair k1, k2;
		cin >> k1 >> k2;
		q = del_key_inRange(q, k1, k2);
		cout << "Список после удаления: " << endl;
		print_pq(q);
	}
	catch (int)
	{
		cout << "error!";
	}
}