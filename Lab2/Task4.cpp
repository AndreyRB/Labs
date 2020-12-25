#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefixFunction(const string& str);

int main()
{
	string str;	cout << "Enter str  ";	 cin >> str;
	vector<int> p = prefixFunction(str);
	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i] << " ";
	}
	cout << '\n';
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




