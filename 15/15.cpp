#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

int n;

struct newspaper
{
	string name;
	int edition;
};

void Shell_sort(newspaper* z)
{
	int d, count;
	d = n;
	d = d / 2;
	while (d > 0)
	{
		for (int i = 0; i < n - d; i++)
		{
			int j = i;
			while (j >= 0 && z[j].edition > z[j + d].edition)
			{
				count = z[j].edition;
				z[j] = z[j + d];
				z[j + d].edition = count;
				j--;
			}
		}
		d = d / 2;
	}
}

void Hoar_sort(newspaper* zz, int first, int last)
{
	int m, c;
	string t;
	int f = first, l = last;
	m = zz[(f + l) / 2].edition;
	while (f <= l)
	{
		while (zz[f].edition > m && f < last) f++;
		while (zz[l].edition < m && l > first) l--;
		if (f <= l)
		{
			c = zz[f].edition;
			zz[f].edition = zz[l].edition;
			zz[l].edition = c;

			t = zz[f].name;
			zz[f].name = zz[l].name;
			zz[l].name = t;

			f++;
			l--;

	    }
    }

if (f < last) Hoar_sort(zz, f, last);
if (first < l) Hoar_sort(zz, first, l);
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int click, close = 0;
	int first = 0; 
	int last = n - 1;
	cout << "Введите кол-во газет: ";
	cin >> n;
	newspaper* st = new newspaper[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Название газеты: ";
		cin >> st[i].name;
		cout << "Тираж: ";
		cin >> st[i].edition;
	}

	cout << endl;
	cout << "\tКаким методом хотите отсортировать газеты?" << endl;
	cout << "1.Методом Шелла" << endl;
	cout << "2.Методом Хоара" << endl;
	cout << endl;
	cin >> click;

	switch (click)
	{
	case 1:
		Shell_sort(st);
		break;
	case 2:
		Hoar_sort(st, first, last);
		break;
	default:
		break;
	}

	cout << "Отсортированный список: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Название газеты №" << i + 1 << " : " << st[i].name;
		cout << endl;
		cout << "Тираж " << st[i].edition;
		cout << endl;
	}

	return 0;
}
