#include <iostream>
#include <windows.h>
#include <unordered_set>
#include <set>
#include <algorithm>
//#include <vector> 
using namespace std;

int num;
int n;
vector<int> v1, v2, v3;
vector<int> U = { -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
vector<int> print_set(vector<int> X);
vector<int> manual_filling(vector<int> X);
vector<int> auto_fill(vector<int> X);
vector<int> by_condition(vector<int> X);
vector<int> intersection(vector<int>& vX, vector<int>& vY, vector<int>& vZ);
vector<int> _union(vector<int>& vX, vector<int>& vY, vector<int>& vZ);
vector<int> symmetric_difference(vector<int>& vX, vector<int>& vY, vector<int>& vZ);
vector<int> difference(vector<int>& vX, vector<int>& vY, vector<int>& vZ);
vector<int> complement(vector<int>& vX, vector<int>& vY, vector<int>& vZ);

vector<int> set_a_set(vector<int> &v)
{
	cout << "___________________________" << endl;
	int click;
	cout << endl;
	cout << "\tВыберите действие:" << endl;
	cout << "1.Ввести элементы множества вручную" << endl;
	cout << "2.Заполнить множество автоматически" << endl;
	cout << "3.Заполнить множество элементами, подходящими по условию" << endl;
	cout << endl;

	cin >> click;
	switch (click)
	{
	case 1:
	{
		cout << "\t";
		cout << "Введите количество элементов во множестве:  "; cin >> n;
		while (true) {
			if (n < 0) {
				cout << "Недопустимый размер множества! Введите другое значение:  "; cin >> n;
			}
			else break;
		}
		vector <int> v(n);
		v = manual_filling(v);
		cout << "ПОЛУЧЕННОЕ МНОЖЕСТВО: " << endl;
		print_set(v);
		return v;
	}
	case 2:
	{
		cout << "\t";
		cout << "Введите количество элементов во множестве:  "; cin >> n;
		while (true) {
			if (n < 0) {
				cout << "Недопустимый размер множества! Введите другое значение:  "; cin >> n;
			}
			else break;
		}
		vector <int> v(n);
		v = auto_fill(v);
		cout << "ПОЛУЧЕННОЕ МНОЖЕСТВО: " << endl;
		print_set(v);
		return v;
	}
	case 3:
	{
		cout << "\t";
		vector <int> v;
		v = by_condition(v);
		cout << "ПОЛУЧЕННОЕ МНОЖЕСТВО: " << endl;
		print_set(v);
		return v;
	}
	default:
		break;
	}
	return v;
}

vector<int> print_set(vector<int> X)
{
	for (int i = 0; i < X.size(); i++) {
		cout << X[i] << "  ";
	}
	cout << endl;
	return X;
}

vector<int> manual_filling(vector<int> X)
{
	unordered_set<int> mem;
	int i = 0;
	while (i < n) {
		cout << "Введите "<< "[" << i << "]" << " число:  ";
		cin >> X[i];
		if (X[i] < -9 || X[i] > 9 || mem.find(X[i]) != mem.end())
			cout << "Число НЕ ВХОДИТ ВО МНОЖЕСТВО УНИВЕРСУМА или ПОВТОРЯЕТСЯ! Введите другое число:  ";
		else
			mem.insert(X[i++]);
	}
	cout << endl;
	return X;
}

vector<int> auto_fill(vector<int> X)
{
	unordered_set<int> mem;
	int i = 0;
	while (i < n) {
		X[i] = rand() % 19 - 9;
		if (mem.find(X[i]) == mem.end())
			mem.insert(X[i++]);
	}
	return X;
}

vector<int> by_condition(vector<int> X)
{
	vector <int> Y;
	int click, t = 0, i=0;
	bool q;
	cout << endl;
	cout << "\tВыберите условие:" << endl;
	cout << "1.четность" << endl;
	cout << "2.кратность" << endl;
	cout << "3.знак" << endl;
	cout << endl;
	Y = U;
	cin >> click;
	switch (click)
	{
	case 1:
	{
		cout << "0. Только четные числа" << endl;
		cout << "1. Только нечетные числа" << endl;
		cin >> q;
		if (!q) {
			for (int i = 0; i < Y.size(); i++)
			{
				if ((Y[i] % 2 == 0)&&(Y[i] != 0)) {
					Y.erase(Y.begin() + i);
				}
			}
		}
		else {
			for (int i = 0; i < Y.size(); i++)
			{
				if (Y[i] % 2 != 0) {
					Y.erase(Y.begin() + i);
				}
			}
		}
		set_difference(U.begin(), U.end(), Y.begin(), Y.end(), back_inserter(X));
		cout << endl;
		break;
	}
	case 2:
	{
		cout << "Какому числу должны быть кратны элементы? (Число должно быть в диапазоне универсума) : ";
		int k;
		cin >> k;
		while (true) {
			if (k < -9 || k > 9) {
				cout << "ОШИБКА! Число не входит во множество универсума! Введите другое число : ";
				cin >> k;
			}
			else if (k == 0) {
				cout << "ОШИБКА! Кратность нулю невозможна! Введите другое число : ";
				cin >> k;
			}
			else break;
		}
		for (int i = 0; i < Y.size(); i++)
		{
			if (Y[i] % k == 0) {
				Y.erase(Y.begin() + i);
			}
		}
		set_difference(U.begin(), U.end(), Y.begin(), Y.end(), back_inserter(X));
		cout << endl;
		break;
	}
	case 3:
	{
		cout << "0. Только положительные числа" << endl;
		cout << "1. Только отрицательные числа" << endl;
		cin >> q;
		if (!q) {
			for (int i = 0; i < Y.size(); i++)
			{
				if (Y[i] >= 0) {
					Y.erase(Y.begin());
					i--;
				}
			}
			X = Y;
		}
		else {
			for (int i = 0; i < Y.size(); i++){
				if (Y[i] < 0) {
					Y.erase(Y.begin());
					i--;
				}
			}
			set_difference(U.begin(), U.end(), Y.begin(), Y.end(), back_inserter(X));
		}
		
		cout << endl;
		break;
	}
	default:
		break;
	}
	return X;
}

vector<int> operations_menu(vector<int>& vX, vector<int>& vY, vector<int>& vZ)
{
	int click;
	vector <int> v_result;

	cout << endl;
	cout << "\tВыберите операцию:" << endl;
	cout << "1.Объединение |" << endl;
	cout << "2.Пересечение &" << endl;
	cout << "3.Разность /" << endl;
	cout << "4.Симметрическая разность " << endl;
	cout << "5.Дополнение" << endl;
	cout << endl;

	cin >> click;
	switch (click)
	{
	case 1: {
		v_result = _union(vX, vY, vZ);
		break;
	}
	case 2: {
		v_result = intersection(vX, vY, vZ);
		break;
	}
	case 3: {
		v_result = difference(vX, vY, vZ);
		break;
	}
	case 4: {
		v_result = symmetric_difference(vX, vY, vZ);
		break;
	}
	case 5: {
		v_result = complement(vX, vY, vZ);
		break;
	}
	default:
		break;
	}
	return v_result;
}

vector<int> intersection(vector<int>& vX, vector<int>& vY, vector<int>& vZ)
{
	vector <int> v_result;
	cout << endl << "\t";
	cout << "Выберите множества для операции: " << endl;
	cout << "1. A и B" << endl;
	cout << "2. B и С" << endl;
	cout << "3. A и C " << endl;
	cout << "4. A, B и C " << endl;
	sort(vX.begin(), vX.end());
	sort(vY.begin(), vY.end());
	sort(vZ.begin(), vZ.end());
	cin >> num;
	switch (num) {
	case 1: {
		cout << " Mножество А: ";
		print_set(vX);
		cout << " Mножество B: ";
		print_set(vY);
		set_intersection(vX.begin(), vX.end(), vY.begin(), vY.end(), back_inserter(v_result));
		break;
	}
	case 2: {
		cout << " Mножество B: ";
		print_set(vY);
		cout << " Mножество C: ";
		print_set(vZ);
		set_intersection(vY.begin(), vY.end(), vZ.begin(), vZ.end(), back_inserter(v_result));
		break;
	}
	case 3: {
		cout << " Mножество А: ";
		print_set(vX);
		cout << " Mножество C: ";
		print_set(vZ);
		set_intersection(vX.begin(), vX.end(), vZ.begin(), vZ.end(), back_inserter(v_result));
		break;
	}
	case 4: {
		cout << " Mножество А: ";
		print_set(vX);
		cout << " Mножество B: ";
		print_set(vY);
		cout << " Mножество C: ";
		print_set(vZ);
		set_intersection(vX.begin(), vX.end(), vY.begin(), vY.end(), back_inserter(v2));
		set_intersection(v1.begin(), v1.end(), vZ.begin(), vZ.end(), back_inserter(v_result));
		break;
	}
	default: break;
	}
	return v_result;
}

vector<int> _union(vector<int>& vX, vector<int>& vY, vector<int>& vZ)
{
	vector <int> v_result;
	cout << endl << "\t";
	cout << "Выберите множества для операции: " << endl;
	cout << "1. A и B" << endl;
	cout << "2. B и С" << endl;
	cout << "3. A и C " << endl;
	cout << "4. A, B и C " << endl;
	sort(vX.begin(), vX.end());
	sort(vY.begin(), vY.end());
	sort(vZ.begin(), vZ.end());
	cin >> num;
	switch (num) {
	case 1: {
		cout << " Mножество А: ";
		print_set(vX);
		cout << " Mножество B: ";
		print_set(vY);
		set_union(vX.begin(), vX.end(), vY.begin(), vY.end(), back_inserter(v_result));
		break;
	}
	case 2: {
		cout << " Mножество B: ";
		print_set(vY);
		cout << " Mножество C: ";
		print_set(vZ);
		set_union(vY.begin(), vY.end(), vZ.begin(), vZ.end(), back_inserter(v_result));
		break;
	}
	case 3: {
		cout << " Mножество А: ";
		print_set(vX);
		cout << " Mножество C: ";
		print_set(vZ);
		set_union(vX.begin(), vX.end(), vZ.begin(), vZ.end(), back_inserter(v_result));
		break;
	}
	case 4: {
		cout << " Mножество А: ";
		print_set(vX);
		cout << " Mножество B: ";
		print_set(vY);
		cout << " Mножество C: ";
		print_set(vZ);
		set_union(vX.begin(), vX.end(), vY.begin(), vY.end(), back_inserter(v1));
		set_union(v1.begin(), v1.end(), vZ.begin(), vZ.end(), back_inserter(v_result));
		break;
	}
	default: break;
	}
	return v_result;
}

vector<int> symmetric_difference(vector<int>& vX, vector<int>& vY, vector<int>& vZ)
{
	vector <int> v_result;
	cout << endl << "\t";
	cout << "Выберите множества для операции: " << endl;
	cout << "1. A и B" << endl;
	cout << "2. B и С" << endl;
	cout << "3. A и C " << endl;
	cout << "4. A, B и C " << endl;
	sort(vX.begin(), vX.end());
	sort(vY.begin(), vY.end());
	sort(vZ.begin(), vZ.end());
	cin >> num;
	switch (num) {
	case 1: {
		cout << " Mножество А: ";
		print_set(vX);
		cout << " Mножество B: ";
		print_set(vY);
		set_symmetric_difference(vX.begin(), vX.end(), vY.begin(), vY.end(), back_inserter(v_result));
		break;
	}
	case 2: {
		cout << " Mножество B: ";
		print_set(vY);
		cout << " Mножество C: ";
		print_set(vZ);
		set_symmetric_difference(vY.begin(), vY.end(), vZ.begin(), vZ.end(), back_inserter(v_result));
		break;
	}
	case 3: {
		cout << " Mножество А: ";
		print_set(vX);
		cout << " Mножество C: ";
		print_set(vZ);
		set_symmetric_difference(vX.begin(), vX.end(), vZ.begin(), vZ.end(), back_inserter(v_result));
		break;
	}
	case 4: {
		cout << " Mножество А: ";
		print_set(vX);
		cout << " Mножество B: ";
		print_set(vY);
		cout << " Mножество C: ";
		print_set(vZ);
		set_symmetric_difference(vX.begin(), vX.end(), vY.begin(), vY.end(), back_inserter(v3));
		set_symmetric_difference(v1.begin(), v1.end(), vZ.begin(), vZ.end(), back_inserter(v_result));
		break;
	}
	default: break;
	}
	return v_result;
}

vector<int> difference(vector<int>& vX, vector<int>& vY, vector<int>& vZ)
{
	vector <int> v_result;
	cout << endl << "\t";
	cout << "Выберите 1-е множество для операции: " << endl;
	cout << "1. A" << endl;
	cout << "2. B" << endl;
	cout << "3. C " << endl;
	cin >> num;
	switch (num) {
	case 1: {
		v1 = vX; 
		cout << " Mножество А: ";
		break;
	}
	case 2: {
		v1 = vY; 
		cout << " Mножество B: ";
		break;
	}
	case 3: {
		v1 = vZ; 
		cout << " Mножество C: ";
		break;
	}
	default: break;
	}
	print_set(v1);
	cout << endl << "\t";
	cout << "Выберите 2-е множество для операции: " << endl;
	cout << "1. A" << endl;
	cout << "2. B" << endl;
	cout << "3. C " << endl;
	cin >> num;
	switch (num) {
	case 1: {
		v2 = vX; 
		cout << " Mножество А: ";
		break;
	}
	case 2: {
		v2 = vY; 
		cout << " Mножество B: ";
		break;
	}
	case 3: {
		v2 = vZ; 
		cout << " Mножество C: ";
		break;
	}
	default: break;
	}
	print_set(v2);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v_result));
	return v_result;
}

