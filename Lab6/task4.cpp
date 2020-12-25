#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> ZFunction(string s);
int main()
{
    string str;
    cout << "Input the string: ";
    cin >> str;
    vector<int> z = ZFunction(str);
    int k = -1;
    for (int i = 0; i < str.length(); i++)
        if (((i + z[i]) == str.length()) && ((str.length() % i) == 0)) {
            k = i;
            break;
        }
    if (k == -1)
        cout << "String not found" << '\n';
    else
        cout << "Found the following string " << str.length()/k << " characters long: " << str.substr(0, k) << '\n';
    system("pause");
    return 0;
}
vector<int> ZFunction(string s)
{
    vector<int> zf(s.length(), 0);

    int left = 0, right = 0;
    for (int i = 1; i < s.length(); i++)
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
