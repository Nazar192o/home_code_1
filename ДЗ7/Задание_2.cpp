#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//Составить алгоритм, находящий, сколько раз в тексте сочетание “мир” является отдельным словом
//(пробелы перед и после).

int main()
{
    fstream f;
    f.open("Текст_2.txt", ios::out | ios::trunc);

    string s1 = "Vo vsem mire mir kak mir.";
    f << s1 << endl;
    int counter = 0;
    for (int i=0;i<s1.length();i++)
    {
        if (i==0 && s1[i]=='m' && s1[i+1]=='i' && s1[i+2]=='r' && s1[i+3]==' ')
        {
        counter++;
        }
        else
        {
            if (s1[i] =='m'&& s1[i+1]=='i'&& s1[i+2]=='r'&& s1[i-1]==' '&& s1[i+3]=='.')
            {
                counter++;
            }
            else
            {
                if (s1[i]=='m' && s1[i + 1]=='i' && s1[i+2]=='r' && s1[i-1]==' ' && s1[i + 3] == ' ')
                {
                    counter++;
                }
            }
        }
    }
    cout << counter;
    f << counter;
}

