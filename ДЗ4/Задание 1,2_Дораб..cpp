#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
//Вариант 11
/*Задание 1,2.Составить программу, которая будет считать количество действий
 *  перестановки элементов. Исследовать зависимость количества перестановок
 * от количества элементов в массиве (рассмотреть не менее 5-ти значений длины,
 * например, для 100, 1000, 5000, 10000, 100000). В результате исследования должна
 * получится сравнительная таблица для нескольких методов:
Сортировка выбором;
Сортировка пузырьком.
*/
          /************** Мой комментарий к заданию и коду *****************/
/** 1.Я отключил вывод значений на экран дабы повысить скорость срабатывания и тестировки
 * (при желании можно вернуть обратно, раскомментив соответствующие строчки)
    2.При запуске проги нужно выбрать:1 - сортировка вставками;2 - сортировка пузырьком;
    3-сортировка выбором
    3.Из личных наблидений(да и в ходе тестов программы)мною была замеченна достаточно большая
    разница в скорости исполнения программы(особенно стало заметно на 100000 длинны массива) в
    пользу метода вставками по сравнению с "пузырями".По количеству перестановок(их наименьшее
    число)всех их превосходит сортировка выбором, но уступает по скорости даже пузырям
    (хотя и немного).
    4.Результаты работы проги:
    1.Сортировка вставками
        ************Tablitsa**************
        Enter nember 1,2 or 3-->1

        ---------------------
        Dlina massiva-->                |10
        Kolichestvo perestanovok insert |26
        ---------------------


        ---------------------
        Dlina massiva-->                |100
        Kolichestvo perestanovok insert |1139
        ---------------------


        ---------------------
        Dlina massiva-->                |1000
        Kolichestvo perestanovok insert |31290
        ---------------------


        ---------------------
        Dlina massiva-->                |10000
        Kolichestvo perestanovok insert |52737
        ---------------------


        ---------------------
        Dlina massiva-->                |100000
        Kolichestvo perestanovok insert |241657
        ---------------------
    2. СОРТИРОВКА ПУЗЫРЬКАМИ
        ************Tablitsa**************
        Enter nember 1,2 or 3-->2

        ---------------------------------
        Dlina massiva-->                |10
        Kolichestvo perestanovok bubble |26
        ---------------------


        ---------------------------------
        Dlina massiva-->                |100
        Kolichestvo perestanovok bubble |1144
        ---------------------


        ---------------------------------
        Dlina massiva-->                |1000
        Kolichestvo perestanovok bubble |26666
        ---------------------


        ---------------------------------
        Dlina massiva-->                |10000
        Kolichestvo perestanovok bubble |64476
        ---------------------


        ---------------------------------
        Dlina massiva-->                |100000
        Kolichestvo perestanovok bubble |413194
        ---------------------
    3.СОРТИРОВКА ВЫБОРОМ
************Tablitsa**************
Enter nember 1,2 or 3-->3

---------------------
Dlina massiva-->                |10
Kolichestvo perestanovok select |11
---------------------


---------------------
Dlina massiva-->                |100
Kolichestvo perestanovok select |290
---------------------


---------------------
Dlina massiva-->                |1000
Kolichestvo perestanovok select |4618
---------------------


---------------------
Dlina massiva-->                |10000
Kolichestvo perestanovok select |19509
---------------------


---------------------
Dlina massiva-->                |100000
Kolichestvo perestanovok select |69806
---------------------
**/

