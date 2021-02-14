#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>

using namespace std;
FILE* fp;
   struct Shopcar
   {
	   string brand;
	   int ReleaseYear = 0;
	   int price = 0 ;
	   string color;
   };

	void to_form(Shopcar * car, int n)
	{
#pragma warning(suppress : 4996)
		fp = fopen("str.txt", "wb");

		  for (int i = 0; i < n; i++)
		  {
			cout << "Введите марку: ";
			cin >> car[i].brand;
			cout << "Введите год выпуска: ";
			cin >> car[i].ReleaseYear;
			   while (true)
			   {
				   if ((car[i].ReleaseYear > 1900) and (car[i].ReleaseYear < 2021))
					 break;
				   else {
					 cout << endl;
					 cout << "_____ОШИБКА! ВВЕДЕНЫ НЕКОРРЕКТНЫЕ ДАННЫЕ_____" << endl;
					 cout << endl;
					 cout << "Введите год выпуска: ";
					 cin >> car[i].ReleaseYear;
				   }
			   }
			cout << "Введите цену: ";
			cin >> car[i].price;
			   while (true)
			   {
				   if (car[i].price > -1)
					 break;
				   else {
					 cout << endl;
					 cout << "_____ОШИБКА! ВВЕДЕНЫ НЕКОРРЕКТНЫЕ ДАННЫЕ_____" << endl;
					 cout << endl;
					 cout << "Введите цену: ";
					 cin >> car[i].price;
				   }
			   }
			cout << "Введите цвет: ";
			cin >> car[i].color;
			cout << endl;
		  }
#pragma warning(suppress : 4996)
		if ((fp = fopen("str.txt", "r+b")) == NULL)
		{
			perror("Ошибка при открытии файла");
			exit(0);
		}
		fwrite(&car, sizeof(Shopcar), 1, fp);
		fclose(fp);
	}

	void print(Shopcar * car, int n)
	{
		FILE* fp;
#pragma warning(suppress : 4996)
		if ((fp = fopen("str.txt", "rb")) == NULL)
		{
			perror("Ошибка при открытии файла");
			exit(0);
		}
		else
		{
			for (int i = 0; i < n; i++) {
				cout << i+1 << ". ";
				cout << "  " << car[i].brand << endl;
				cout << "Год выпуска: " << car[i].ReleaseYear << endl;
				cout << "Цена: " << car[i].price << endl;
				cout << "Цвет: " << car[i].color << endl;
				cout << endl;
			}
		}
		fwrite(&car, sizeof(Shopcar), 1, fp);
		fclose(fp);
	}

	void car_del(Shopcar * car, int year, int& n)
	{
		for (int i = 0; i < n; i++)
		{
			if (car[i].ReleaseYear < year)
			{
				for (int j = i; j < n - 1; j++)
				{
					car[j] = car[j + 1];
				}
				n--;
				i = -1;
			}
		}
#pragma warning(suppress : 4996)
		if ((fp = fopen("str.txt", "r+b")) == NULL)
		{
			perror("Ошибка при открытии файла");
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "\tСписок подходящих вам автомобилей:"<< endl;
			for (int i = 0; i < n; i++)
			{
				cout << i + 1 << ". ";
				cout << "  " << car[i].brand << endl;
				cout << "Год выпуска: " << car[i].ReleaseYear << endl;
				cout << "Цена: " << car[i].price << endl;
				cout << "Цвет: " << car[i].color << endl;
				cout << endl;
			}
		}
		fread(&car, sizeof(n), 1, fp);
		fclose(fp);
	}

	void car_add(Shopcar * car, int& n)
	{
		for (int i = 0; i < n; i++)
		{
			car[n-i] = car[n-i-1];
		}
		n++;
		cout << "Введите марку автомобиля: ";
		cin >> car[0].brand;
		cout << "Введите год выпуска: ";
		cin >> car[0].ReleaseYear;
		cout << "Введите цену: ";
		cin >> car[0].price;
		cout << "Введите цвет: ";
		cin >> car[0].color;
		cout << endl;

#pragma warning(suppress : 4996)
		if ((fp = fopen("str.txt", "r+b")) == NULL)
		{
			perror("Ошибка при открытии файла");
			exit(0);
		}
		fread(&car, sizeof(n), 1, fp);
		fclose(fp);
	}

	int main()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int n, year;
		int click, close = 0;
		cout << "\tСколько будет записей в файле? : - ";
		cin >> n;
		Shopcar* car = new Shopcar[n];
		while (true)
		{
			if (n > 0)
				break;
			else {
				cout << endl;
				cout << "Файл пуст!" << endl;
				cout << endl;
				cout << "\tЗавершить работу программы? - ";
				cout << "1.Да/2.Нет" << endl;
				cin >> click;
					switch (click)
					{
					case 1:
						cout << endl;
						cout << "Программа завершила свою работу!";
						cout << endl;
						close = 1;
						break;
					case 2:
						cout << "\tСколько будет записей в файле? : - ";
						cin >> n;
						break;
					default:
						break;
					}

			break;
			} 
		}
		if (close == 0) {
			do
			{
				cout << endl;
				cout << "\tЧто вы хотите сделать?" << endl;
				cout << "1.Сформировать файл" << endl;
				cout << "2.Печать файла" << endl;
				cout << "3.Удаление из файла" << endl;
				cout << "4.Добавление в файл" << endl;
				cout << "5.Выход" << endl;
				cout << endl;
				cin >> click;

				switch (click)
				{
				case 1:
					to_form(car, n);
					break;
				case 2:
					print(car, n);
					break;
				case 3:
				{
					cout << endl;
					cout << "Введите минимальный год выпуска автомобиля: ";
					cin >> year;
					car_del(car, year, n);
					break;
				}
				case 4:
				{
					car_add(car, n);
					break;
				}
				case 5:
					cout << endl;
					cout << "Программа завершила свою работу!";
					cout << endl;
					close = 1;
					break;
				default:
					break;
				}

			} while (close != 1);
		}
		return 0;
	}
