#include <iostream>
#include "Dialog.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Выберите команду:" << endl;
	cout << "m [size] Создать группу" << endl;
	cout << "+ Добавление элемента в группу" << endl;
	cout << "- Удаление элемента из группы" << endl;
	cout << "s Вывести информацию об элементах группы" << endl;
	cout << "z Вывести информацию о названиях всех элементов группы" << endl;
	cout << "q Выход из программы" << endl;
	Dialog D;
	D.Execute();
}