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

/*5.Реализовать чтение форматов
PNG: сигнатура и IHDR Chunk
.*/

void readPNG(string fname){
    ifstream f;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << endl;
        f.close();
        return;
    }

    #pragma pack(push, 1)  // упаковка памяти
    struct PNGCHUNK_IHDR{
        unsigned int len_raw;
        unsigned int type;
        unsigned int width;
        unsigned int height;
        unsigned char depth;
        unsigned char cType;
        unsigned char compr;
        unsigned char filter;
        unsigned char interl;
        unsigned int crc;
    };
    #pragma pack(pop)

    unsigned char sign[8];
    PNGCHUNK_IHDR ihdr;

    f.read((char*) &sign, sizeof(sign));
    f.read((char*) &ihdr, sizeof(ihdr));
    f.close();

    cout << "----------------- Read PNG ----------------- \n";
    cout << fname << endl;

    cout << "Signature (hex): " << showbase << hex
         << +sign[0] << " "
         << +sign[1] << " "
         << +sign[2] << " "
         << +sign[3] << " "
         << +sign[4] << " "
         << +sign[5] << " "
         << +sign[6] << " "
         << +sign[7] << " " << endl;

    cout << "Chunk IHDR (" << dec << sizeof(ihdr) << " bytes)"<< endl
    << "len " << ihdr.len_raw << " (true = " << __builtin_bswap32(ihdr.len_raw) << ")" << endl
    << "type    " << ihdr.type <<  " [(char) "
                << (char)(ihdr.type)
                << (char)(ihdr.type >> 8)
                << (char)(ihdr.type >> 16)
                << (char)(ihdr.type >> 24) << "]" << endl
    << "width   " << (int) ihdr.width << " (true = " << __builtin_bswap32(ihdr.width) << ")" << endl
    << "height  " << (int) ihdr.height << " (true = " << __builtin_bswap32(ihdr.height) << ")" << endl
    << "depth   " << (int) ihdr.depth << endl
    << "cType   " << (int) ihdr.cType << endl
    << "compr   " << (int) ihdr.compr << endl
    << "filter  " << (int) ihdr.filter << endl
    << "interl  " << (int) ihdr.interl << endl
    << "crc     " << (int) ihdr.crc;

    cout << endl << endl;

    // без упаковки памяти
    struct PNGCHUNK_IHDR_NONPACKED{
        unsigned int len_raw;
        unsigned int type;
        unsigned int width;
        unsigned int height;
        unsigned char depth;
        unsigned char cType;
        unsigned char compr;
        unsigned char filter;
        unsigned char interl;
        unsigned int crc;
    };

    PNGCHUNK_IHDR_NONPACKED ihdrn;

    f.open(fname);
    f.read((char*) &sign, sizeof(sign));
    f.read((char*) &ihdrn, sizeof(ihdrn));
    f.close();

    cout << "Chunk IHDR_NONPACKED (" << dec << sizeof(ihdrn) << " bytes)"<< endl
    << "len " << ihdrn.len_raw << " (true = " << __builtin_bswap32(ihdrn.len_raw) << ")" << endl
    << "type    " << ihdrn.type <<  " [(char) "
                << (char)(ihdrn.type)
                << (char)(ihdrn.type >> 8)
                << (char)(ihdrn.type >> 16)
                << (char)(ihdrn.type >> 24) << "]" << endl
    << "width   " << (int) ihdrn.width << " (true = " << __builtin_bswap32(ihdrn.width) << ")" << endl
    << "height  " << (int) ihdrn.height << " (true = " << __builtin_bswap32(ihdrn.height) << ")" << endl
    << "depth   " << (int) ihdrn.depth << endl
    << "cType   " << (int) ihdrn.cType << endl
    << "compr   " << (int) ihdrn.compr << endl
    << "filter  " << (int) ihdrn.filter << endl
    << "interl  " << (int) ihdrn.interl << endl
    << "crc     " << (int) ihdrn.crc;

    cout << endl << endl;

}

int main()
{
    readPNG("./data_samples/sevgu1.png");
    readPNG("./data_samples/sevgu2.png");
    cin.get();
    cin.get();
    return 0;
}

/************************************ВЫВОД**********************************************
 * ----------------- Read PNG -----------------
./data_samples/sevgu1.png
Signature (hex): 0x89 0x50 0x4e 0x47 0xa 0 0xe4 0
Chunk IHDR (25 bytes)
len 16619520 (true = 10026240)
type    7680 [(char)    ]
width   -462295040 (true = 15757796)
height  96256 (true = 7864576)
depth   0
cType   96
compr   2
filter  228
interl  0
crc     0

Chunk IHDR_NONPACKED (28 bytes)
len 14946712 (true = 2551309312)
type    14946720 [(char) аф ]
width   2 (true = 33554432)
height  94 (true = 1577058304)
depth   190
cType   1
compr   0
filter  191
interl  32
crc     14942816

----------------- Read PNG -----------------
./data_samples/sevgu2.png
Signature (hex): 0x89 0x50 0x4e 0x47 0xa 0 0xe4 0
Chunk IHDR (25 bytes)
len 16619520 (true = 10026240)
type    0 [(char)     ]
width   3584 (true = 917504)
height  -468608512 (true = 10097124)
depth   0
cType   5
compr   0
filter  0
interl  0
crc     20

Chunk IHDR_NONPACKED (28 bytes)
len 14946712 (true = 2551309312)
type    14946720 [(char) аф ]
width   2 (true = 33554432)
height  14946824 (true = 135455744)
depth   190
cType   1
compr   0
filter  191
interl  160
crc     1



