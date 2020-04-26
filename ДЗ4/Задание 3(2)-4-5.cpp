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

struct Plane{
    string firm; //фирма самолотов
    int spr_win; //размах крыльев
    float flight_range; //дальность полета
};

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

void showStudent(const Plane s){
    cout << "\t"<< s.firm<< "\t"
         << "\t"<<s.spr_win << "\t"
         << "\t"<<s.flight_range << endl;
}
//поиск по размаху крыльев
int findSpr_win(const Plane s[], const int l, const float key){
    int count = 0;
    for(int i=0; i<l; i++){
        if(s[i].spr_win > key){
            showStudent(s[i]);
            count++;
        }
    }
    return count;
}
//поиск по дальности полета
int findFlight_range(const Plane s[], const int l, const float key){
    int count = 0;
    for(int i=0; i<l; i++){
        if(s[i].flight_range > key){
            showStudent(s[i]);
            count++;
        }
    }
    return count;
}
void bubbleSort(Plane data[], int n) {
    Plane tmp;
    for(int i = 0; i<n; i++){
        for(int j = n-1; j >= i+1; j--){
            if(data[j].flight_range < data[j-1].flight_range){
                tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
            }
        }
    }
}

void write2File(const Plane s[], const int l){

    ofstream f;
    f.open("data1.txt");


    for(int i = 0; i < l; i++)
        f << s[i].firm<< "\t"
          << s[i].spr_win << "\t"
          << s[i].flight_range << endl;
    f.close();
}

int main(){
    const int n = 20;
    Plane planes[n];
    srand(time(NULL));
    cout <<"\t======================================="<<endl;
    for(int i=0; i<n; i++){
        planes[i].spr_win = rand() % 90; //размах крыльев
        planes[i].flight_range = (float)rand() /1; //дальность полета
        randString(planes[i].firm); //фирма
        showStudent(planes[i]);
    }

    float avg_spr_win = 50.0;
    float avg_flight_range=10000.0;
    cout <<"\t======================================="<<endl;
    cout<< endl << "\t        Wingspan planes  "<< endl;
    cout << endl << "\t     Find all who more than " << avg_spr_win << endl;
    cout <<"\t  ********************************"<<endl;
    int findCount = findSpr_win(planes, n, avg_spr_win);
    cout << "\t\t Total " << findCount << " elements" << endl;
    cout<< endl << "\t        Flight range planes "<< endl;
    cout << endl << "\t     Find all who more than " << avg_flight_range << endl;
    cout <<"\t  ********************************"<<endl;
    int findCount1 = findFlight_range(planes, n, avg_flight_range);
    cout << "\t\t Total " << findCount1 << " elements" << endl;
    cout << endl << "\t************Sorted***************** " << endl;
    bubbleSort(planes, n);

    for(int i=0; i<n; i++)
        showStudent(planes[i]);
    write2File(planes, n);

}
