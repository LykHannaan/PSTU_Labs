#include <iostream>
#include <ctime>

using namespace std;

int n;
float x;

int factorial(int n)
{
	if (n <= 1) return 1;
	else return n * factorial(n - 1);
}
double funSumm(int n, int x)
{
	if (n == 0)
		return 1;
	else
		return funSumm(n-1, x) + pow(sin(x), n-1) / factorial(n);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите переменную x: ";
		cin >> x;
	cout << "Введите количество членов ряда - n: ";
		cin >> n;
	cout << "Результат: "<< funSumm(n, x) << endl;
	
	return 0;
}
