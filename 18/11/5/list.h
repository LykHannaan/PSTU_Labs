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
	List<T>& operator=(const List<T>& l);
	T& operator[](int index);
	int operator()() const;
	List<T> operator+(T k);
	void push_back(T);
	void pop_back();
	T back();
	friend ostream& operator<< <>(ostream& out, const List<T>& l);
	friend istream& operator>> <>(istream& in, List<T>& l);
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
T List<T>::back() {
	return data[size - 1];
}

template<class T>
void List<T>::pop_back() {
	T* tmp = data;
	--size;
	data = new T[size];
	for (int i = 0; i < size; ++i) {
		data[i] = tmp[i];
	}
	delete[] tmp;
}

