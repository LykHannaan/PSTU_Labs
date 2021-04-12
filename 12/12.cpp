#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

string key;
string surname, name, middle_name, street, town;
int n, i, j;


struct Data
{
	string full_name;
	string DOB;
	string address;
};

void make_random(Data* person)
{
	int k;
	k = rand() % 6;
	switch (k)
	{
	case 1:
		surname = "Connery";
		name = "Alex";
		middle_name = "Hayden";
		street = "Westminster Avenue";
		town = "Brooklyn";
		break;
	case 2:
		surname = "Allen";
		name = "Woody";
		middle_name = "Reagan";
		town = "Los Angeles";
		street = "7th Street";
		break;
	case 3:
		surname = "Miller";
		name = "Emery";
		middle_name = "James";
		street = "Fordham Dr.";
		town = "St Paul";
		break;
	case 4:
		surname = "Wilson";
		name = "Harper";
		middle_name = "Joseph";
		street = "Dominica Circle";
		town = "Niceville";
		break;
	case 5:
		surname = "Brown";
		name = "Charlie";
		middle_name = "Sean";
		street = "Hood St";
		town = "New York";
		break;
	default:
		break;
	}
}

void to_form(Data* person)
{
	int a = 0, d, m, y;
	string surname1, name1, middle_name1, street1, town1;

	for (i = 0; i < n; i++) {

		make_random(person);
		surname1 = surname;
		make_random(person);
		name1 = name;
		make_random(person);
		middle_name1 = middle_name;
		person[i].full_name = surname1 + " " + name1 + " " + middle_name1;

		d = 1 + rand() % 31;
		m = 1 + rand() % 12;
		y = rand() % 122 + 1950;

		auto day = to_string(d);
		auto month = to_string(m);
		auto year = to_string(y);

		person[i].DOB = month + "." + day + "." + year;

		a = rand() % 1000;
		auto Apt = to_string(a);

		make_random(person);
		street1 = street;
		make_random(person);
		town1 = town;
		person[i].address = Apt + " " + street1 + ", " + town1;
	}
}

void print_to_file(Data* person)
{
	ofstream fout;
	fout.open("Data+.txt");

	if (!fout.is_open())
	{
		perror("Ошибка при открытии файла");
		exit(0);
	}
	else {
		for (int i = 0; i < n; i++) {
			fout << i + 1 << ".\t";
			fout << person[i].full_name << endl;
			fout << person[i].DOB << endl;
			fout << person[i].address << endl << endl;
		}
	}
	fout.close();
}

void Line_search1(Data* person, string key)
{
	int res = -1;
	for (i = 0; i < n; i++)
	{
		if (person[i].full_name == key) res = i;
	}
	if (res != -1)
	{
		cout << "Элемент в списке найден. Он находится под номером " << res + 1;
	}
	else cout << "Элемента в списке нет";
}

int search3(Data* person, string key)
{
	int str1, key1, res = -1;
	key1 = key.size();

	for (int t = 0; t < n; t++) {
		str1 = person[t].full_name.size();

		if (str1 != 0 && key1 != 0)
		{
			for (i = 0; i < str1 - key1 + 1; i++)
			{
				for (j = 0; j < key1; j++)
				{
					if (key[j] != person[t].full_name[i + j]) break;
					else if (j == key1 - 1)
					{
						res = i;
						break;
					}
				}
			}
		}
	}
	if (res != -1)
	{
		cout << "Элемент в списке найден. Он находится под номером " << res + 1;
	}
	else cout << "Элемента в списке нет" << endl;

	return 0;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int click, close = 0;
	srand(time(NULL));
	n = 5;
	cout << "\tЗаписей в файле: - " << n;

	Data* person1 = new Data[n];

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
			{
				cout << endl;
				cout << "Программа завершила свою работу!";
				cout << endl;
				close = 1;
				break;
			}
			case 2:
			{
				n = rand() % 1000 - 500;
				cout << "\tЗаписей в файле: - " << n;
				break;
			}
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
			cout << "1.Линейный поиск в файле" << endl;
			cout << "2.Прямой поиск подстроки в строке в файле" << endl;
			cout << "3.Выход" << endl;
			cout << endl;
			cin >> click;

			switch (click)
			{
			case 1:
			{
				to_form(person1);
				print_to_file(person1);
				cin.get();
				cout << "Введите ФИО человека, данные о котором хотите найти: ";
				getline(cin, key);
				Line_search1(person1, key);
				break;
			}
			case 2:
			{
				to_form(person1);
				print_to_file(person1);
				cin.get();
				cout << "Введите фамилию человека, данные о котором хотите найти: ";
				getline(cin, key);
				search3(person1, key);
				break;
			}
			case 3:
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
