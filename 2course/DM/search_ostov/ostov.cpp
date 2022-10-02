#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Graf
{
private:
    int MaxNodes;//Максимальное кол-во узлов
    int* nodes;//массив узлов для раскраски
    int num_vershina;//кол-во вершин
    int num_rebro;//кол-во ребер
    int Last_vershina;//цвет последней окрашеной вершины

    struct uzel
    {
        int v1;
        int v2;
        int wes;
    }*uzels;
public:
    Graf();
    void InitGraf();//функция задающая граф
    void sort();//сортировка ребер по возрастанию
    int GetColor(int n);//получает цвет ребра,n - номер вершины
    void OutTree();//вывод дерева на экран

};

Graf::Graf()
{
    MaxNodes = 50;
    nodes = new int[MaxNodes];
    uzels = new uzel[MaxNodes];
}

void Graf::InitGraf()
{
    setlocale(LC_ALL, "Russian");
    cout << "Ввидите число вершин: ";
    cin >> num_vershina;
    while (true) {
        if (num_vershina > MaxNodes) {
            cout << "Ошибка! Максимальное число вершин = 50!" << endl;
            cout << "Ввидите число вершин: ";
            cin >> num_vershina;
        }
        else break;
    }
  cout << "Введите число ребер: ";
    int MaxRebro = (num_vershina * num_vershina - num_vershina) / 2;
    cin >> num_rebro;
    while (true) {
        if (num_rebro > MaxRebro) {
            cout << "Ошибка! Максимальное число рёбер = " << MaxRebro << "!" << endl;
            cout << "Ввидите число рёбер: ";
            cin >> num_rebro;
        }
        else break;
    }
    // Задаем начальные цвета вершинам
    for (int i = 0; i < num_vershina; i++)
        nodes[i] = -1 - i;
    cout << endl
        << "Количество ребер: " << num_rebro << endl
        << "Введите их в формате: вершина1, вершина2, вес "
        << endl;
    for (int i = 0; i < num_rebro; i++)
    {
        cout << endl << "Вершина 1 = "; cin >> uzels[i].v1;
        cout << "Вершина 2 = "; cin >> uzels[i].v2;
        cout << "Вес = "; cin >> uzels[i].wes;
    }
    cout << endl << "ГРАФ ЗАДАН!" << endl;
}

/* Фунция сортирующая ребра графа по весу начиная с наименьшего               */
void Graf::sort()
{
    uzel tmp;//обьект типа узел
    // Пузырьковая сортировка

    for (int i = 0; i < num_rebro - 1; i++)
        for (int j = 0; j < num_rebro - 1; j++)
            if (uzels[j].wes > uzels[j + 1].wes)
            {
                tmp = uzels[j];
                uzels[j] = uzels[j + 1];
                uzels[j + 1] = tmp;
            }
}

/* Функция, получающая цвет ребра                                             */

int Graf::GetColor(int n)
{

    // Если цвет вершины с номером n - отрицательный, то...
    if (nodes[n] < 0)
    {
        Last_vershina = n;//цвет последней окрашенной вершины
        return nodes[Last_vershina];//возвращаем его
    }
    else
    {
        int color;
        // Получаем цвет вершины с номером n
        color = GetColor(nodes[n]);
        nodes[n] = Last_vershina;// окрашиваем его в цвет вершины, с которой объединяем
        return color;// возвращаем цвет
    }

}

void Graf::OutTree()
{
    sort();
    // Сортируем ребра по возрастанию

    cout << "Минимальное остовное дерево состоит из ребер с весами " << endl;
    for (unsigned i(0); i++ < 45; cout.put('-'));
    cout.put('\n');
    cout << setw(15) << "Вершина 1" << setw(3) << '|'
        << setw(12) << "Вершина 2" << setw(7) << '|'
        << setw(8) << "Вес" << endl;
    for (unsigned i(0); i++ < 45; cout.put('-'));
    cout.put('\n');
    for (int i = 0; i < num_rebro; i++)
    {
        int color1 = GetColor(uzels[i].v2);// получаем цвет второй вершины
        int color2 = GetColor(uzels[i].v1);  // получаем цвет первой вершины
   // Если ребро соединяет вершины различных цветов, то...

        if (color2 != color1)
        {
            // ...перекрашиваем вершины в цвет ребра
            nodes[Last_vershina] = uzels[i].v2;
            // добавляем вершину в минимальное остовное дерево
            cout << setw(15) << uzels[i].v1
            << setw(3) << '|' << setw(12) << uzels[i].v2
            << setw(7) << '|' << setw(8) << uzels[i].wes << endl;
        }
    }
    for (unsigned i(0); i++ < 45; cout.put('-'));
}


int main()
{
    setlocale(LC_ALL, "Russian");
    Graf graf;
    int c = 1;

    while (c != 3)
    {
        cout << endl;
        cout << "Операции" << endl;
        cout << "1. Задать граф" << endl;
        cout << "2. Построить дерево" << endl;
        cout << "3. Выход" << endl;
        cout << ">> " << endl;

        cin >> c;

        switch (c)
        {
        case 1:
            graf.InitGraf();
            break;

        case 2:
            graf.OutTree();
            break;

        case 3:
            break;

        default:
            cout << endl << "Неверный выбор" << endl;
            break;
        }
    }
    return(1);
}
