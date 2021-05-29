#pragma once
#include <iostream> 
#include <set> 
#include <iterator> 
using namespace std;

template <class T>
class MsetList
{
private:
	multiset<T> m;
	int size;
public:

	T GetMax()
	{
		return *(--m.end());
	}
	T GetMin()
	{
		return *(m.begin());
	}
	MsetList();
	MsetList(int n);
	~MsetList();
	void add_average();
	void print();
	void del_key_inRange(T key1, T key2);
	void sumMaxMin();

};

template<class T>
MsetList<T>::MsetList() {

	size = 0;
}

template<class T>
MsetList<T>::MsetList(int n) {

	for (int i = 0; i < n; ++i) {
		Pair p; cin >> p;
		m.insert(p);
	}
	size = m.size();
}

template<class T>
MsetList<T>::~MsetList() {}

template<class T>
void MsetList<T>::print() {
	class multiset<T>::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
		cout << *it;
	cout << endl;
}

template <class T>
void MsetList<T>::add_average()
{
	T s;
	class multiset<T>::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
		s += *it;
	int n = size;
	m.insert(s / n);
}

template<class T>
void MsetList<T>::del_key_inRange(T key1, T key2) {
	multiset<T>tmp;
	class multiset<T>::iterator it;
	for (it = m.begin(); it != m.end(); ++it) {
		if (!(key1 < *it && *it < key2)) {
			tmp.insert(*it);
		}
	}
	m = tmp;
}

template <class T>
void MsetList<T>::sumMaxMin()
{
	multiset<T>tmp;
	class multiset<T>::iterator it;
	T max = GetMax();
	T min = GetMin();

	T sum = min + max;
	for (it = m.begin(); it != m.end(); ++it)
	{
		*it += sum
			tmp.insert(*it);
	}

	m = tmp;
}
