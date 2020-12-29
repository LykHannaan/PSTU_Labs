#include <iostream>

using namespace std;

int sum(int **a, int n, int m);
void main()
{
	int n, m, maxS,s;
	cin >> n >> m;
	int **a, i, j;
	a = new int*[n];
	

	for (i = 0; i < n; i++)
		a[i] = new int [m];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			a[i][j] = rand() % 10;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	maxS = sum(a, n, m);

	while (m-1>0)
	{
		s = sum(a, n, m); 
		m--;
		cout << s << ' ';
		if (s > maxS) maxS = s;
	}

	cout << maxS;
}


int sum(int **a, int n, int m)
{
	int i,j, c = 0;
	for (j = 0; j < m; j++) 
	{   
		c = 0;
		for (i = 0; i < n; i++)
		{
			c += a[i][j];
		}
	}
	return c;
}
