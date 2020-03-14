#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <string.h>
using namespace std;
//Я объеденил два задания из таблицы, так как они относятся к одному второму заданию. Вариант 11

void exes_k();
void exes_f();

int main(){
    float a;
    cout<<"Viberete zadanie(1 ili 2)-->";
    cin>>a;
    if(a==1)
    exes_f();
    else
    exes_k();
}

void exes_f()
    {
    float max,min,x,y,h,a;
     fstream f;
     f.open("name2.txt", ios::out);
     cout<<"Enter a range[min,max]--> ";
     cin>>min>>max;
     cout<<"Enter a step-->";
     cin>>h;
     cout << "\tx\t\ty" <<   endl;
     for(x=min;x<max+0.00001;x+=h)
      {
         if(x!=0)
         {
          y = pow((-(1+3*x)/2),(1/2)) + 3*x;
          cout << "\t" << x << "\t\t"<<y<<endl;
          f<<"\t" << x << "\t\t"<<y<<endl;}
          else
          {
            x=0.00001;
            y = pow((-(1+3*x)/2),(1/2)) + 3*x;
            cout << "\t" << x << "\t\t"<<y<<endl;
            f<<"\t" << x << "\t\t"<<y<<endl;
          }

     }
      f.close();

}

void exes_k(){
    float max,min,x,y,h,a;
     fstream f;
     f.open("name.txt", ios::out);//Ответ также записывается в txt файл
     cout<<"Enter a range[min,max]--> ";
     cin>>min>>max;
     cout<<"Enter a step-->";
     cin>>h;
     cout << "\tx\t\ty" <<   endl;
     for(x=min;x<max+0.0001;x+=h)
      {
          y = pow(5+4*x,(1/2)) + 13*x+cos(12*x+91);
          cout << "\t" << x << "\t\t"<<y<<endl;
          f<<"\t" << x << "\t\t"<<y<<endl;
      }
      f.close();
}






