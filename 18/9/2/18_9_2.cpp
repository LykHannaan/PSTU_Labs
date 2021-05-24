#include "List.h" 
#include "error.h"
#include <iostream> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		List a(5);
		int bsize;
		cin >> bsize;
		List b(bsize); //при вводе bsize > 20 выдаст ошибку 
		cin >> a;
		cout << a;
		cout << "Номер элемента списка: ";
		int n;
		cin >> n;
		cout << a[n] << endl;
		b = a;
		b * a;
		cout << a;

		cout << "Пример попытки обращения к элементу с номером больше текущего размера списка: " << endl;
		a[7] = 9;
	}
	catch (error e)
	{
		e.what();
	}
	return 0;
}