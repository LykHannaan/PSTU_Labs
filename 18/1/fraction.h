#pragma once
struct progression
{
	double first;
	int second;
	void Init(double, int);    //инициализация полей
	void Read();               //чтение значения полей
	void Show();               //вывод значений полей
	double element(int);
};
