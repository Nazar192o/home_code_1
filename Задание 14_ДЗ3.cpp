#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
   ///Задание 14 Найти наибольший элемент массива среди элементов с нечётным индексами; Вариант 11
int main()
{
    srand(time(NULL));
    const int n=10;
    int arr[n];
    int max=0;
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 20-5;
        cout << arr[i] << ", ";
        if(i%2!=0)//нечет
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
    }
    cout<<endl;
    cout<<"Max= "<<max;
}
