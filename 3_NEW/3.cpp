#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	int a[100];
	int n;
	cout << "Длина массива: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a[i] = rand() % 10; //заполнение массива 
	}
	cout << "Исходный массив: ";
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;

	//удаление
	cout << "__Удаление из массива элементов с четными индексами__";
	cout << endl;
	int m = n, p = (n + 1) / 2;
	for (int i = 1; i <= m; i++)
	{
		if (i % 2 == 0)
			a[i] = a[i + 1];  //элементам с четными индексами задаются значения следующих за ними элементов 
	}
	m--;
	int j = 3;
	while (m > p)
	{
		for (int i = j; i <= m; i += 2)
		{
			a[i] = a[i + 1];
		}
		m--;
		j++;
	}
	cout << "Массив, полученный после удаления заданных элементов: " << endl;
	for (int i = 1; i <= m; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;

	//добавление
	cout << "__Добавление в массив N элементов, начиная с заданного номера K__" << endl;
	int k;
	cout << "K: ";
	cin >> k;
	for (int i = k; i <= n + m; i++)
	{
		a[i + n] = a[i];
	}
	for (int i = k; i < n + k; i++)
	{
		a[i] = rand() % 10;
	}
	cout << "Массив, полученный после добавления заданных элементов: " << endl;
	for (int i = 1; i <= m + n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;

	//перестановка
	cout << "__Перестановка - перевернуть массив__" << endl;
	n = n + m; //задание для переменной n нового значения после добавления элементов в массив
	int t;
	for (int i = 1; i <= n / 2; i++)
	{
		t = a[i];
		a[i] = a[n - i + 1];
		a[n - i + 1] = t;
	}
	cout << "Перевернутый массив: ";
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;

	//поиск 1
	cout << "__Поиск элемента с заданным ключом(значением)__" << endl;
	int kk = 0, s = 0;
	cout << "Элемент: ";
	cin >> k;
	for (int i = 1; i <= n; i++)
	{
		kk++;
		if (a[i] == k)
		{
			s = i;
			break;
		}
	}
	if (s == 0) cout << " -> не найдено элементов с заданным значением k";
	else
	{
		cout << " -> Элемент найден" << endl;
		cout << "Количество сравнений, проведенных в ходе поиска: " << kk;
	}
	cout << endl << endl;

	//сортировка
	cout << "__Сортировка методом включения__" << endl;
	for (int i = 1; i <= n; i++)
	{
		int v = a[i];
		int j = i;
		while ((j > 0) && (a[j - 1] > v))
		{
			a[j] = a[j - 1];
			j--;
			a[j] = v;
		}
	}
	cout << "Отсортированный массив: ";
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;

	//поиск 2
	cout << "__Поиск элемента с заданным ключом(значением) в отсортированном массиве__" << endl;
	kk = 0, s = 0;
	cout << "Элемент: ";
	cin >> k;
	for (int i = 1; i <= n; i++)
	{
		kk++;
		if (a[i] == k)
		{
			s = i;
			break;
		}
	}
	if (s == 0) cout << " -> не найдено элементов с заданным значением k";
	else
	{
		cout << " -> Элемент найден" << endl;
		cout << "Количество сравнений, проведенных в ходе поиска: " << kk;
	}
	cout << endl;
}
