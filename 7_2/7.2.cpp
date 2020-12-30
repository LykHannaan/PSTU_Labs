#include <iostream>
using namespace std;

int* octdec(int n, ...)
{
    int* d = new int[n];
    int* ptr = &n;
    for (int i = 0; i < n; i++)
    {
        int oct = ptr[i + 1];
        bool flag = (oct > 0);
        oct = abs(oct);
        d[i] = 0;
        int exp = 0;
        while (oct > 0)
        {
            d[i] += (oct % 10) * pow(8, exp);
            exp++;
            oct /= 10;
        }
        if (!flag) d[i] *= -1;
    }
    return d;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Введите 3 числа в восьмеричной сс: ";
    int a[8];
    for (int i = 0; i < 3; i++) cin >> a[i];
    int* d = octdec(3, a[0], a[1], a[2]);
    cout << "Числа в десятичной сс: ";
    for (int i = 0; i < 3; i++) cout << d[i] << ' ';
    cout << endl;
    
    cout << "Введите 6 чисел в восьмеричной сс: ";
    for (int i = 0; i < 6; i++) cin >> a[i];
    d = octdec(6, a[0], a[1], a[2], a[3], a[4], a[5]);
    cout << "Числа в десятичной сс: ";
    for (int i = 0; i < 6; i++) cout << d[i] << ' ';
    cout << endl;
    
    cout << "Введите 7 чисел в восьмеричной сс: ";
    for (int i = 0; i < 7; i++) cin >> a[i];
    d = octdec(7, a[0], a[1], a[2], a[3], a[4], a[5], a[6]);
    cout << "Числа в десятичной сс : ";
    for (int i = 0; i < 7; i++) cout << d[i] << ' ';
    cout << endl;
}
