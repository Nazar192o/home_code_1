#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
                    ///Задание 3 Сумма четных/нечетных Вариант 11
void exes_chet();
void exes_nechet();
int main()
{
    int a;
    cout<<"Enter number -->";  //Выберите задание
    cin>>a;
    switch (a)
    {
    case 1: exes_chet();
        break;
    case 2: exes_nechet();
        break;
    }
}

void exes_chet()
{
    srand(time(NULL));
    const int n=10;
    int arr[n];
    int sum=0, count=0;
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 30-5;
        cout << arr[i] << ", ";
        if(arr[i]%2==0)
        {
            sum+=arr[i];
            count=count+1;
        }
    }
        cout<<endl;
       cout<<"kol-vo= "<<count<<" , "<<"summa= "<<sum;
}

void exes_nechet()
{
    srand(time(NULL));
    const int n=15;
    int arr[n];
    int sum=0, count=0;
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 30-5;
        cout << arr[i] << ", ";
        if(arr[i]%2!=0)
        {
            sum+=arr[i];
            count=count+1;
        }
    }
        cout<<endl;
       cout<<"kol-vo= "<<count<<" , "<<"summa= "<<sum;
}
