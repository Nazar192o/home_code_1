#include <iostream> 
#include <fstream>
using namespace std;
//Составить алгоритм, находящий, является ли частью данного слова слово “раз”.
//Ответ должен быть “да” или “нет”.
int cycle(string s1)
{
    int result = 0;
    for (int i=0; i<s1.length();i++)
    {
        if (s1[i]=='r' && s1[i+1]=='a' && s1[i+2]=='z')
        {
            result = 1;
        }
    }
    return result;
}

int main()
    {
    fstream f;
    f.open("Текст_5.txt", ios::out | ios::trunc);

    cout << "Enter the word (raz)" << endl;
    string s1;
    cin >> s1;
    f << s1 << endl;

    if (cycle(s1) == 1)
    {
        cout << "Yes" << endl;
        f << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
        f << "No" << endl;
    }
}


