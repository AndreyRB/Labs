#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ZFunction(string s);
int FindSubstringFirst(string text, string pattern);
int FindSubstringLast(string text, string pattern);
vector<int> FindSubstrings(string text, string pattern);

int main()
{
    string str;
    cout << "Input a string "; cin >> str;
    ZFunction(str);
    string substr;
    cout << "Input a substring ";
    cin >> substr;
    cout << "first entry on the position " << FindSubstringFirst(str, substr) << '\n';
    cout << "Last entry on the position " << FindSubstringLast(str, substr) << '\n';
    vector<int> occurrences = FindSubstrings(str, substr);
    cout << "All occurences ";
    for (int i = 0; i < occurrences.size(); i++)
    {
        cout << occurrences[i] << "  ";
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
int FindSubstringFirst(string text, string pattern)
{
    vector<int> zf = ZFunction(pattern + '#' + text);
    for (int i = pattern.length() + 1; i < text.length() + 2; i++)
    {
        if (zf[i] == pattern.length())
        {
            return i - pattern.length() - 1;
        }
    }
    return -1;
}
int FindSubstringLast(string text, string pattern)
{
    vector<int> zf = ZFunction(pattern + '#' + text);
    for (int i = text.length() + 1; i >= pattern.length() + 1; i--)
    {
        if (zf[i] == pattern.length())
        {
            return i - pattern.length() - 1;
        }
    }
    return -1;
}
vector<int> FindSubstrings(string text, string pattern)
{
    vector<int> indexes;
    vector<int> zf = ZFunction(pattern + '#' + text);
    for (int i = pattern.length() + 1; i < text.length() + 2; i++)
    {
        if (zf[i] == pattern.length())
        {
            indexes.push_back(i - pattern.length() - 1);
        }
    }
    return indexes;
}

