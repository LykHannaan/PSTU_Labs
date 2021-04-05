#pragma once
struct fraction
{
	double first;
	int second;
	int j;
	void Init(double, int, int);    //инициализация полей
	void Read();               //чтение значения полей
	void Show();               //вывод значений полей
	double element();
};