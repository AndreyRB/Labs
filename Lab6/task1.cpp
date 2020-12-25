// Lab6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> ZFunction(string s);
int main()
{
    string str;
    cout << "Input a string "; cin >> str;
    vector<int> zf = ZFunction(str);
    for (int i = 0; i < str.length(); i++)
    {
        cout << zf[i] << " ";
    }
    cout << '\n';
    system("pause");
    return 0;
}
vector<int> ZFunction(string s)
{
    vector<int> zf(s.length());

    int left = 0, right = 0;
    for (int i = 0; i < s.length(); i++)
    {
        zf[i] = max(0, min(right - i, zf[i - left]));

        while ((i + zf[i] < s.length()) && s[zf[i]] == s[i + zf[i]])
        {
            zf[i]++;
        }

        if (i + zf[i] > right)
        {
            left = i;
            right = i + zf[i];
        }
    }
    return zf;
}
