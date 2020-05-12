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
1.Объявить сущности 1 и 2. Описать их свойства. Включить одну сущность в другую.
    Объявить массив сущностей 1. Заполнить атрибуты числовыми и текстовыми значениями
    (диапазон значений определить самостоятельно).

    компьютер, жёсткий диск

2.Реализовать чтение и запись данных в
текстовый файл
бинарный файл

*/
const int string_len = 7;

struct Hard_drive{
    string firm_h; //Фирма
    int volume; // Объем, Гб
    int interest; // Доля заполненности диска
};
struct Computer{
    string firm; //Фирма
    float freq; //Частота
    float RAM; //Оперативная память
    Hard_drive Hard_drive;
};

void showComputer(const Computer s){
    cout << s.firm<< "\t"
        << s.freq << "\t"
        << s.RAM << "\t\t["
        << s.Hard_drive.firm_h << ","
        << s.Hard_drive.volume << ","
        << s.Hard_drive.interest << "]" << endl;
}

void showComputers(const Computer sts[], const int len){
    cout << " firm \t"
        << "freq \t"
        << "RAM \t["
        << "firm_h,"
        << "volume,"
        << "interest]" << endl;

    for(int i=0; i<len; i++)
    {
        showComputer(sts[i]);
    }
    cout << endl;
}

void randString(string &str, const int len){
    static const char alphabet[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // очищаем и заносим данные
    str.clear();
    str.append(len, ' ');

    for(int i=0; i < str.length(); i++){
        int r = rand() % (sizeof(alphabet)-1);
        str[i] = alphabet[r];
    }
    str[str.length()] = 0;  // последний символ сообщает о том, что строка закончилась
}

void initComputers(Computer sts[], const int len){
    for(int i=0; i<len; i++)
    {
        // Computer
        sts[i].freq = rand() % 7;
        sts[i].RAM = 7.0* (float) rand()/ RAND_MAX+1;
        randString(sts[i].firm, string_len);

        // Hard_drive
        randString(sts[i].Hard_drive.firm_h, string_len);
        sts[i].Hard_drive.volume = rand() % 1200;
        sts[i].Hard_drive.interest = rand() % 100;
    }
}

void writeTextFile(const Computer sts[], const int l){
    ofstream f;

    f.open("data.txt",ios::trunc|ios::out);
    for(int i = 0; i < l; i++)  // Все атрибуты struct  в одной строке
        f << sts[i].firm<< " "
        << sts[i].freq << " "
        << sts[i].RAM << " "
        << sts[i].Hard_drive.firm_h << " "
        << sts[i].Hard_drive.volume << " "
        << sts[i].Hard_drive.interest << endl;
    f.close();
}

void openTextFile(Computer sts[], const int l){
    ifstream f;

    f.open("data.txt",ios::trunc| ios::in);
    for(int i = 0; i < l; i++)
        f >> sts[i].firm
        >> sts[i].freq
        >> sts[i].RAM
        >> sts[i].Hard_drive.firm_h
        >> sts[i].Hard_drive.volume
        >> sts[i].Hard_drive.interest;
    f.close();
}

void writeBinFile(Computer sts[], const int l){
    // in-function WRITE code
    fstream f;
    f.open("data.bin", ios::trunc|ios::out | ios::binary);
    f.write((char*)sts, sizeof(Computer)*l);
    f.close();
}

void openBinFile(Computer sts[], const int l){
    fstream f;
    f.open("data.bin",ios::trunc| ios::in | ios::binary);
    f.read((char*)sts, sizeof(Computer)*l);
    f.close();
}


int main()
{
    // init
    cout.precision(50);
    srand(10);

    const int len = 20;
    Computer Computers[len];

    cout << "************Begin array:************************\n";
    initComputers(Computers, len);
    writeTextFile(Computers, len);
    showComputers(Computers, 5);

    cout << "************New array:************************\n";
    initComputers(Computers, len);
    showComputers(Computers, 5);

    cout << "************Read array:************************\n";
    openTextFile(Computers, len);
    showComputers(Computers, 5);

    cout << "************Binary file.************************\n";
    writeBinFile(Computers, len);

    cout << "************New array:************************\n";
    initComputers(Computers, len);
    showComputers(Computers, 5);

    cout << "************Read array:************************\n";
    openBinFile(Computers,len);
    showComputers(Computers, 5);

    return 0;
}
/* *********************************ВЫВОД************************************************
                            ************Begin array:************************
                             firm   freq    RAM     [firm_h,volume,interest]
                            WSVSOWA 1       4.6101          [BGTBGFI,581,29]
                            DGHSXJG 3       5.3901          [LPTHJFK,368,92]
                            YRXPLZG 5       4.9216          [DDTIBOB,304,13]
                            WMAQRXR 4       6.0737          [XSIXJIV,914,25]
                            EMUONSX 4       4.2611          [JSVJKPK,595,23]

                            ************New array:************************
                             firm   freq    RAM     [firm_h,volume,interest]
                            JFIJZXX 3       5.7377          [AZZRVDG,923,68]
                            KFCMISZ 5       5.2279          [USHCKLJ,99,9]
                            DZCSVHA 4       3.7159          [XSZYQDJ,811,39]
                            ZNOKBST 5       7.9504          [JIPCSCN,812,77]
                            YSKPWUF 0       7.119           [UMAMCXD,303,93]

                            ************Read array:************************
                             firm   freq    RAM     [firm_h,volume,interest]
                            WSVSOWA 1       4.6101          [BGTBGFI,581,29]
                            DGHSXJG 3       5.3901          [LPTHJFK,368,92]
                            YRXPLZG 5       4.9216          [DDTIBOB,304,13]
                            WMAQRXR 4       6.0737          [XSIXJIV,914,25]
                            EMUONSX 4       4.2611          [JSVJKPK,595,23]

                            ************Binary file.************************
                            ************New array:************************
                             firm   freq    RAM     [firm_h,volume,interest]
                            ZOWHSFD 0       7.4362          [VNTXVGS,1067,11]
                            UUQRUQU 0       3.2455          [HNKHBEO,537,1]
                            EUEVEYM 5       5.3724          [HJTDMRL,589,2]
                            WAILZII 4       2.7306          [ZEYMXUI,706,90]
                            ZPLZOIP 3       4.4606          [ETZZLLN,969,73]

                            ************Read array:************************
                             firm   freq    RAM     [firm_h,volume,interest]
                            WSVSOWA 1       4.6101          [BGTBGFI,581,29]
                            DGHSXJG 3       5.3901          [LPTHJFK,368,92]
                            YRXPLZG 5       4.9216          [DDTIBOB,304,13]
                            WMAQRXR 4       6.0737          [XSIXJIV,914,25]
                            EMUONSX 4       4.2611          [JSVJKPK,595,23]
*/
