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
/*Реализовать вычисление матричных норм из списка.
 * 5,2
 * Сделал следующим образом, ибо используемые мной матрицы - квадратные.
*/
void   Exes_5()
{
    const int n = 4;
    const int m = 4;
    const int d = 4;
    const int y = 4;
    int mat1[n][m]{};
    srand(time(NULL));
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
    int q;
    int sum_max=0;
    //реализация сложения
    cout<<"Conclusion:"<<endl;
    cout<<"||A||={";
    for(int d = 0; d<n; d++)
    {
        q=0;
        for(int y = 0; y<m; y++)
        {
            q+=mat1[d][y];
        }
        cout<<q<<"+";

        sum_max+=q;

    }
    cout<<"}";
    cout<<"= "<<sum_max<<endl;
    cout<<"*********************************"<<endl;
}

void   Exes_2()
{
    const int n = 4;
    const int m = 4;
    const int d = 4;
    const int y = 4;
    int mat1[n][m]{};
    srand(time(NULL));
    cout<<"Fitst matrix:"<<endl;
    for(int i = 0; i<n; i++)//заполняем матрицу
        for(int j = 0; j<m; j++)
            mat1[i][j] =9+rand()%8-12;

    for(int i = 0; i<n; i++)    //выводими матрицу
    {
        for(int j = 0; j<m; j++)
            cout << mat1[i][j] << " ";
        cout << endl;
    }
    cout<<' ' <<endl;
    int q;
    int sum_max=0;
    int max=mat1[d][y];

    cout<<"Conclusion:"<<endl;
    cout<<"||A||={";
    for(int d = 0; d<n; d++)
    {
        q=0;

        for(int y = 0; y<m; y++)
        {
            if(mat1[d][y]>0)
            q+=mat1[d][y];
        }
        cout<<q<<", ";
        if(q>max)
        {
            max=q;
        }
    }
    cout<<"}";
    cout<<"= "<<max<<endl;
}


int main()
{
    Exes_5();
    Exes_2();
}
/****************************************ВЫВОД************************************
        Fitst matrix:
        13 0 13 5
        11 10 0 10
        4 9 9 12
        2 14 2 0

        Conclusion:
        ||A||={31+31+34+18+}= 114
        *********************************
        Fitst matrix:
        4 3 2 3
        3 1 -2 4
        -1 -2 0 -3
        2 2 2 4

        Conclusion:
        ||A||={12, 8, 0, 10, }= 12
*/
