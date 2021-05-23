#include "Pair.h" 
#include <iostream>
#include <fstream> 
#include <string> 
#include "file.h" 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	Pair p, p6;
	int k, c;
	char file_name[30];
	c = -1;
	while (c != 0)
	{
		cout << "\n1. Создание файла";
		cout << "\n2. Вывод файла";
		cout << "\n3. Удаление из файла";
		cout << "\n4. Добавление в файл";
		cout << "\n5. Изменение значений в файле";
		cout << "\n0. Выход\n";
		cout << "Выбрать: ";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Имя файла?";
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0)
				cout << "Can't make file";
			break;
		case 2:
			cout << "Имя файла: ";
			cin >> file_name;
			k = print_file(file_name);
			if (k == 0)
				cout << "Пустой файл\n";
			if (k < 0)
				cout << "Невозможно считать файл\n";
			break;
		case 3:
			cout << "Имя файла: ";
			cin >> file_name;
			cout << "Максимальное значение, записи меньшие которого нужно удалить? ";
			cin >> p;
			del_file(file_name, p);
			break;
		case 4:
			cout << "Имя файла: ";
			cin >> file_name;
			cout << "Кол-во элементов для добавления: ";
			int kol;
			cin >> kol;
			cout << "Значение, после которого нужно добавить: ";
			cin >> p;
			add_file(file_name, p, kol);
			break;
		case 5:
			cout << "Имя файла: ";
			cin >> file_name;
			cout << "Значение, которое нужно изменить: ";
			cin >> p;
			cout << "Значение, которое нужно прибавить: ";
			cin >> p6;
			change_file(file_name, p6, p);
			break;
		}
	}
}
