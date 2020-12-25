#include <iostream>
#include <string>
using namespace std;

unsigned int count_bits(unsigned int i)
{
    unsigned c = 0;
    while (i) 
    {
        c += i & 1;
        i >>= 1;
    }
    return c;
}

string invert(const string& str)
{
    string res = str;
    for (int i = 0; i < res.size(); i++) 
    {
        if (res[i] == 'a')
            res[i] = 'b';
        else
            res[i] = 'a';
    }
    return res;
}

int main()
{
    int n;
    cout << "Input n: ";
    cin >> n;
    cout << "By the definition: ";
    string str;
    for (int i = 0; i < (1 << n); i++)
        str += 'a' + count_bits(i) % 2;
    cout << str << endl
        << "By the way of getting the next string: ";
    str = "a";
    for (int i = 0; i < n; i++)
        str += invert(str);
    cout << str << endl;
    system("pause");
    return 0;
}
