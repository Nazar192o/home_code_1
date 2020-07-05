#include <iostream> 
#include <fstream>
#include <string>
using namespace std;
//Дана строка. Если ее длина больше 10, то оставить в строке только первые 6 символов,
//иначе дополнить строку символами 'o' до длины 12.

string ster(string s)
{
    if (s.length() > 10)
    {
        s.erase(5, s.length() - 6);
    }
    else
    {
        int i = s.length();
        for (int i = s.length(); i < 12; i++)
        {
            s = s + 'o';
        }
    }
    return s;
}

int main()
{

fstream f;
f.open("Текст_15.txt", ios::out | ios::trunc);

string s1 = "Gggkgregrgrgrjgrgrgregnr";
string s2 = "fwef";

cout << "String 1 : " << s1 << endl;
cout << "String 2 : " << s2 << endl;

f << "String 1 : " << s1 << endl;
f << "String 2 : " << s2 << endl;


cout <<"New String 1: " << ster(s1) << endl;
cout <<"New String 2: " << ster(s2) << endl;

f << "New String 1: " << ster(s1) << endl;
f << "New String 2: " << ster(s2) << endl;
}

