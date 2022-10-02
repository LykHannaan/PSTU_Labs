#include <windows.h>
#include <iostream>
//#include <conio.h>
#include "Pipes.h"

using namespace std;

int main()
{
        if (WaitNamedPipe("\\\\.\\pipe\\MyPipe", 3000))
        {
                HANDLE hPipe = CreateFile("\\\\.\\pipe\\MyPipe", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
                while (true)
                {
                        cout << "Enter message:" << endl;
                        string s;
                        cin >> s;
                        SendString(hPipe, s);
                        if (s == "quit")
                        {
                                break;
                        }
                        cout << GetInt(hPipe) << endl;
                }
                CloseHandle(hPipe);
        }
        else
        {
                cout << "No pipes available" << endl;

        }
}
