#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void copy();
void count_maxletters_A();

int main()
{
    system("chcp 1251 > nul");
    //setlocale(LC_ALL, "rus");

    int close = 0, click;

    do
    {
        cout << endl;
        cout << "\tЧто вы хотите сделать?" << endl;
        cout << "1.Скопировать из файла F1 в файл F2 все строки, заканчивающиеся на букву «А» и расположенные между строками с номерами N1 и N2" << endl;
        cout << "2.Определить номер той строки, в которой больше всего букв «А», файла F2." << endl;
        cout << "3.Выход" << endl;
        cout << endl;
        cin >> click;

        switch (click)
        {
        case 1:
            cout << "Введите номера строки N1 и N2: " << endl;

            copy();

            break;
        case 2:
            count_maxletters_A();
            break;

        case 3:
            cout << endl;
            cout << "Программа завершила свою работу!";
            cout << endl;
            close = 1;
            break;
        default:
            break;
        }

    } while (close != 1);
    return 0;
}

void copy()
{
    ifstream file1("F1.txt");
    ofstream file2("F2.txt");

    string str;
    //char S[50];

    int N1, N2;
    bool flag = 0;
    int countStr = 0;
    cin >> N1 >> N2;
    if (!file1.is_open())
    {
        cout << " Ошибка открытия файла !" << endl;
    }
    else
    {
        cout << "Файл открыт!" << endl;

        for (int i = 0; !file1.eof(); i++)
        {
            getline(file1, str);

            countStr++;

            if (countStr >= N1 && countStr <= N2) {
                for (int i = 0; i < str.length(); i++)
                {
                    if ((str[i] == 'А') && (str[i + 1] == '\0'))
                        flag = true;
                }
            }
                if (flag) 
            file2 << str << '\n';

            flag = false;

        }
        cout << countStr;

    }

    file1.close();
    file2.close();

}

void count_maxletters_A()
{
    ifstream newf("F2.txt");

    string str;

    int countStr = 0;
    int count_A = 0;
    int max_count_A = 0;
    int numStr = 0;

    if (!newf.is_open())
    {
        cout << " Ошибка открытия файла !" << endl;
    }
    else
    {
        cout << "Файл открыт!" << endl;

        for (int i = 0; !newf.eof(); i++)
        {
            count_A = 0;
            getline(newf, str);

            countStr++;

            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == 'А')
                    count_A++;
            }
            if (count_A > max_count_A)
            {
                max_count_A = count_A;
                numStr = countStr;
            }
        }
        cout << numStr;
    }

    newf.close();

}