vector<int> complement(vector<int>& vX, vector<int>& vY, vector<int>& vZ)
{
	vector <int> v_result;
	cout << endl << "\t";
	cout << "Выберите множество для операции: " << endl;
	cout << "1. A" << endl;
	cout << "2. B" << endl;
	cout << "3. C " << endl;
	cin >> num;
	switch (num) {
	case 1: {
		v1 = vX;
		cout << " Mножество А: ";
		break;
	}
	case 2: {
		v1 = vY; 
		cout << " Mножество B: ";
		break;
	}
	case 3: {
		v1 = vZ; 
		cout << " Mножество C: ";
		break;
	}
	default: break;
	}
	print_set(v1);
	sort(v1.begin(), v1.end());
	set_difference(U.begin(), U.end(), v1.begin(), v1.end(), back_inserter(v_result));
	return v_result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int sizeA = 0, sizeB = 0, sizeC = 0;
	vector<int> vA;
	vector<int> vB;
	vector<int> vC;
	vector <int> v;
	vector <int> v_result;

	cout << endl << "\tЗАДАЙТЕ МНОЖЕСТВО A: " << endl;
	vA = set_a_set(vA);
	sizeA = vA.size();
	//print_set(vA);
	sort(vA.begin(), vA.end());
	cout << endl << "\tЗАДАЙТЕ МНОЖЕСТВО B: " << endl;
	vB = set_a_set(vB);
	sort(vB.begin(), vB.end());
	bool q;
	cout << "\tЗадать множество C? " << endl;
	cout << "1.да/ 0.нет" << endl; cin >> q;
	if (q) {
		vC = set_a_set(vC);
		sort(vC.begin(), vC.end());
		cout << "___________________________" << endl;
	}

	int click, num, close = 0;
	if (close == 0) {
		do {
			cout << endl;
			cout << "\tЧто вы хотите сделать?" << endl;
			cout << "1.Изменить множество" << endl;
			cout << "2.Выполнить операцию" << endl;
			cout << "3.Выход из программы" << endl;
			cout << endl;
			cin >> click;

			switch (click)
			{
			case 1:
			{
				cout << endl;
				cout << "1.A" << endl;
				cout << "2.B" << endl;
				cout << "3.C" << endl;
				cout << endl;
				cin >> num;
				cout << endl << "\tЗАДАЙТЕ МНОЖЕСТВО : " << endl;
				if(num == 1) vA = set_a_set(vA);
				else if(num == 2) vB = set_a_set(vB);
					else vC = set_a_set(vC);
				break;
			}
			case 2:
			{
				vector <int> v;
				cout << "___________________________" << endl;
				v_result = operations_menu(vA, vB, vC);
				set <int> s_result;
				s_result.insert(v_result.begin(), v_result.end());
				cout << "\t";
				cout << endl << "Результат операции: " << "\t";
				for (auto i : s_result)
					cout << i << "  ";
				cout << endl;
				cout << "___________________________" << endl;
				break;
			}
			case 3:
			{
				cout << endl;
				cout << "Программа завершила свою работу!";
				cout << endl;
				close = 1;
				break;
			}
			default:
				break;
			}

		} while (close != 1);
	}
	
	return 0;
}
