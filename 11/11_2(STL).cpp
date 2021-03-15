//двунаправленный список через библиотеки STL

#include <iostream>
#include <windows.h>
#include <list>
#include <iterator>

using namespace std;
list <int> node;

int elem;

void make(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Введите " << i + 1 << " элемент: ";
		cin >> elem;
		node.push_back(elem);
	}
}

void delete_list_elem()
{
	list<int>::iterator it = node.begin();
	int j = 0;
	while (it != node.end())
	{
		j++;
		if (j % 2 == 0)
		{
			it = node.erase(it);
		}
		else
		{
			++it;
		}
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	cout << "Введите размер списка: ";
	cin >> size;

	make(size);

	cout << "Ваш список: " << endl;

	copy(node.begin(), node.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	delete_list_elem();

	cout << "Ваш список после удаления: " << endl;
	copy(node.begin(), node.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