void selectionSort(float arr[], int len,int schet_select);
void bubbleSort(float arr[], int len,int schet_bubble);
void insertionSort(float arr[], int len, int schet_insert);
int schet_bubble,schet_insert,schet_select=0;
int n =10;
int m=5;
int main(){
    int frog;//лучше в голову ничего не пришло)
    fstream f;
    f.open("name.txt", ios::out);
    cout << "************Tablitsa**************" << endl;
    cout<<"Enter nember 1,2 or 3-->";
    cin>>frog;
    srand(time(NULL));
    // массив вещественных чисел в диапазоне [-10, 30]
    for (int k=0;k<m;k++)
    {
        float arr[n];
//        if(n<101)
//        {
//            for(int i=0; i<n; i++)
//                {
//                arr[i] =(float)rand()/818.9-10;
//                cout << arr[i] << "| ";
//                }
//            for(int i=0; i<n; i++)
//                {
//                cout << arr[i] << "| ";
//                }
//        }
        switch(frog)
        {
            case 1:
                insertionSort(arr, n, schet_insert);//вставки
                        break;
            case 2:
                bubbleSort(arr, n, schet_bubble);//пузыри
                        break;
            case 3:
                selectionSort(arr, n, schet_select);//выбор
                        break;
        }
        cout<<endl<<"---------------------  "<<endl;
        cout<<endl;
        n=n*10;
    }
    f.close();
}

void insertionSort(float arr[], int len, int schet_insert) {
    float key = 0;
    int j = 0;
    fstream f;
    f.open("name.txt", ios::out);
    // проход по массиву
    for(int i = 1; i<len; i++)
    {
        key = arr[i];  // ключевой/текущий элемент
        j = i - 1;
        // перестановка элемента на нужное место
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
            arr[j+1] = key;
            schet_insert++;
        }
    }
    cout << endl << "---------------------  ";
    cout<<endl;
    cout<<"Dlina massiva-->"<<"\t        |"<<n<<endl;
    cout<<"Kolichestvo perestanovok insert"<<" |"<<schet_insert;
    f << endl << "---------------------  ";
    f<<endl;
    f<<"Dlina massiva-->"<<"\t        |"<<n<<endl;
    f<<"Kolichestvo perestanovok insert"<<" |"<<schet_insert;
}
void bubbleSort(float arr[], int len,int schet_bubble) {
    float tmp = 0;
    fstream f;
    f.open("name.txt", ios::out);
    // идём по массиву
    for(int i = 0; i<len; i++)
    {
        // делаем проверки в оставшейся части массива

        for(int j = len-1; j >= i+1; j--)
        {
            if(arr[j] < arr[j-1])
            {  // сравниваем соседние элементы
                // делаем перестановку
                tmp = arr[j];
                arr[j] =arr[j-1];
                arr[j-1] = tmp;
                schet_bubble++;
            }
        }

    }
     cout << endl << "---------------------------------  ";
     cout<<endl;
     cout<<"Dlina massiva-->"<<"\t        |"<<n<<endl;
     cout<<"Kolichestvo perestanovok bubble"<<" |"<<schet_bubble;
     f << endl << "---------------------------------  ";
     f<<endl;
     f<<"Dlina massiva-->"<<"\t        |"<<n<<endl;
     f<<"Kolichestvo perestanovok bubble"<<" |"<<schet_bubble;

}
void selectionSort(float arr[], int len,int schet_select) {
    int j = 0;
    float tmp = 0;
    fstream f;
    f.open("name.txt", ios::out);
    for(int i=0; i<len; i++){
        // ищем номер наименьшего элемента среди элементов от i-го до конца
        j = i;
        for(int k = i; k < len; k++)
        {
            if(arr[j] > arr[k])
            {
                j = k;
                schet_insert++;
            }
        }
        // меняем местами наибольший элемент и текущий
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;

    }
    cout << endl << "---------------------  ";
    cout<<endl;
    cout<<"Dlina massiva-->"<<"\t        |"<<n<<endl;
    cout<<"Kolichestvo perestanovok select"<<" |"<<schet_insert;
    f<< endl << "---------------------  ";
    f<<endl;
    f<<"Dlina massiva-->"<<"\t        |"<<n<<endl;
    f<<"Kolichestvo perestanovok select"<<" |"<<schet_insert;
}

