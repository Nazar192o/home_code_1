#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

//Задание 3 а

void exes_a();
void exes_e();

int main()
{
    int ex;
    cout<<"Enter exercise -->";
    cin>>ex;
    switch (ex)
    {
    case 1: exes_a();
        break;
    case 2: exes_e();
        break;
    }
}
void exes_a()
{
    int i;
    float num,x,y;
    cout<<"Enter number -->";
    cin>>num;
    cout<<"Enter x -->";
    cin>>x;
    for(int i=1; i < num+1; i++)
    {
        y+=i*x;
    }
    cout<<y;
}

void exes_e()//Это было сложно, и надеюсь что все верно
{
    int i;
    float num,x,y;
    cout<<"Enter number -->";
    cin>>num;
    if(num>=7)
    {
        cout<<"Enter x -->";
        cin>>x;
        for(int i=1; i<num-5; i++)
        {
            y+=pow(-1,i)*(i/((6+i)*x));
        }
        cout<<y;
    }
    else
    {
        cout<<"Not correct number";
    }
}





