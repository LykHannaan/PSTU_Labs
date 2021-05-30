#include <map>
#include "Pair.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef map<int,Pair>TMap;
typedef TMap::iterator it;
Pair sum; Pair k1, k2;

Pair average(TMap m)
{
	Pair s = m[0];
	for (int i = 1; i < m.size(); i++)
		s += m[i];
	int n = m.size();
	return s/n;
}

TMap make_map(int n)
{
	TMap m;
	Pair p;
	for (int i = 0; i < n; ++i) {
		cin >> p;
		m.insert(make_pair(i, p));
	}
	return m;
}
void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++)
		cout << m[i] << " ";
	cout << endl;
}

int main()
{
	int n;
	cout << "N?";
	cin >> n;
	TMap m;
	m = make_map(n);
	print_map(m);
	//
	cout << "key?" << endl;
	cin >> k1;
	cin >> k2;
	for (it i = m.begin(); i != m.end(); ) {
		if (k1 < i->second && i->second < k2) {
			m.erase(i++);
		}
		else {
			++i;
		}
	}
	print_map(m);
	//
	Pair s;
	s = average(m);
	m.insert(make_pair(n,s));
	print_map(m);
	//
	it i;
	i = max_element(m.begin(), m.end());
	cout << "Max element = " << i->first << " (" << i->second << ")" << endl;
	sum = i->second;
	i = min_element(m.begin(), m.end());
	cout << "Min=" << i->first << " (" << i->second << ")" << endl;
	sum = sum + i->second;
	for (it i = m.begin(); i != m.end(); i++)
	{
		i->second = i->second + sum;
	}
	print_map(m);
}