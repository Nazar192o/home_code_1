#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
        ///Задание 12 Увеличить все нечётные элементы массива на 3, а чётные в 2 раза; Вариант 11

int main()
{
    srand(time(NULL));
    const int n=20;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 20-5;
        cout << arr[i] << "-->";
        if(arr[i]%2==0)//чет
        {
            arr[i]=arr[i]*2;
        }
        else    //нечет
        {
            arr[i]=arr[i]+3;
        }
        cout << arr[i] << " \n";
    }
}
