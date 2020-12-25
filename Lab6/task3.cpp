#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ZFunction(string s);
int Max(const vector<int>& arr);

int main()
{
    string str;
    cout << "Input the string: "; cin >> str;
    int res = 0;
    for (int i = 0; i < str.length(); i++) {
        string tmp = str.substr(0, i + 1);
        reverse(tmp.begin(), tmp.end());
        res += tmp.length() - Max(ZFunction(tmp));
    }
    cout << "There's " << res << " possible substrings " << '\n';
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
int Max(const vector<int>& arr)
{
    int res = INT32_MIN;
    for (auto x : arr)
        if (x > res)
            res = x;
    return res;
}