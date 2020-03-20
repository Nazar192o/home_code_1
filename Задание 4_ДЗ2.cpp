#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    float x,answ;
    cout<<"Enter x -->";
    cin>>x;
    if(x>0)
    {
        answ=2*x-10;
        cout<<"Answers ="<<answ;
    }

    else if(x<0)
    {
        answ=2*abs(x)-1;
        cout<<"Answers ="<<answ;
    }

    else
    {
        answ=0;
        cout<<"Answers ="<<answ;
    }
}
