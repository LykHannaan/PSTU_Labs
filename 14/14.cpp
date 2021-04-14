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
    int n_passport;
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
		person[i].n_passport = 10000 + rand() % 70001;
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
			fout << person[i].address << endl;
			fout << person[i].n_passport << endl << endl;
		}
	}
	fout.close();
}

int BoyerM(Data* person, string key)
{
	string line;
    int stl, subsl;
	for (int t = 0; t < n; t++)
	{
		line = person[t].full_name;
		stl = line.size();
		subsl = key.size();
		if (stl != 0 && subsl != 0 && stl >= subsl)
		{
			int i, p;
			int b[256];     
			for (i = 0; i < 256; i++)
			{
				b[i] = subsl;     
			}
			for (i = subsl - 2; i >= 0; i--)  
			{
				if (b[int(unsigned char(key[i]))] == subsl)    
				{
					b[int(unsigned char(key[i]))] = subsl - i - 1; 
				}
			}
			p = subsl - 1; 
			while (p < stl) 
			{
				if (key[subsl - 1] != line[p])   
				{
					p += b[int((unsigned char)line[p])];  
				}
				else    
				{
					for (i = subsl - 1; i >= 0; i--)  
					{
						if (key[i] != line[p - subsl + i + 1])  
						{
							p += b[int((unsigned char)line[p])];    
							break;  
						}
						else if (i == 0) 
						{
							return t; 
						}
					}
				}
			}
		}
	}
		return -1; 
	
}


int KnMorPr(Data* person, string key) {
	int  strl, subsl;
	int res = -1, num;
	string line;
	for (int t = 0; t < n; t++)
	{
		line = person[t].full_name;
		strl = line.size();
		subsl = key.size();
		if (strl == 0)
			cout << "Неверно задана строка\n";
		else if (subsl == 0)
			cout << "Неверно задана подстрока\n";
		else {
			int  i, j = 0, k = -1;
			int* d;
			d = new int[1000];
			d[0] = -1;
			while (j < subsl - 1) {
				while (k >= 0 && key[j] != key[k])
					k = d[k];
				j++;
				k++;
				if (key[j] == key[k])
					d[j] = d[k];
				else
					d[j] = k;
			}
			i = 0;
			j = 0;
			while (j < subsl && i < strl) {
				while (j >= 0 && line[i] != key[j])
					j = d[j];
				i++;
				j++;
			}
			delete[] d;
			if (j == subsl)
			{
				res = t;
				break;
			}
			else res = -1;

		}
	}
	return res;
}

void Sort(Data* person)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j >= (i + 1); j--)
		{
			if (person[j - 1].n_passport > person[j].n_passport)
			{
				Data person_sort = person[j];
				person[j] = person[j - 1];
				person[j - 1] = person_sort;
			}
		}
	}
}

int interp_search(Data* person, int key_num)
{
	int mid, left = 0, right = n - 1;
	while (person[left].n_passport <= key_num && person[right].n_passport >= key_num)
	{
		mid = left + ((key_num - person[left].n_passport) * (right - left)) / (person[right].n_passport - person[left].n_passport);
		if (person[mid].n_passport < key_num) left = mid + 1;
		else if (person[mid].n_passport > key_num) right = mid - 1;
		else return mid;
	}
	if (person[left].n_passport == key_num) return left;
	else return -1;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int click, close = 0;
	srand(time(NULL));
	n = 3;
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
					getline(fout, person1[i].full_name);
					getline(fout, person1[i].DOB);
					getline(fout, person1[i].address);
					fout >> person1[i].n_passport;
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
			cout << endl;
			cout << "\tВыберите метод поиска: " << endl;
			cout << "1.Метод поиска Бойера-Мура" << endl;
			cout << "2.Метод поиска Кнута-Морриса-Пратта" << endl;
			cout << "3.Интерполяционный поиск в файле" << endl;
			cout << "4.Выход" << endl;
			cout << endl;
			cin >> click;

			switch (click)
			{
			case 1:
			{
				cin.get();
				cout << "Введите фамилию или имя человека, данные о котором хотите найти: ";
				getline(cin, key);
				int alt = BoyerM(person1, key);
				if (alt != -1) 
					cout << "Элемент найден. Номер элемента в списке: " << alt + 1 << endl;
				else cout << "Элемент не найден" << endl;
				break;
			}
			case 2:
			{
				cin.get();
				cout << "Введите фамилию или имя человека, данные о котором хотите найти: ";
				getline(cin, key);
				int alt = KnMorPr(person1, key);
				if (alt != -1)
					cout << "Элемент найден. Номер элемента в списке: " << alt + 1 << endl;
				else cout << "Элемент не найден" << endl;
				break;
			}
			case 3:
			{
				int key_num;
				cout << endl;
				cout << "Введите номер паспорта человека, данные о котором хотите найти: ";
				cin >> key_num;

				Sort(person1);
				print_to_file(person1);
				int element = interp_search(person1, key_num);

				if (element != -1)
					cout << "Элемент найден. Номер элемента в отсортированном списке: " << element + 1 << endl;
				else
					cout << "Элемент с введенным номером не найден" << endl;
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
