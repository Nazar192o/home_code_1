#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

/*Объявить сущность и описать её свойства (характеристики вроде роста, цвета, названия и прочего).
 *  Объявить массивы сущностей. Заполнить атрибуты числовыми и текстовыми значениями (диапазон
 * значений определить самостоятельно).
    1.самолёт
    2.цветок
*/

struct Flower{
    string color; //цвет
    int length; //длина
    float smell; //запах от 1 до 10))
    float key;
};
const int n = 20;
Flower flowers[n];


void randString(string &str){
    static const char alphabet[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    str = "     ";

    for(int i=0; i < str.length(); i++){
        int r = rand() % (sizeof(alphabet)-1);
        str[i] = alphabet[r];
    }
    str[str.length()] = 0;
}

void showFlowers(const Flower s){
    cout << "\t"<< s.color<< "\t"
         << "\t"<<s.length << "\t"
         << "\t"<<s.smell << endl;
}

//поиск по ключю длинна цветка
int findLength(const Flower s[], const int l, const float key){
    int count = 0;
    for(int i=0; i<l; i++){
        if(s[i].length > key){
            showFlowers(s[i]);
            count++;
        }
    }
    return count;
}
//поиск по ключю запах цветка
int findSmell(const Flower s[], const int l, const float key){
    int count = 0;
    for(int i=0; i<l; i++){
        if(s[i].smell > key){
            showFlowers(s[i]);
            count++;
        }
    }
    return count;
}
void insertionSort(Flower data[], int n) {
    int key=10;
    int j = 0;
    // проход по массиву
    for(int i = 1; i<n; i++){
        key = data[i].smell;  // ключевой/текущий элемент
        j = i - 1;
        // перестановка элемента на нужное место
        while(j >= 0 && data[j].smell > key){
            data[j+1] = data[j];
            j = j-1;
            data[j+1].smell = key;
        }
    }
}

void bubbleSort(Flower data[], int n) {
    Flower tmp;
    for(int i = 0; i<n; i++){
        for(int j = n-1; j >= i+1; j--){
            if(data[j].smell < data[j-1].smell){
                tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
            }
        }
    }
}

void write2File(const Flower s[], const int l){

    ofstream f;
    f.open("data2.txt");


    for(int i = 0; i < l; i++)
        f << s[i].color<< "\t"
          << s[i].length << "\t"
          << s[i].smell << endl;
    f.close();
}

int main(){


   srand(time(NULL));

    for(int i=0; i<n; i++){
        flowers[i].length = rand() % 20; // длина стебля,см
        flowers[i].smell = rand() %11; //аромат от 1 до 10
        randString(flowers[i].color); //цвет
        showFlowers(flowers[i]);
    }


    float avg_length = 10.0;
    float avg_smell = 5.0;
    cout <<"\t==================================="<<endl;
    cout << endl << "\t        Length flowers" << endl;
    cout << endl << "\t     Find all who more than " << avg_length << endl;
    cout <<"\t  ********************************"<<endl;
    int findCount = findLength(flowers, n, avg_length);
    cout << "\t\t Total " << findCount << " elements" << endl;
    cout << endl << "\t        Smell flowers" << endl;
    cout << endl << "\t     Find all who more than " << avg_smell << endl;
    cout <<"\t  ********************************"<<endl;
    int findCount1 =findSmell(flowers, n, avg_smell);
    cout << "\t\t Total " << findCount1 << " elements" << endl;
    cout << endl << "\t************Sorted***************** " << endl;
    bubbleSort(flowers, n);


    for(int i=0; i<n; i++)
        showFlowers(flowers[i]);

    write2File(flowers, n);


}
