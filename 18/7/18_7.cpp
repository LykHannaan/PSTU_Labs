#include "list.h"
#include "Pair.h"
#include <iostream> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	List<int>a(5, 0);
	cin >> a;
	cout << "Инициализация а" << endl;
	cout << a << endl;
	List <int>b(10, 0);
	b = a;
	cout << "Списку b присвоили а" << endl;
	cout << b << endl;
	cout << "Определение размера списка b: " << b() << endl;
	List <int>c(10, 0);
	c = a * b;
	cout << "Умножение списка а на список b: " << c << endl;
	cout << "Доступ по номеру 2 списка a: " << a[2] << endl;
	
	Pair c;
	cin >> c;
	List<Pair>A(5, c);
	cin >> A;
	cout << "Инициализация списка А" << endl;
	cout << A << endl;
	List<Pair>B(10, c);
	cout << "Списку B присвоили A" << endl;
	B = A;
	cout << B << endl;
	cout << "Доступ по номеру 3 списка A: " << A[3] << endl;
	List<Pair>C(10, c);
	C = B * A;
	cout << "Умножение списка B на список A: " << C << endl;
	cout << "Размер списка B: " << B() << endl;
}
