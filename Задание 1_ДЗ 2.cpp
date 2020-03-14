#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
   int a;
   cout<<"Enter the number of rows --> ";
   cin>>a;
   for(int i=1; i <= a; i++)
   {
       for(int j=0; j < i; j++)
           cout << 0;
           cout << endl;
   }
}






