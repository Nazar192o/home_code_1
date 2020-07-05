#include <iostream>
#include <locale>
#include <cstring> 
#include <fstream>
using namespace std;

int main()
    {
    fstream f;
    f.open("Текст_7.txt", ios::out | ios::trunc);

    const int lenght = 200;
    char s[lenght];
    cin.getline(s, lenght);

    f << s << endl;
    size_t maxlen = 0;
    char* maxidx = nullptr;

    for (char* c = s; *c;)
    {
        while (*c == ' ') ++c;
            if (*c == 0) break;
                char* begin = c;
        while (*c && *c != ' ') ++c;
            if (maxlen < (c - begin))
            {
                maxlen = c - begin;
                maxidx = begin;
            }
    }
    if (maxlen == 0)
    {
        cout << "Empty line!\n";
        f << "Empty line!\n";
        return 0;
    }
    else
    {
        *(maxidx + maxlen) = 0;
        cout << maxidx;
        f << maxidx;
    }
}
