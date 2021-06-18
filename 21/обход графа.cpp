#include <iostream>
using namespace std;
const int n = 7;
int i, j;
bool* visited = new bool[n];
//матрица смежности графа
int graph[n][n] =
{
{0, 1, 0, 0, 1, 0, 0},
{0, 0, 0, 1, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 1, 1},
{0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 0, 0},
};
//поиск в глубину
void DFS(int st)
{
	int r;
	cout << st << " ";
	visited[st] = true;
	for (r = 0; r <= n; r++)
		if ((graph[st][r] != 0) && (!visited[r]))
			DFS(r);
}
//поиск в ширину
void BFS(int unit)
{
	int* queue = new int[n];
	int count, head;
	for (i = 0; i < n; i++) queue[i] = 0;
	count = 0; head = 0;
	queue[count++] = unit;
	visited[unit] = true;
	while (head < count)
	{
		unit = queue[head++];
		cout << unit << " ";
		for (i = 0; i < n; i++)
			if (graph[unit][i] && !visited[i])
			{
				queue[count++] = i;
				visited[i] = true;
			}
	}
	delete[]queue;
}
//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	int start;
	cout << "Матрица смежности графа: " << endl;
	for (i = 0; i < n; i++)
	{
		visited[i] = false;
		for (j = 0; j < n; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}
	cout << "Стартовая вершина >> "; cin >> start;
	//массив посещенных вершин
	cout << "Порядок обхода: ";
	DFS(start);
	BFS(start);
	delete[]visited;
	system("pause>>void");
}
