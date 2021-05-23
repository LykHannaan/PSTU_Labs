#pragma once
#include "Pair.h" 
#include <iostream> 
#include <fstream> 
using namespace std;
int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream)
		return -1;
	int n;
	Pair p;
	cout << "Êîë-âî?";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p << "\n";
	}
	stream.close();
	return n;
}
int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	Pair p;
	int i = 0;
	while (stream >> p)
	{
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}
void del_file(const char* f_name, Pair k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
	{
		cout << "Îøèáêà îòêðûòèÿ" << endl;
		return;
	}
	Pair p;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		if (p != k)
			temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
}
void add_file(const char* f_name, Pair pp, int s)

{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
	{
		cout << "Îøèáêà îòêðûòèÿ" << endl;
		return;
	}
	Pair p;
	int l = 0;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		temp << p;
		if (p == pp)
		{
			for (int j = 0; j < s; j++)
			{
				Pair p1;
				cin >> p1;
				temp << p1;
				l++;
			}
		}
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
}
void change_file(const char* f_name, Pair k, Pair pp)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
	{
		cout << "Îøèáêà îòêðûòèÿ" << endl;
		return;
	}
	Pair p;
	char x;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		if (p == pp)
		{
			p = p - k;
			temp << p;
		}
		else
			temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
}