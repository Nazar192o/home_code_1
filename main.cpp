#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;

int main (){
float y,f_start, f_end;
float x;
float h;

    cin>>f_start
       >>f_end
       >>h;
    x=f_start;
    while(x<f_end)
    {

        y=3*x*x+(4/x);
        cout<<x<<"     "
           <<y<<endl;
        x=x+h;
    }
}







//    int x;
//    float a;
//    cin>>x;
//    a=(e^(x+2))+fabs(sin(x))-pow(x,4)*cos(1/x);
//    cout<<a;






//Задание1
//int main ()
//{   cout<<"*      *"<<endl
//        <<"*      *"<<endl
//        <<"********"<<endl
//        <<"*      *"<<endl
//        <<"*      *"<<endl;
//}
