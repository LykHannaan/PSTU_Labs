#pragma once
struct fraction
{
	double first;
	int second;
	int j;
	void Init(double, int, int);    //������������� �����
	void Read();               //������ �������� �����
	void Show();               //����� �������� �����
	double element();
};