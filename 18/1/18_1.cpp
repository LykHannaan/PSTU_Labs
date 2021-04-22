#include <iostream>
#include "fraction.h"
#include "fraction.cpp"

using namespace std;

progression make_progression(double F, int S)
{
	progression t;
	t.Init(F, S);
	return t;
}

int main()
{
	progression A;
	progression B;
	int j;
	A.Init(3.0, 2);
	cout << "Введите номер элемента прогрессии: ";
	cin >> j;
	cout << "A.element(" << A.first << "," << A.second << ")=" << A.element(j) << endl;
	A.Show();

	B.Read();
	cout << "Введите номер элемента прогрессии: ";
	cin >> j;
	cout << "B.element(" << B.first << "," << B.second << ")=" << B.element(j) << endl;
	B.Show();

	progression* X = new progression;
	X->Init(2.0, 5);
	X->Show();
	X->element(j);
	cout << "Введите номер элемента прогрессии: ";
	cin >> j;
	cout << "X.element(" << X->first << "," << X->second << ")=" << X->element(j) << endl;
	X->Show();

	progression mas[3];
	for (int i = 0; i < 3; i++)
		mas[i].Read();
	for (int i = 0; i < 3; i++)
		mas[i].Show();
	for (int i = 0; i < 3; i++)
	{
		mas[i].element(i);
		cout << "mas[(" << i << "].element(" << mas[i].first << "," << mas[i].second << ")=";
		cout << mas[i].element(i) << endl;
	}

	progression* p_mas = new progression[3];
	for (int i = 0; i < 3; i++)
		p_mas[i].Read();
	for (int i = 0; i < 3; i++)
		p_mas[i].Show();
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].element(i);
		cout << "p_mas[(" << i << "].element(" << p_mas[i].first << "," << p_mas[i].second << ")=";
		cout << p_mas[i].element(i) << endl;
	}

	double y; int z;
	cout << "first?";
	cin >> y;
	cout << "second?";
	cin >> z;

	progression F = make_progression(y, z);
	F.Show();
	cout << "F.element(" << F.first << "," << F.second << ")=" << F.element(j) << endl;

	return 0;
}
