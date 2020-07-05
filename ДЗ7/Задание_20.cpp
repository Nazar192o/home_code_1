#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//Дана строка. Вставить после каждого символа пробел. Пробел не считается символом,
//после которого надо ставить пробел.

int main()
{
    fstream f;
    f.open("Текст_15.txt", ios::out | ios::trunc);

    string S1;
    getline(cin, S1);
    for (size_t i = 0; i < S1.size(); ++i)
    {
        S1.insert(S1.begin() + ++i, ' ');
    }
    cout << S1 << '\n';
    f << S1 << '\n';
    return 0;
}
