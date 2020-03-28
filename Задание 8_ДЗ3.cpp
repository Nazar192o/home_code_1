#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
//Задание 8 Посчитать количество (и вывести на экран) положительных/отрицательных элементов массива; Вариант 11

int main()
{
    srand(time(NULL));
    const int n=20;
    int arr[n],poloj=0,otrec=0;
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 20-5;
        cout << arr[i] << ", ";
        if(arr[i]>=0)//+ и 0
        {
            poloj++;
        }
        else    //-
        {
            otrec++;
        }
    }
    cout<<endl;
    cout<<"polojitel'nie--> "<<poloj<<' '<<"orecatel'nie--> "<<otrec;
}

