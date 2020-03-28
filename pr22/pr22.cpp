

#include <iostream>
#include <stdio.h>  
#include <windows.h>
#include <fstream>


bool open(int W[]);
void arithmetic(int p[], int n);
const int n = 33;
using namespace std;

int main()
{
    int p[n] = { 0 };
    setlocale(LC_ALL, "Russian");
    if (open(p) == 1)
    {
        system("pause");
        return 1;
    }
    
    cout << endl;
    arithmetic(p, n);
    system("pause");
    return 0;
   
}
bool open(int W[]) 
{
    ifstream file("Mas.txt");
    if (!file)
    {
        cout << "Файл не найден\n";
        return 1;
    }
    for (int i = 0; i < n; i++)
        file >> W[i];
    return 0;
}


void arithmetic(int p[], int n)
{
    int* len_arifm = new int[n];
    int* len_geom = new int[n];
    len_arifm[1] = 2, len_geom[1] = 2;
    int end_arifm = 1, end_geom = 1 ;

    for (int i = 2; i < n; i++)
    {
        if (p[i] - p[i - 1] == p[i - 1] - p[i - 2])
            len_arifm[i] = len_arifm[i - 1] + 1;
        else 
            len_arifm[i] = 2;
        if (p[i - 1] * p[i - 1] == p[i] * p[i - 2])
            len_geom[i] = len_geom[i - 1] + 1;
        else
            len_geom[i] = 2;

        if (len_arifm[i] > len_arifm[end_arifm])
            end_arifm = i;
        if (len_geom[i] > len_geom[end_geom])
            end_geom = i;
    }

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    
    for (int i = 0; i < n; i++)
    {
        if (i >= end_arifm - len_arifm[end_arifm] + 1  && i <= end_arifm + 1)
        {
            SetConsoleTextAttribute(console, FOREGROUND_RED);
            cout << p[i] << " ";
        }
        else
        {
            if (i >= end_geom - len_geom[end_geom] + 1 && i <= end_geom + 1)
            {
                SetConsoleTextAttribute(console, FOREGROUND_BLUE);
                cout << p[i] << " ";
            }
            else
            {
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                cout << p[i] << " ";
            }
        }
    }
    cout << endl;
    cout << "Цвета:\n";
    SetConsoleTextAttribute(console, FOREGROUND_RED);
    cout << "Красный";
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "- Самая большея арифметическая прогрессия.\n";
    SetConsoleTextAttribute(console, FOREGROUND_BLUE);
    cout << "Синий ";
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout<< "  - Самая большея геометрическая прогрессия." << endl;
   
    delete[] len_arifm;
    delete[] len_geom;
}