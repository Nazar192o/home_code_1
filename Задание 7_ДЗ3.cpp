#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
                    ///Задание 7 Среднее арифметич. все/полож./отрец. Вариант 11
void exes_vse();
void exes_poloj();
void exes_otrec();
int main()
{
    int a;
    cout<<"Enter number -->";  //Выберите задание
    cin>>a;
    switch (a)
    {
    case 1: exes_vse(); //Все
        break;
    case 2: exes_poloj(); //Положительные
        break;
    case 3: exes_otrec();  //Отрицательные
        break;
    }
}

void exes_vse()
{
    srand(time(NULL));
    const int n=10;
    int arr[n];
    float sr_arifm,sum=0;
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 20-5;
        cout << arr[i] << ", ";
        sum=sum+arr[i];
    }
    sr_arifm=sum/n;
    cout<<endl;
    cout<<"srednee arifmeticheskoe= "<<sr_arifm;
}
void exes_poloj()
{
    srand(time(NULL));
    const int n=10;
    int arr[n],kol_vo=0;
    float sr_arifm,sum=0;
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 20-5;
        cout << arr[i] << ", ";
        if(arr[i]>0)
        {
            sum=sum+arr[i];
            kol_vo++;
        }
    }
    sr_arifm=sum/kol_vo;
    cout<<endl;
    cout<<"srednee arifmeticheskoe= "<<sr_arifm;
}
void exes_otrec()
{
    srand(time(NULL));
    const int n=10;
    int arr[n],kol_vo=0;
    float sr_arifm,sum=0;
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 20-5;
        cout << arr[i] << ", ";
        if(arr[i]<0)
        {
            sum=sum+arr[i];
            kol_vo++;
        }
    }
    sr_arifm=sum/kol_vo;
    cout<<endl;
    cout<<"srednee arifmeticheskoe= "<<sr_arifm;
}
