#include <list>
#include "Pair.h"
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef list<Pair> lst;
typedef priority_queue<Pair> pq;
Pair sum;

struct plus1
{
	Pair operator()(Pair& х)
	{
		return х + sum;
	}
};

pq make_pqueue(int n)
{
	pq q;
	for (int i = 0; i < n; i++)
	{
		Pair p; cin >> p;
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

void print_pq(pq q) {
	while (!q.empty()) {
		cout << q.top() << " \t ";
		q.pop();
	}
	cout << endl;
}

Pair average(lst l)
{
	Pair s;
	list<Pair>::iterator it;
	for (it = l.begin(); it != l.end(); ++it)
		s += *it;
	int n = l.size();
	return s/n;
}

int main()
{
	int n;
	pq q;
	Pair f, s;
	cout << "N?";
	cin >> n;
	q = make_pqueue(n);
	print_pq(q);
	//
	lst l = copy_pq_to_lst(q);
	s = average(l);
	l.push_back(s);
	q = copy_lst_to_pq(l);
	print_pq(q);
	//
	cout << "key?" << endl;
	cin >> f;
	cin >> s;
	l.remove_if([f, s](Pair p) { return ((f < p&& p < s)); });
	q = copy_lst_to_pq(l);
	print_pq(q);
	//
	lst::iterator i;
	i = max_element(l.begin(), l.end());
	cout << "max=" << *(i) << endl;
	sum = *(i);
	i = min_element(l.begin(), l.end());
	cout << "min=" << *(i) << endl;
	sum = sum + *(i);
	for_each(l.begin(), l.end(), plus1());
	q = copy_lst_to_pq(l);
	print_pq(q);
	return 0;
}