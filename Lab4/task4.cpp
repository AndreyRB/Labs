#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prefixFunction(const string& str);

int main()
{
    string str;
    cout << "Input the string: "; cin >> str;
    vector<int> pi = prefixFunction(str);
    int k = str.length() - pi.back();
    if ((str.length() != k) && ((str.length() % k) == 0))
        cout << "Found the following string " << str.length()/k << " characters long: " << str.substr(0, k) << endl;
    else
        cout << "String not found" << endl;
    system("pause");
    return 0;
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