#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

string key;
string surname, name, middle_name, street, town;
int n;

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
	ofstream fout;
	fout.open("Data+.txt");

	if (!fout.is_open())
	{
		perror("Ошибка при открытии файла");
		exit(0);
	}
	else {
		Data* person = new Data[n];

		int a = 0, d, m, y;
		string surname1, name1, middle_name1, street1, town1;

		for (int i = 0; i < n; i++) {

			fout << i + 1 << ".\t";
			make_random(person);
			surname1 = surname;
			make_random(person);
			name1 = name;
			make_random(person);
			middle_name1 = middle_name;
			person[i].full_name = surname1 + " " + name1 + " " + middle_name1;
			fout << person[i].full_name << endl;

			d = 1 + rand() % 31;
			m = 1 + rand() % 12;
			y = rand() % 122 + 1950;

			auto day = to_string(d);
			auto month = to_string(m);
			auto year = to_string(y);

			person[i].DOB = month + "." + day + "." + year;
			fout << person[i].DOB << endl;

			a = rand() % 1000;
			auto Apt = to_string(a);

			make_random(person);
			street1 = street;
			make_random(person);
			town1 = town;
			person[i].address = Apt + " " + street1 + ", " + town1;
			fout << person[i].address << endl << endl;
		}
	}
	fout.close();
}



void del(Data* person, int m)
{
	ofstream fout;
	fout.open("Data+.txt");
	if (!fout.is_open())
	{
		perror("Ошибка при открытии файла");
		exit(0);
	}
	else
	{
		cout << "Файл открыт!" << endl;

		for (int i = m+1; i < n; i++)
		{
			person[i] = person[i + 1];
			n--;
		}
	}
	for (int i = m + 1; i < n; i++) {

		fout << i + 1 << ".\t";
		fout << person[i].full_name << endl;
		fout << person[i].DOB << endl;
		fout << person[i].address << endl << endl;
	}
	fout.close();
}

void add(Data* person, int m)
{
	ofstream fout;
	fout.open("Data+.txt");
	if (!fout.is_open())
	{
		perror("Ошибка при открытии файла");
		exit(0);
	}
	else
	{
		cout << "Файл открыт!" << endl;
		int i, m;
		cout << "Под каким номером вы хотите добавить новые данные?: " << endl;
		cin >> m;
		for (i = m; i < n + 1; i++)
		{
			person[i + 1] = person[i];
		}
		cout << "Введите ФИО человека, данные о котором хотите добавить: ";
		cin >> person[m].full_name; 
		cout << "Введите дату рождения: ";
		cin >> person[m].DOB;
		cout << "Введите адрес: ";
		cin >> person[m].address;
		cout << endl;

		for (i = m; i < n + 1; i++)
		{
			fout << i + 1 << ".\t";
			fout << person[i].full_name << endl;
			fout << person[i].DOB << endl;
			fout << person[i].address << endl << endl;
		}
	}

	fout.close();
}

void add_del(Data* person, int res)
{
	bool boop;
	cout << "\tЧто вы хотите сделать?" << endl;
	cout << "0.Удаление данных из файла" << endl;
	cout << "1.Добавление новых данных в файл" << endl;
	cin >> boop;
	if (!boop) 
	{
		del(person, res);
		cout << "Данные удалены" << endl;
	}
	else add(person, res);
}

void Line_search1(Data* person, string key)
{
	int res = -1;
	for (int i = 0; i < n; i++)
	{
		if (person[i].full_name == key) res = i;
	}
	if (res != -1)
	{
		cout << "Элемент в списке найден. Он находится под номером " << res + 1;
		add_del(person, res);
	}
	else cout << "Элемента в списке нет";
}

int search3(Data* person, string key)
{
	int str1, key1, res = -1;

	str1 = person[0].full_name.size(); 
	key1 = key.size();

	for (int t = 0; t < n; t++)
		if (str1 != 0 && key1 != 0)
		{
			for (int i = 0; i < str1 - key1 + 1; i++)
			{
				for (int j = 0; j < key1; j++)
				{
					if (key[j] != person[t].full_name[i + j]) break;
					else if (j == key1 - 1)
					{
						res = i;
						break;
					}
				}
			}
			if (res != -1)
			{
				cout << "Элемент в списке найден. Он находится под номером " << res;
				add_del(person, res);
			}
			else cout << "Элемента в списке нет";
		}
	return 0;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int click, close = 0;
	srand(time(NULL));
	n = rand() % 100 + 100;
	cout << "\tЗаписей в файле: - " << n;

	Data* person = new Data[n];
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
			cout << "1.Сформировать файл" << endl;
			cout << "2.Линейный поиск в файле" << endl;
			cout << "3.Прямой поиск подстроки в строке" << endl;
			cout << "4.Выход" << endl;
			cout << endl;
			cin >> click;

			switch (click)
			{
			case 1:
				    to_form(person);
				break;
			case 2:
			{
				cin.get();
				cout << "Введите ФИО человека, данные о котором хотите найти: ";
				getline(cin, key);
				Line_search1(person, key);
				break;
			}
			
			case 3:
			{
				cin.get();
				cout << "Введите ФИО человека, данные о котором хотите найти: ";
				getline(cin, key);
				search3(person, key);
				break;
			}
			case 4:
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
