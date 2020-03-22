#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
//Задание 1, Вариант 11
int main()
{
   fstream f;
   f.open("generator.txt", ios::out);
   const int n = 20;
   int arr[n];
   srand(time(NULL));
   for(int i=0; i<n; i++){
       arr[i] = rand() % 21-10;
       f<<arr[i]<<",";
   }
   for(int i=0; i<n; i++)
        cout << arr[i] << ", ";
   cout <<  endl;
   f.close();
}

