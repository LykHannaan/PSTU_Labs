#include <iostream>
#include "list.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	List a(5);
	cout << "Создание списка а" << endl;
	cout << a << "\n";
	cin >> a;
	cout << " Заполненный список а" << endl;
	cout << a << "\n";
	a[2] = 100;
	cout << "После обращению к эл по индеку и переприсваивания в списке а" << endl;
	cout << a << "\n";
	cout << "Разыменовывание указателя на 1 эл" << endl;
	cout << *(a.first()) << endl;
	Iterator i = a.first();
	int n;
	cout << "Номер элемента списка: ";
	cin >> n;
	i+n;
	cout << "Переход к n-ому элементу списка а" << endl;
	cout << *i << endl;
	cout << "Вывод значений списка а с помощью итератора и разыменовывания указателя" << endl;
	for (i = a.first(); i != a.last(); ++i)
		cout << *i << " ";
	cout << endl;
	List b(10);
	cout << "Создание списка b" << endl;
	cout << b << "\n";
	b = a;
	cout << "Присваивание списку b список а" << endl;
	cout << b << "\n";
	cout << "Определение размера списка b: " << b() << endl;
	List c(10);
	c = a * b;
	cout << "Произведение a и b" << endl;
	cout << c << "\n";
}

