#include <iostream> 
#include <set>
#include <iterator>
using namespace std;
typedef multiset<double>Mset;
typedef Mset::iterator it;

Mset make_Mset(int n)
{
	Mset m;
	for (int i = 0; i < n; i++)
	{
		double a = (double)(rand()) / RAND_MAX * 200 - 100;
		m.insert(a);
	}
	return m;
}
Mset print_Mset(Mset m)
{
	copy(m.begin(), m.end(), ostream_iterator<double>(cout, " \t "));
	cout << endl;
	return m;
}

void add_average(Mset &m)
{
	double s = 0;
	multiset<double>::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
		s += *it;
	int n = m.size();
	m.insert(s / n);
} 

Mset Add_sumMaxMin(Mset m)
{
	Mset tmp;
	multiset<double>::iterator it;
	double max = *m.begin();
	double min = *m.begin();
	for (it = m.begin(); it != m.end(); ++it)
		if (max < *it) max = *it;
		else if (min > *it) min = *it;

	double sum = min + max;
	for (it = m.begin(); it != m.end(); ++it)
		tmp.insert(*it + sum);

	return tmp;
}

Mset del_key_inRange(Mset m, int key1, int key2) {
	Mset tmp;
	multiset<double>::iterator it;
	for (it = m.begin(); it != m.end(); ++it) {
		if (!(key1 < *it && *it < key2)) {
			tmp.insert(*it);
		}
	}
	return tmp;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "N?";
	cin >> n;
	Mset m = make_Mset(n);
	cout << "Созданный список: " << endl;
	print_Mset(m);
	add_average(m);
	cout << "Список после добавления среднего арифметического: " << endl;
	print_Mset(m);
	m = Add_sumMaxMin(m);
	cout << "Список после прибавления к элементам суммы максимального и минимального: " << endl;
	print_Mset(m);
	cout << "Введите диапазон значений ключа для удаления: " << endl;
	int key1, key2;
	cin >> key1 >> key2;
	m = del_key_inRange(m, key1, key2);
	cout << "Список после удаления: " << endl;
	print_Mset(m);
}
