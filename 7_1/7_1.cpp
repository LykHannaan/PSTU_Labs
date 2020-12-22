#include <iostream>
#include <ctime>

using namespace std;

int n, z;
double z1;

int power(int z, int n)
{
	return (pow(z, n));
}

double power(double z1, int n)
{
	return pow(z, 1.0 / n);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите число z: ";
		cin >> z;
	cout << "Введите степень n: ";
	cin >> n;
	cout << "z^n = " << power(z,n) << endl;
	cout << "Введите число десятичное число z1: ";
	while (true)
	{
		cin >> z1;
	    if (z1 >= 0 or n%2!=0) break;
		else cout << "Корень не извлекается, введите другое значение z1" << endl;
	}
	cout << "десятичное число z1 под корнем n-й степени: "<< power(z1, n) << endl;
	
	return 0;
}
