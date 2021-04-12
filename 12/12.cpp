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
			fout << i + 1 << endl;
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

void search2(Data* person, string key)
{
	string line;
	for (int i = 1; i <= n; i++)
	{
		line = line + to_string(i) + person[i - 1].full_name;
	}
	int str, substr, res = -1;

	str = line.size();
	substr = key.size();
	if (str != 0 && substr != 0)
	{
		for (int i = 0; i < str - substr + 1; i++)
		{
			for (int j = 0; j < substr; j++)
			{
				if (key[j] != line[i + j]) break;
				else if (j == substr - 1)
				{
					res = i;
					break;
				}
			}
		}
		if (res != -1) cout << "Элемент в списке найден. Он находится под номером " << line[res - 1];
		else cout << "Элемента в списке нет";
	}
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
		do{
		cout << endl;
		cout << "\tЧто вы хотите сделать?" << endl;
		cout << "1.Сформировать файл" << endl;
		cout << "2.Открыть готовый файл" << endl;
		cout << "3.Выход" << endl;
		cout << endl;
		cin >> click;

		switch (click)
		{
		case 1:
		{
			to_form(person1);
			print_to_file(person1);
			break;
		}
		case 2:
		{
			int count = 0;
			string row;
			ifstream fout;
			fout.open("Data+.txt");
			while (!fout.eof())
			{
				count++;
				getline(fout, row);
			}
			n = count / 4;
			person1 = new Data[n];
			fout.close();
			fout.open("Data+.txt");
			int i = 0;
			while (!fout.eof())
			{
				getline(fout, row);
				getline(fout, person1[i].full_name);
				getline(fout, person1[i].DOB);
				getline(fout, person1[i].address);
				getline(fout, row);
				i++;
			}
			fout.close();
			cout << "Список загружен." << endl << endl;
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
			cout << endl;
			cout << "\tВыберите метод поиска: " << endl;
			cout << "1.Линейный поиск в файле" << endl;
			cout << "2.Прямой поиск подстроки в строке в файле" << endl;
			cout << "3.Выход" << endl;
			cout << endl;
			cin >> click;

			switch (click)
			{
			case 1:
			{
				cin.get();
				cout << "Введите ФИО человека, данные о котором хотите найти: ";
				getline(cin, key);
				Line_search1(person1, key);
				break;
			}
			case 2:
			{
				cin.get();
				cout << "Введите фамилию человека, данные о котором хотите найти: ";
				getline(cin, key);
				search2(person1, key);
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
