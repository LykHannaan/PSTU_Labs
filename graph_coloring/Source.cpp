#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int  Versh[10];
int matrix[10][10];
int N = 0;							// ���-�� ������
int  StepVersh[10];					// ������, ������� �������� ������� ������
int color[10];						// ������, ������� �������� ���� ������ �������
int Kcolor = 0;						// �������� �� ����
int mstep = 0;                      // ������������ ������� ��������� �������, ������� ��� �� ��������
int neokrash = 0;                   // ���-�� ������������ ������
int NVMS = -1;
int Okrash[1000];
int KK = 0;

void inputFile() {
	setlocale(LC_ALL, "Russian");
	cout << "������� ������� ��������� � ����!" << endl << endl;
	cout << "������� ������ � ����� �����?: ";

	cin >> N;
	if (N > 10) {
		cout << "������� �������� ���-�� ������" << endl; exit(0);
	}
	neokrash = N;
	// ���������� �������, ������������ ���������� ������ = 10
	ifstream ProgInput("input.txt");     //input.txt ������� ������� �����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ProgInput >> matrix[i][j];
		}
	}
}
void PrintMatrix() {
	cout << endl;
	cout << "������� ���������:" << endl;
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
	cout << "������� ��������� ������:" << endl;
	cout << endl;
	for (int i = 0; i < N; i++) {
		int Step = 0;
		for (int j = 0; j < N; j++) {            // ���������� ������� ������ �������
			if (matrix[i][j] > 0) {
				Step++;
			}
		}
		StepVersh[i] = Step;
	}

	for (int i = 0; i < N; i++) {
		cout << "������� " << Versh[i] << " : " << StepVersh[i] << endl;     //����� ������ � �� ������� ���������
	}
	cout << endl;
}

void InitColor() {
	for (int i = 0; i < N; i++) {
		color[i] = Kcolor;
		// �� ���� ������� ��� �� ��������
	}
	for (int i = 0; i < 1000; i++) {
		Okrash[i] = -1;
	}

}
void PrintColor() {
	cout << "��������� ���������!" << endl;
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << "���� ������� " << i << ": " << color[i] << endl;     // �� ���� ������� ��� �� ��������
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
	while (neokrash > 0) {				// �� ��� ���, ���� ��� ������� �� ����� ��������
		MaxStepen();					// ���� ������������ ������� ���������
		Kcolor++;						// +1 ����
		color[NVMS] = Kcolor;			// ���������� ������� � ���������� ����������� �������
		neokrash--;						// ���-�� ������������ ������ ����������� �� 1
		Okrash[KK] = NVMS;				// ��������� � ������ ����������� �������
		StepVersh[NVMS] = -1;
		for (int i = 0; i < N; i++) {
			if ((matrix[NVMS][i] == 0) && (color[i] == 0)) {       // ���� � ������� ��������� � ������ NVMS ���� ��������� ������� � ��� �� ���������, ����� ��������� ������� ��� ��� ���
				if (!contains(Okrash, i)) {
					KK++;
					Okrash[KK] = i;
					color[i] = Kcolor;                            // ����������� �������
					StepVersh[i] = -1;                            // ������� ������� � �� ������� ��������� � ����� ����� ������, ����� ��� ��� �� ������. 
					neokrash--;
					UpdateSmezn(matrix, i);					// ��������� ������ Okrash, �� �������� �� ������� �������
				}
			}
		}
		for (int i = 0; i < 1000; i++) {			// �������������� ������ Okrash ��� ������ ����������� ��������� ��� ������� �����
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