#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
FILE* fp;

struct Shopcar
{
	string brand;
	int ReleaseYear = 0;
	string price;
	string color;
};

void to_form(Shopcar* car, int n)
{
	fp = fopen("str.txt", "w");
	for (int i = 0; i < n; i++)
	{
		cout << "Введите марку: ";
		cin >> car[i].brand;
		cout << "Введите год выпуска: ";
		cin >> car[i].ReleaseYear;
		cout << "Введите цену: ";
		cin >> car[i].price;
		cout << "Введите цвет: ";
		cin >> car[i].color;
		cout << endl;
	}
	if ((fp = fopen("str.txt", "rb")) == NULL)
	{
		perror("Ошибка при открытии файла");
		exit(0);
	}
	fwrite(&car, sizeof(Shopcar), 1, fp);
	fclose(fp);
}

void print(Shopcar* car, int n)
{
	FILE* fp;

	if ((fp = fopen("str.txt", "rb")) == NULL)
	{
		perror("Ошибка при открытии файла");
		exit(0);
	}
	else
	{
		for (int i = 0; i < n; i++) {
			cout << car[i].brand << " ";
			cout << car[i].ReleaseYear << " ";
			cout << car[i].price << " ";
			cout << car[i].color << endl;
		}
	}
	fwrite(&car, sizeof(Shopcar), 1, fp);
	fclose(fp);
}

void car_del(Shopcar* car, int year, int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (car[i].ReleaseYear < year)
		{
			for (int k = i; k < n - 1; k++)
			{
				car[k].brand = car[k + 1].brand;
				car[k].ReleaseYear = car[k + 1].ReleaseYear;
				car[k].price = car[k + 1].price;
				car[k].color = car[k + 1].color;
			}
			n--;
		}
	}

	if ((fp = fopen("str.txt", "rb")) == NULL)
	{
		perror("Ошибка при открытии файла");
		exit(0);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			cout << car[i].brand << " ";
			cout << car[i].ReleaseYear << " ";
			cout << car[i].price << " ";
			cout << car[i].color << endl;
		}
	}
	fread(&car, sizeof(n), 1, fp);
	fclose(fp);
}


void car_add(Shopcar* car, int& n)
{
	for (int i = 0; i < n - 1; i++)
	{
		car[i].brand = car[i + 1].brand;
		car[i].ReleaseYear = car[i + 1].ReleaseYear;
		car[i].price = car[i + 1].price;
		car[i].color = car[i + 1].color;
	}
	n++;
	cout << "Введите носитель: ";
	cin >> car[0].brand;
	cout << "Введите объём: ";
	cin >> car[0].ReleaseYear;
	cout << "Введите название: ";
	cin >> car[0].price;
	cout << "Введите автора: ";
	cin >> car[0].color;
	cout << endl;


	if ((fp = fopen("str.txt", "rb")) == NULL)
	{
		perror("Ошибка при открытии файла");
		exit(0);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			cout << car[i].brand << " ";
			cout << car[i].ReleaseYear << " ";
			cout << car[i].price << " ";
			cout << car[i].color << endl;
		}
	}
	fread(&car, sizeof(n), 1, fp);
	fclose(fp);
}

int main()
{
	setlocale(LC_ALL, "ru");

	int n, year;
	cout << "\tСколько будет записей в файле? : - ";
	while (true)
	{
		cin >> n;
		if (n > 0)
			break;
		else {
			cout << "Файл пуст" << endl;
			cout << "\tСколько будет записей в файле? : - ";
		}
	}

	Shopcar* car = new Shopcar[n];

	to_form(car, n);
	cout << endl;
	print(car, n);
	cout << endl;
	cout << "Введите год выпуска автомобиля: ";
	cin >> year;
	car_del(car, year, n);
	cout << endl;
	car_add(car, n);
	cout << endl;

	return 0;
}
