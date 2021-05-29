#pragma once
#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std;

template <class T>
class List
{
public:
	explicit List(int s, T k);
	List();
	List(const List<T>& l);
	~List();
	List<T> &operator=(const List<T>& l);
	T& operator[](int index);
	int operator()() const;
	List<T> operator+(T k);
	void push_back(T);
	friend ostream& operator<< <>(ostream& out, const List<T>& l);
	friend istream& operator>> <>(istream& in, List<T>& l);

	void make(int n);
	void add_average();
	void print();
	void del_key_inRange(T key1, T key2);
	void sumMaxMin();
private:
	int size;
	T* data{};
};

template <class T>
List<T>::List(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}

template <class T>
List<T>::List(const List& l)
{
	size = l.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = l.data[i];
}
template <class T>
List<T>::~List()
{
	delete[]data;
	data = 0;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& a)
{
	if (this == &a)
		return *this;
	size = a.size;
	if (data != 0)
		delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}

template <class T>
T& List<T>::operator[](int index)
{
	if (index < size)
		return data[index];
	else cout << "\nError! Index>size";
}

template<class T>
List<T> List<T>::operator+(const T k) {
	List<T> tmp(size, k);
	for (int i = 0; i < size; i++) {
		tmp.data[i] = data[i] + k;
	}
	return tmp;
}

template <class T>
int List<T>:: operator()() const
{
	return size;
}

template <class T>
ostream& operator<< (ostream& out, const List<T>& l)
{
	for (int i = 0; i < l.size; ++i)
		out << l.data[i] << " ";
	return out;
}
template <class T>
istream& operator>> (istream& in, List<T>& l)
{
	for (int i = 0; i < l.size; ++i)
		in >> l.data[i];
	return in;
}

template<class T>
List<T>::List() {
	size = 0;
	data = new T[0];
}

template<class T>
void List<T>::push_back(T k) {
	T* tmp = data;
	data = new T[size + 1];
	for (int i = 0; i < size; ++i) {
		data[i] = tmp[i];
	}
	delete[] tmp;
	data[size] = k;
	++size;
}

template<class T>
void List<T>::make(int n) {

	for (int i = 0; i < n; ++i) {
		Pair p; cin >> p;
		push_back(p);
	}
}

template<class T>
void List<T>::print() {
	for (int i = 0; i < size; ++i) {
		cout << data[i] << " \t ";
	}
	cout << endl;
}

template <class T>
void List<T>::add_average()
{
	Pair s;
	class list<T>::iterator it;
	for (int i = 0; i < size; ++i) {
		s += data[i]; 
	}
	push_back(s / size);
}

template<class T>
void List<T>::del_key_inRange(T key1, T key2) {
	List<T> tmp;
	for (int i = 0; i < size; ++i) {
		if (!(key1 < data[i] && data[i] < key2)) {
			tmp.push_back(data[i]);
		}
	}
	size = tmp.size;
	T* to_del = data;
	data = tmp.data;
	delete[] to_del;
	tmp.data = nullptr;
}

template <class T>
void List<T>::sumMaxMin()
{
	class list<T>::iterator it;
	Pair max = data[0];
	Pair min = data[0];
	for (int i = 0; i < size; ++i)
		if (max < data[i]) max = data[i];
		else if (min > data[i]) min = data[i];

	Pair sum = min + max;
	List<T> tmp;
	for (int i = 0; i < size; ++i) {
		data[i] = data[i] + sum;
		tmp.push_back(data[i]);
	}
	T* to_del = data;
	data = tmp.data;
	delete[] to_del;
	tmp.data = nullptr;
}
