#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
                    ///Задание 2 a,e Вариант 11
void exes_a();
void exes_e();
int main()
{
    int a;
    cout<<"Enter number -->";  //Выберите задание
    cin>>a;
    switch (a)
    {
    case 1: exes_a();
        break;
    case 2: exes_e();
        break;
    }
}

void exes_a()
{
    srand(time(NULL));
    const int n=10;
    int arr[n];
    int sum=0, count=0;
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 20-5;
        cout << arr[i] << ", ";
        if(arr[i]>5)
        {
            sum+=arr[i];
            count=count+1;
        }
    }
        cout<<endl;
       cout<<"kol-vo= "<<count<<" , "<<"summa= "<<sum;
}

void exes_e()
{
    srand(time(NULL));
    const int n=15;
    int arr[n];
    int sum=0, count=0;
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 30-5;
        cout << arr[i] << ", ";
        if(arr[i]>20)
        {
            sum+=arr[i];
            count=count+1;
        }
    }
        cout<<endl;
       cout<<"kol-vo= "<<count<<" , "<<"summa= "<<sum;
}
