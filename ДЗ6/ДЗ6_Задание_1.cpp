#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
using namespace std;

/*
2.Преобразовать матрицу, умножив элементы каждой строки на значение второго элемента этой строки.

*/
void MatRix(){
    const int rows = 5;
    const int cols = 4;
    int mat[rows][cols];

    srand(1);
    for(int i = 0; i<rows; i++)
        for(int j = 0; j<cols; j++)
            mat[i][j] = rand()%10;

    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    cout<<' ' <<endl;

    for(int i = 0; i<rows; i++)
    {
        if(i=1)
        {
            int k=0;
            for(int j = 0; j<cols; j++)
            {
                if(j>1|j<1)
                {

                    mat[k][j]=mat[k][j]*(const int)mat[k][1];
                    cout<<mat[k][j]<<' ';
                }
                else
                {
                    int m=mat[k][1]*mat[k][1];
                    cout<<m<<' ';
                }
            }
        }
        cout<<endl;
        if(i=1)
        {
            int k=1;  //отвечает за строку
            for(int j = 0; j<cols; j++)
            {
                if(j>1|j<1)
                {

                    mat[k][j]=mat[k][j]*(const int)mat[k][1];
                    cout<<mat[k][j]<<' ';
                }
                else
                {
                    int m=mat[k][1]*mat[k][1];
                    cout<<m<<' ';
                }
            }
        }
        cout<<endl;
        if(i=2)
        {
            int k=2;
            for(int j = 0; j<cols; j++)
            {
                if(j>1|j<1)
                {

                    mat[k][j]=mat[k][j]*(const int)mat[k][1];
                    cout<<mat[k][j]<<' ';
                }
                else
                {
                    int m=mat[k][1]*mat[k][1];
                    cout<<m<<' ';
                }
             }
        }
        cout<<endl;
        if(i=3)
        {
            {
                int k=3;
                for(int j = 0; j<cols; j++)
                {
                    if(j>1|j<1)
                    {

                        mat[k][j]=mat[k][j]*(const int)mat[k][1];
                        cout<<mat[k][j]<<' ';
                    }
                    else
                    {
                        int m=mat[k][1]*mat[k][1];
                        cout<<m<<' ';
                    }
                 }
            }
        }
        cout<<endl;
        if(i=4)
        {
            {
                int k=4;
                for(int j = 0; j<cols; j++)
                {
                    if(j>1|j<1)
                    {

                        mat[k][j]=mat[k][j]*(const int)mat[k][1];
                        cout<<mat[k][j]<<' ';
                    }
                    else
                    {
                        int m=mat[k][1]*mat[k][1];
                        cout<<m<<' ';
                    }
                 }
            }
        }


    }
    cout<<endl;
}
int main()
{
    MatRix();
}
/**************************************ВЫВОД******************************************
1 7 4 0
9 4 8 8
2 4 5 5
1 7 1 1
5 2 7 6

7 49 28 0
36 16 32 32
8 16 20 20
7 49 7 7
10 4 14 12

