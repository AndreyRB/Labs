#include <iostream>
#include <string>
using namespace std;

string nextFib(string& str)
{
    string res = str;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == 'x') {
            res.insert(i + 1, 1, 'y');
            i++;
        }
        else
            res[i] = 'x';
    }
    return res;
}

string prevFib(string& str)
{ //Используется обратный морфизм
    string res = str;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == 'x') {
            if (i < (res.size() - 1)) {
                if (res[i + 1] == 'y')
                    res.erase(i + 1, 1);
                else if (res[i + 1] == 'x') {
                    res[i] = 'y';
                }
            }
            else
                res[i] = 'y';
        }
    }
    return res;
}

int main()
{
    int n;
    cout << "Input n: "; cin >> n;
    cout << "f[n] = ";
    string str = "y";
    for (int i = 0; i < n; i++) {
        str = nextFib(str);
    }
    cout << str << '\n';
    if (n)
        cout << "f[n-1] = " << prevFib(str) << '\n';
    else
        cout << "f[n-1] not exist" << '\n';
    system("pause");
    return 0;
}