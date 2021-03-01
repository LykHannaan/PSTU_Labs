#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, m;
	int i, j;

	cout << "\tВедите размер массива : - ";
	cin >> n >> m;

	while (true)
	{
		if (n > 0 or m > 0)
			break;
		else {
			cout << endl;
			cout << "Массив нулевой" << endl;
			cout << endl;
			cout << "\tВведите размер массива : - ";
				cin >> n;
			}
	}
		int** matr;
		matr = new int* [n];

		for (i = 0; i < n; i++)
		{
			matr[i] = new int[m];

			for (j = 0; j < m; j++)
				matr[i][j] = rand() % 100 - 50;
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << matr[i][j] << '\t';
			}
			cout << endl;
		}
		cout << endl;

		int maxElem = 0;
		int k = 0, p = 0;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				if (matr[i][j] > maxElem)
				{
					maxElem = matr[i][j];
					k = i;
					p = j;
				}
		}
	
		int** new_array;
		new_array = new int*[n-1];

		for (i = 0; i < n - 1; i++)
			new_array[i] = new int[m-1];

		delete matr[k];


		for (i = k; i < n - 1; i++)
		{
			matr[i] = matr[i + 1];
		}
		n--;

		for (i = 0; i < n; i++)
		{
			for (j = p; j < m - 1; j++)
				matr[i][j] = matr[i][j + 1];

		}
		m--;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				new_array[i][j] = matr[i][j];

		matr = new_array;


		for (int i = 0; i < n - 1; i++)
			delete[]new_array[i];
		delete[]new_array;


		for (i = 0; i < n; i++)
		{
		    for (j = 0; j < m; j++)
			{
				cout << matr[i][j] << '\t';
			}
			cout << endl;
		}
		

		
		for (int i = 0; i < n; i++)
			delete matr[i];
		delete[] matr;


	return 0;
}