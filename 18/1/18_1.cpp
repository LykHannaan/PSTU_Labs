#include <iostream>
#include "fraction.h"
#include "fraction.cpp"

using namespace std;

fraction make_fraction(double F, int S, int G)
{
	fraction t;
	t.Init(F, S, G);
	return t;
}
int main()
{
	fraction A;
	fraction B;
	A.Init(3.0, 2, 4);
	B.Read();
	A.Show();
	B.Show();
	cout << "A.element(" << A.first << "," << A.second << ")=" << A.element() << endl;
	cout << "B.element(" << B.first << "," << B.second << ")=" << B.element() << endl;
	fraction* X = new fraction;
	X->Init(2.0, 5, 6);
	X->Show();
	X->element();
	cout << "X.Power(" << X->first << "," << X->second << ")=" << X->element() << endl;
	fraction mas[3];
	for (int i = 0; i < 3; i++)
		mas[i].Read();
	for (int i = 0; i < 3; i++)
		mas[i].Show();
	for (int i = 0; i < 3; i++)
	{
		mas[i].element();
		cout << "mas[(" << i << "].element(" << mas[i].first << "," << mas[i].second << ")=";
		cout << mas[i].element() << endl;
	}

	fraction* p_mas = new fraction[3];
	for (int i = 0; i < 3; i++)
		p_mas[i].Read();
	for (int i = 0; i < 3; i++)
		p_mas[i].Show();
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].element();
		cout << "p_mas[(" << i << "].element(" << p_mas[i].first << "," << p_mas[i].second << ")=";
		cout << p_mas[i].element() << endl;
	}

	double y; int z; int q;
	cout << "first?";
	cin >> y;
	cout << "second?";
	cin >> z;
	cout << "j?";
	cin >> q;

	fraction F = make_fraction(y, z, q);
	F.Show();
	return 0;
}