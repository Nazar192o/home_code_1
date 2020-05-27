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
}

void   SummMatrix()
{

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
    //реализация сложения
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

Second matrix:
14 0 8 3
8 7 5 12
10 4 11 4
6 10 12 3

Summ:
23 5 14 16
13 18 9 20
23 12 23 14
11 14 26 6
*************************************

Subtraction:
-5 5 -2 10
-3 4 -1 -4
3 4 1 6
-1 -6 2 0

*************************************

Multiplication:
126 0 48 39
40 77 20 96
130 32 132 40
30 40 168 9
*************************************

Transposition:
9 5 13 5
5 11 8 4
6 4 12 14
13 8 10 3
*************************************
