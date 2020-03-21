#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;
//Задание 7
int main()
{
    float x,n,answ;
    cout<<"Enter number -->";
    cin>>x;
    cout<<"Enter degree -->";
    cin>>n;
    answ=pow(x,n);
    cout<<"Answer ="<<answ;
}
