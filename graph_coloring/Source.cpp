#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int  Versh[10];
int matrix[10][10];
int N = 0;							// кол-во вершин
int  StepVersh[10];					// массив, который содержит степени вершин
int color[10];						// массив, который содержит цвет каждой вершины
int Kcolor = 0;						// отвечает за цвет
int mstep = 0;                      // максимальная степень смежности вершины, которая еще не окрашена
int neokrash = 0;                   // кол-во неокрашенных вершин
int NVMS = -1;
int Okrash[1000];
int KK = 0;

void inputFile() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите матрицу смежности в файл!" << endl << endl;
	cout << "Сколько вершин в вашем графе?: ";

	cin >> N;
	if (N > 10) {
		cout << "Введено неверное кол-во вершин" << endl; exit(0);
	}
	neokrash = N;
	// обьявление матрицы, максимальное количество вершин = 10
	ifstream ProgInput("input.txt");     //input.txt берется матрица весов
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ProgInput >> matrix[i][j];
		}
	}
}
void PrintMatrix() {
	cout << endl;
	cout << "Матрица смежности:" << endl;
	cout << endl;
	cout << "  ";
	for (int i = 0; i < N; i++) { Versh[i] = i; cout << Versh[i] << " "; }
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << Versh[i] << " ";
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void StepVerhin() {
	cout << endl;
	cout << "Степени смежности вершин:" << endl;
	cout << endl;
	for (int i = 0; i < N; i++) {
		int Step = 0;
		for (int j = 0; j < N; j++) {            // нахождение степени каждой вершины
			if (matrix[i][j] > 0) {
				Step++;
			}
		}
		StepVersh[i] = Step;
	}

	for (int i = 0; i < N; i++) {
		cout << "Вершина " << Versh[i] << " : " << StepVersh[i] << endl;     //вывод вершин и их степени смежности
	}
	cout << endl;
}

void InitColor() {
	for (int i = 0; i < N; i++) {
		color[i] = Kcolor;
		// ни одна вершина еще не окрашена
	}
	for (int i = 0; i < 1000; i++) {
		Okrash[i] = -1;
	}

}
void PrintColor() {
	cout << "Раскраска завершена!" << endl;
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << "Цвет вершины " << i << ": " << color[i] << endl;     // ни одна вершина еще не окрашена
	}
	cout << endl;
}

void MaxStepen() {
	int max = -1;
	for (int i = 0; i < N; i++) {
		if (StepVersh[i] > max) {
			max = StepVersh[i];
			NVMS = i;
		}
	}
	mstep = max;
}

bool contains(int arr[1000], int elem) {
	for (int i = 0; i < 1000; i++) {
		if (arr[i] == elem) {
			return true;
		}
	}
	return false;
}
void UpdateSmezn(int matr[10][10], int i) {
	for (int j = 0; j < N; j++) {
		if (matrix[i][j] == 1) {
			Okrash[KK] = j;
		}
	}
}
void Coloring() {
	while (neokrash > 0) {				// до тех пор, пока все вершины не будут окрашены
		MaxStepen();					// ищем максимальную степень смежности
		Kcolor++;						// +1 цвет
		color[NVMS] = Kcolor;			// окрашиваем вершину с наибольшим количеством соседей
		neokrash--;						// кол-во неокрашенных вершин уменьшилось на 1
		Okrash[KK] = NVMS;				// добавляем в список закрашенную вершину
		StepVersh[NVMS] = -1;
		for (int i = 0; i < N; i++) {
			if ((matrix[NVMS][i] == 0) && (color[i] == 0)) {       // если в матрице смежности в строке NVMS есть несмежные вершины и они не закрашены, тогда проверяем смежные они или нет
				if (!contains(Okrash, i)) {
					KK++;
					Okrash[KK] = i;
					color[i] = Kcolor;                            // закрашиваем вершину
					StepVersh[i] = -1;                            // убираем вершину и ее степень смежности в самый конец списка, чтобы она нам не мешала. 
					neokrash--;
					UpdateSmezn(matrix, i);					// обновляем массив Okrash, он отвечает за смежные вершины
				}
			}
		}
		for (int i = 0; i < 1000; i++) {			// инициализируем массив Okrash для снятия ограничений смежности для другого цвета
			Okrash[i] = -1;
		}
	}

}

int main()
{
	inputFile();
	PrintMatrix();
	StepVerhin();
	InitColor();
	Coloring();
	PrintColor();
}
