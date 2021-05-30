#include <list>
#include "Pair.h"
#include <iostream>
#include <algorithm>
using namespace std;
typedef list<Pair> lst;
Pair sum;
struct plus1
{
	Pair operator()(Pair& х)
	{
		return х + sum;
	}
};

Pair average(lst l)
{
	Pair s;
	list<Pair>::iterator it;
	int j = 0;
	for (it = l.begin(); it != l.end(); ++it)
		s += *it;
	int n = l.size();
	return(s / n);
}

lst make_list(int n)
{
	lst l;
	for (int i = 0; i < n; i++)
	{
		Pair p; cin >> p;
		l.push_back(p);
	}
	return l;
}

lst print_list(lst l)
{
	copy(l.begin(), l.end(), ostream_iterator<Pair>(cout, " \t "));
	cout << endl;
	return l;
}

int main()
{
	int n;
	lst::iterator i;
	cout << "N?";
	cin >> n;
	lst l;
	l = make_list(n);
	print_list(l);
	//
	cout << "key?" << endl;
	Pair f, s;
	cin >> f;
	cin >> s;
	l.remove_if([f, s](Pair p) { return ((f < p&& p < s)); });
	print_list(l);
	//
	s = average(l);
	l.push_back(s);
	print_list(l);
	//
	i = max_element(l.begin(), l.end());
	cout << "max=" << *(i) << endl;
	sum = *(i);
	i = min_element(l.begin(), l.end());
	cout << "min=" << *(i) << endl;
	sum = sum + *(i);
	for_each(l.begin(), l.end(), plus1());
	print_list(l);
}