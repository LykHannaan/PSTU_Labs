#include <iostream>
#include <time.h>

using namespace std;

void Left(int* arr, int N, int K) 
{
    int i = K;
    while (true)
    {
        cout << arr[i] << "\t";
        i--;
        if (i == -1) i = N - 1;
        if (i == K) break;
    }
}

void Right(int* arr, int N, int K) 
{
    int i = K;
    while (true)
    {
        cout << arr[i] << "\t";
        i++;
        if (i == N) i = 0;
        if (i == K) break;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(0));

    int N;
    while (true)
    {
       cin >> N;
       if (N >= 2)
        break;
       else cout << "Введите другой размер" << endl;
    }

    int* arr = new int[N];
    for (int i = 0; i < N; i++) 
    {
            arr[i] = rand()/ 100;
    }

    for (int i = 0; i < N; i++) 
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    int K;
    while (true)
    { 
        cin >> K;
        if (K >= 0 && K < N) break;
        else cout << "Введите другое значение K" << endl;
    }

    cout << "Массив по кольцу влево: \t";
    Left(arr, N, K);
    cout << endl;

    //удаление первого и последнего элементов
    for (int i = 0; i < N-1; i++) 
    { 
        arr[i] = arr[i + 1];
    }
    N-=2;
    //--------------------------------------

    if (K >= N)
    {
        while (true) 
        {
            cout << "Введите новое значение K" << endl;
            cin >> K;
            if (K >= 0 && K < N) break;
        }
    }
    cout << "Массив по кольцу вправо (после удаления элементов): \t";
    Right(arr, N, K);

    delete[] arr;
    return 0;
}
