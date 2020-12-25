// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prefixFunction(const string& str);
vector<int> kmpAll(const string& str, const string& pattern);

int main()
{
    string str, pattern;
    cout << "Input the string: ";
    cin >> str;
    cout << "Input the pattern: ";
    cin >> pattern;
    vector<int> pref = prefixFunction(pattern);
    cout << "Prefix func : ";
    for (int i = 0; i < pref.size(); i++)
    {
        cout << pref[i] << " ";
    }
    cout << '\n';
    vector<int> res = kmpAll(str, pattern);
    if (res.empty())
        cout << "Not found";
    else {
        cout << "Found pattern" << '\n'
            << "First at " << res.front() << '\n'
            << "Last at " << res.back() << '\n'
            << "All: ";
        for (auto x : res)
            cout << x << " ";
        cout << '\n';
    }
    system("pause");
    return 0;
}
vector<int> kmpAll(const string& str, const string& pattern)
{
    vector<int> res,
        prefixes = prefixFunction(pattern + "#" + str);
    for (int i = 0; i < prefixes.size(); i++)
        if (prefixes[i] == pattern.length())
            res.push_back(i - pattern.length() * 2);
    return res;
}
vector<int> prefixFunction(const string& str) {
    int n = str.length();
    vector<int> pi(n);
    pi[0] = 0;
    int j = 0;
    int i = 1;
    while (i != n) {
        if (str[i] == str[j]) { // ai==aj
            pi[i] = j + 1;
            i++; j++;
        }
        else 
            if (j == 0) {  // ai!=aj j == 0
                pi[i] = 0; i++;
            }
            else j = pi[j - 1]; // ai!=aj j!=0
    }
    return pi;
}
