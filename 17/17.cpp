#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <iomanip>
using namespace std;

struct Table
{
	string* FIO;
	string* DOB;
	string* adress;
	Table* next;
	Table* prev;
};

Table** hashs;
int coliz = 0;

Table* create_obj(string names[], string surnames[], string patronymics[], string adress[], string year[], string month[], string day[])
{
	Table* p = new Table;
	string dob[6];
	int s;
	s = rand() % 9;
	dob[0] = year[s];
	s = rand() % 13;
	dob[1] = ' ';
	dob[2] = month[s];
	s = rand() % 31;
	dob[3] = ' ';
	dob[4] = day[s];
	p->DOB = new string[6];
	for (int i = 0; i < 6; i++)
	{
		p->DOB[i] = dob[i];
	}
	string OIF[6];
	int k;
	k = rand() % 9;
	OIF[0] = surnames[k];
	k = rand() % 9;
	OIF[1] = ' ';
	OIF[2] = names[k];
	k = rand() % 9;
	OIF[3] = ' ';
	OIF[4] = patronymics[k];
	p->FIO = new string[6];
	for (int i = 0; i < 6; i++)
	{
		p->FIO[i] = OIF[i];
	}
	string adressss[6];
	int d;
	d = rand() % 9;
	adressss[0] = adress[d];
	d = rand() % 9;
	adressss[1] = ' ';
	adressss[2] = adress[d];
	d = rand() % 9;
	adressss[3] = ' ';
	adressss[4] = adress[d];
	p->adress = new string[6];
	for (int i = 0; i < 6; i++)
	{
		p->adress[i] = adressss[i];
	}
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void Print(Table* p)
{
	cout << '\t';
	for (int i = 0; i < 6; i++)
	{
		cout << right << p->DOB[i];
	}
	cout << '\t';
	for (int i = 0; i < 1; i++)
	{
		cout << p->adress[i];
	}
	cout << '\t';
	for (int i = 0; i < 6; i++)
	{
		cout << p->FIO[i];
	}
	cout << endl;

}

int hash_func(string key[])
{
	int h = 0;
	int k = 0;
	int* ascii = new int[key[0].length()];
	for (int i = 0; i < key[0].length(); i++)
	{
		ascii[i] = key[0][i];
		k += ascii[i];
	}
	delete[]ascii;
	ascii = new int[key[2].length()];
	for (int i = 0; i < key[2].length(); i++)
	{
		ascii[i] = key[2][i];
		k += ascii[i];
	}
	delete[]ascii;
	ascii = new int[key[4].length()];
	for (int i = 0; i < key[4].length(); i++)
	{
		ascii[i] = key[4][i];
		k += ascii[i];
	}
	delete[]ascii;
	h = k % 40;
	return h;
}

void create_table(Table* p)
{
	int h = hash_func(p->DOB);
	cout << h;
	if (hashs[h] != NULL)
	{

		hashs[h]->next = p;
		p->prev = hashs[h];
		hashs[h] = hashs[h]->next;
		Print(hashs[h]);
		coliz++;
	}
	else
	{
		hashs[h] = p;
		Print(hashs[h]);
	}
}

void search_key(string key[])
{
	int h = hash_func(key);
	cout << h;
	Table* r = hashs[h];
	if (r->prev == NULL)
	{
		Print(r);
	}
	else
	{
		do
		{
			if (r->DOB[0] == key[0] && r->DOB[2] == key[2] && r->DOB[4] == key[4])
			{
				Print(r);
				return;
			}
			else
			{
				r = r->prev;
			}
		} while (r != NULL);
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	string adress[10] = { "Ëåíèíà   ","Ïëåõàíîâà","Ïåòðîïàâëîâñêàÿ","Òâåðñêàÿ","Ìèðà     ","Êðèñàíîâà","Ãàãàðèíà","Ðåâîëþöèè","Ïîïîâà   ","Ëóíà÷àðñêîãî" };
	string names[10] = { "Ìèõàèë","Äàíèèë","Àíäðåé","Àðòåì","Âàëåðèé","Ñåðãåé","Èâàí","Èãíàòèé","Êèðèëë","Ðóáèäèé" };
	string surnames[10] = { "Íîâèêîâ","Íèôîíòîâ","Ãóáàíîâ","Øâåöîâ","×àäîâ","Ìîðîçîâ","Êàëü÷èíêî","Ëóãîâêèí","Ïàíêîâ","Ïåðåâîçíèêîâ" };
	string patronymics[10] = { "Ïàâëîâè÷","Þðüåâè÷","Ãåîðãèåâè÷","Ìàêñèìîâè÷","Îëåãîâè÷","Èëüè÷","Ìèõàéëîâè÷","Èãîðåâè÷","Àëåêñàíäðîâè÷","Äìèòðåèâè÷" };
	string year[10] = { "2000","2001","2002","2003","2004","2005","2006","2007","2008","2009" };
	string month[13] = { "01","02","03","04","04","05","06","07","08","09","10","11","12" };
	string day[31] = { "01","02","03","04","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30" };
	Table* p = NULL;
	int n;
	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ òàáëèöû (íå ìåíåå 40):";
	cin >> n;
	hashs = new Table * [n];
	for (int i = 0; i < n; i++)
	{
		hashs[i] = NULL;
	}
	for (int i = 0; i < n; i++)
	{
		p = create_obj(names, surnames, patronymics, adress, year, month, day);
		create_table(p);
	}
	cout << "Êîëè÷åñòâî êîëëèçèé:" << coliz << endl;
	cout << "Ââåäèòå äàòó ðîæäåíèÿ:";
	string search[6];
	cin >> search[0];
	cin >> search[2];
	cin >> search[4];
	search[1] = ' '; search[3] = ' ';
	search_key(search);
}
