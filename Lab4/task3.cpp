#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

int Max(const vector<int>& arr)
{
	int res = INT32_MIN;
	for (auto x : arr)
		if (x > res)
			res = x;
	return res;
}

int main()
{
	string str;
	cout << "Input the string: ";
	cin >> str;
	int res = 0;
	for (int i = str.length() - 1; i >= 0; i--) {		// удаление символа с конца
		string tmp = str.substr(0, i + 1);		// tmp = str.substr(i, str.length() - i) - добавление символа в начало
		reverse(tmp.begin(), tmp.end());
		res += tmp.length() - Max(prefixFunction(tmp));
	}
	cout << "There's " << res << " possible substrings in the given string" << endl;
	system("pause");
	return 0;
}