#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <string.h>
using namespace std;
const int n = 4;
const int m = 4;
const int r = 4;
const int k = 4;
const int d = 4;
const int y = 4;
int mat1[n][m]{};
int mat2[r][k]{};
int summ[d][y]{};
int sub[d][y]{};
int mult[d][y]{};
int tran[d][y]{};


void   MakeMatrix()
{
    srand(time(NULL));
    cout<<"*************************************"<<endl;
    cout<<"Fitst matrix:"<<endl;
    for(int i = 0; i<n; i++)//заполняем матрицу
        for(int j = 0; j<m; j++)
            mat1[i][j] = rand()%15;

    for(int i = 0; i<n; i++)    //выводими матрицу
    {
        for(int j = 0; j<m; j++)
            cout << mat1[i][j] << " ";
        cout << endl;
    }
    cout<<' ' <<endl;

    cout<<"Second matrix:"<<endl;
    for(int r = 0; r<n; r++)//заполняем матрицу
        for(int k = 0; k<m; k++)
            mat2[r][k] = rand()%15;

    for(int r = 0; r<n; r++)    //выводими матрицу
    {
        for(int k = 0; k<m; k++)
            cout << mat2[r][k] << " ";
        cout << endl;
    }
}

void   SummMatrix()
{

    cout<<' ' <<endl;
    //реализация сложения
    cout<<"Summ:"<<endl;
    for(int d = 0; d<n; d++)
    {
        for(int y = 0; y<m; y++)
        {
            summ[d][y]=mat1[d][y]+mat2[d][y];
            cout << summ[d][y] << " ";
        }
    cout << endl;
    }
    cout<<"*************************************"<<endl;
}

void   SubtractionMatrix()
{

    cout<<' ' <<endl;
    //реализация сложения
    cout<<"Subtraction:"<<endl;
    for(int d = 0; d<n; d++)
    {
        for(int y = 0; y<m; y++)
        {
            sub[d][y]=mat1[d][y]-mat2[d][y];
            cout << sub[d][y] << " ";
        }
    cout << endl;
    }

    cout<<endl;
    cout<<"*************************************"<<endl;
}

void   MultiplicationMatrix()
{

    cout<<' ' <<endl;
    cout<<"Multiplication:"<<endl;
    for(int d = 0; d<n; d++)
    {
        for(int y = 0; y<m; y++)
        {
            mult[d][y]=mat1[d][y]*mat2[d][y];
            cout << mult[d][y] << " ";
        }
    cout << endl;
    }
    cout<<"*************************************"<<endl;
}

void   TranspositionMatrix()
{
    cout<<' ' <<endl;
    //реализация сложения
    cout<<"Transposition:"<<endl;
    for(int d = 0; d<n; d++)
    {
        for(int y = 0; y<m; y++)
        {
            tran[d][y]=mat1[y][d];
            cout << tran[d][y] << " ";
        }
    cout << endl;
    }
    cout<<"*************************************"<<endl;
}


int main()
{
    MakeMatrix();
    SummMatrix();
    SubtractionMatrix();
    MultiplicationMatrix();
    TranspositionMatrix();
}

/*********************************ВЫВОД****************************

*************************************
Fitst matrix:
12 10 13 12
9 1 7 5
11 13 6 8
1 1 9 6

Second matrix:
7 8 11 1
8 13 8 0
5 0 6 6
2 5 9 1

Summ:
19 18 24 13
17 14 15 5
16 13 12 14
3 6 18 7
*************************************

Subtraction:
5 2 2 11
1 -12 -1 5
6 13 0 2
-1 -4 0 5

*************************************

Multiplication:
84 80 143 12
72 13 56 0
55 0 36 48
2 5 81 6
*************************************

Transposition:
12 9 11 1
10 1 13 1
13 7 6 9
12 5 8 6
*************************************
