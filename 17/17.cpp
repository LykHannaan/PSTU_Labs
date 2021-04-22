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
	string fio;
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
		person[i].fio = surname1 + " " + name1 + " " + middle_name1;

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
			fout << person[i].fio << endl;
			fout << person[i].DOB << endl;
			fout << person[i].address << endl << endl;
		}
	}
	fout.close();
}

int GetK(string key) {
	int K = 0;
	int j = 1;
	for (int i = 0; i < key.length(); i++) {
		K += key[i] * j;
		j++;
	}
	return K;
}

int Hash(string key, int size)
{
	return int(GetK(key) % size);
}

void Make_Table(int size, Data* person2)
{
	int n = size;
	int* table = new int[size];
	int Hashsize = size;
	for (int i = 0; i < size; i++)
	{
		table[i] = 0;
	}
	int collis = 0;
	for (int k = 0; k < n; k++)
	{
		int num;
		int hash = Hash(person2[k].fio, Hashsize);
		if (table[hash] == 0)
		{
			table[hash] = k;
		}
		else
		{
			num = hash;
			while (num < size && table[num] != 0)
			{
				collis++;
				num++;
			}
			if (num >= size)
			{
				size *= 2;
				int* temptable = new int[size];
				for (int i = 0; i < size / 2; i++)
				{
					temptable[i] = table[i];
				}
				for (int i = size / 2; i < size; i++)
				{
					temptable[i] = 0;
				}
				delete[]table;
				table = temptable;
			}
			if (table[num] == 0)
			{
				table[num] = k;
			}
		}
	}
	cout << "Число коллизий: " << collis << endl;
	cout << "Введите ФИО человека, данные о котором хотите найти: ";
	string key;
	cin.get();
	getline(cin, key);
	int hashkey = Hash(key, Hashsize);
	if (person2[table[hashkey]].fio == key)
	{
		cout << "Элемент найден: " << endl;
		cout << "	" << person2[table[hashkey]].fio << endl;
		cout << "	" << person2[table[hashkey]].DOB << endl;
		cout << "	" << person2[table[hashkey]].address << endl;
	}
	else
	{
		while (person2[table[hashkey]].fio != key && hashkey < size / 2)
		{
			hashkey++;
		}
		if (person2[table[hashkey]].fio == key)
		{
			cout << "Элемент найден: " << endl;
			cout << "	" << person2[table[hashkey]].fio << endl;
			cout << "	" << person2[table[hashkey]].DOB << endl;
			cout << "	" << person2[table[hashkey]].address << endl;
		}
		else
			cout << "Элемент не найден";
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int click, close = 0;
	srand(time(NULL));
	n = rand() % 500;
	cout << "\tЗаписей в файле: - " << n;

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
				n = rand() % 500;
				cout << "\tЗаписей в файле: - " << n;
				break;
			}
			default:
				break;
			}

			break;
		}
	}
	Data* person1 = new Data[n];

	if (close == 0) {
		do {
			cout << endl;
			cout << "\tЧто вы хотите сделать?" << endl;
			cout << "1.Сформировать файл" << endl;
			cout << "2.Открыть готовый файл" << endl;
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
					getline(fout, person1[i].fio);
					getline(fout, person1[i].DOB);
					getline(fout, person1[i].address);
					getline(fout, row);
					i++;
				}
				fout.close();
				cout << "Список загружен." << endl << endl;
				break;
			}
			default:
				break;
			}
			Make_Table(n, person1);
			break;

		} while (close != 1);
	}
	return 0;
}
