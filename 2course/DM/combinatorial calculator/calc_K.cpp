#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

int n, k;
unsigned long long P,A,C;

int fact(int m)
{
	if (m < 2) return 1;
	return m * fact(m - 1);
}

void permutation1()
{
	cout << endl;
	cout << "Нахождение числа перестановок из n элементов без повторений." << endl;
	cout << "Введите число n : " << endl;
	cin >> n;
	cout << "P(n) = n! = " << n << "!" << endl;
	P = fact(n);
	cout << "Ответ: " << P << endl;
}
void permut_repeat2()
{
	cout << endl;
	cout << "Нахождение числа перестановок с повторениями." << endl;
	cout << "Пусть имеется n объектов различных типов: n1 объектов первого типа, n2 объектов второго типа,... nk объектов k-го типа." << endl;
	cout << "Введите число k : " << endl;
	cin >> k;
	int *arr = new int[k];
	n = 0;
	P = 1;
	cout << "Введите k чисел : " << endl;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		n = n + arr[i];
	}
	int max = arr[0];
	int i_max = 0;
	for (int i = 0; i < k; i++)
		if (arr[i] > max)
		{
			max = arr[i];
			i_max = i;
		}
	cout << "Pn(n1,n2,...,nk) = n!/n1!*n2!*...*nk! = " << n << "!/" << arr[0];
	for (int i = 1; i < k; i++) {
		cout << "!*" << arr[i];
	}
	P = P * n;
	cout << "! = " << n;
	for (int i = 1; i < n - max; i++) {
		P = P * (n-i);
		cout << "*" << (n - i);
	}
	bool f = 0;
	if (arr[0] == max) { arr[0] = 1;  f = 1; }
	P = P / fact(arr[0]);
	cout << "/ " << arr[0];
	for (int i = 1; i < k; i++) {
		if ((arr[i] == max) && (!f)) 
		{
			arr[i] = 1; f = 1;
		}
		P = P / fact(arr[i]);
		cout << "!*" << arr[i];
	}
	cout << "!"<< endl << "Ответ: " << P << endl;
}
void placements3()
{
	cout << endl;
	cout << "Нахождение числа размещений без повторений из n объектов по k." << endl;
	cout << "Введите число n: " << endl;
	cin >> n;
	cout << "Введите число k: " << endl;
	cin >> k;
	A = 1;
	cout << "A(k,n) = n!/(n-k)! = " << n << "!/(" << n - k << ")! = ";
	for (int i = 1; i < k; i++) {
		A = A * (n - k + i);
		cout << (n - k + i) << "*";
	}
	A = A * (n - k + k);
	cout << (n - k + k) << endl << "Ответ: " << A << endl;
}
void placem_repeat4()
{
	cout << endl;
	cout << "Нахождение числа размещений с повторениями из n объектов по k." << endl;
	cout << "Введите число n : " << endl;
	cin >> n;
	cout << "Введите число k : " << endl;
	cin >> k;
	cout << "[A(k,n) = n^k = " << n << "^" << k << endl;
	A = pow(n, k);
	cout << "Ответ: " << A << endl;
}
void combinations5()
{
	cout << endl;
	cout << "Нахождение числа сочетаний без повторений из n объектов по k." << endl;
	cout << "Введите число n: " << endl;
	cin >> n;
	cout << "Введите число k: " << endl;
	cin >> k;
	C = 1;
	cout << "C(k,n) = n!/(n-k)!k! = " << n << "!/" << n - k << "!" << k << "! = ";
	for (int i = 1; i < k; i++) {
		C = C * (n - k + i);
		cout << (n - k + i) << "*";
	}
	C = C * (n - k + k);
	C = C / fact(k);
	cout << (n - k + k) << "/" << k << "!" << endl << "Ответ: " << C << endl;
}
void comb_repeat6()
{
	cout << endl;
	cout << "Нахождение числа сочетаний с повторениями из n объектов по k." << endl;
	cout << "Введите число n: ";
	cin >> n;
	cout << "Введите число k: ";
	cin >> k;
	C = 1;
	cout << "[C(k,n) = (k+n-1)!/(n-1)!k! = " << k+n-1 << "!/" << n - 1 << "!" << k << "! = ";
	for (int i = 1; i < k; i++) {
		C = C * (n + k - i);
		cout << (n + k - i) << "*";
	}
	C = C * (n + k - k);
	C = C / fact(k);
	cout << (n + k - k) << "/" << k << "!" << endl << "Ответ: " << C << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int click, close = 0;
	if (close == 0) {
		do {
			cout << endl;
			cout << "\tВыберите действие: " << endl;
			cout << "1.Перестановки" << endl;
			cout << "2.Перестановки с повторениями" << endl;
			cout << "3.Размещения" << endl;
			cout << "4.Размещения с повторениями" << endl;
			cout << "5.Сочетания" << endl;
			cout << "6.Сочетания с повторениями" << endl;
			cout << "7.Выход из программы" << endl;
			cout << endl;
			cin >> click;

			switch (click)
			{
			case 1:
			{
				permutation1();
				break;
			}
			case 2:
			{
				permut_repeat2();
				break;
			}
			case 3:
			{
				placements3();
				break;
			}
			case 4:
			{
				placem_repeat4();
				break;
			}
			case 5:
			{
				combinations5();
				break;
			}
			case 6:
			{
				comb_repeat6();
				break;
			}

			case 7:
			{
				cout << endl;
				cout << "Программа завершила свою работу!";
				cout << endl;
				close = 1;
				break;
			}
			default:
				break;
			}

		} while (close != 1);
	}
	return 0;
}
