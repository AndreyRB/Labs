#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Search(string str, string substr);
int FindPositionFirst(string str, string substr);
int FindPositionLast(string str, string substr);
vector<int> Allpositions(string str, string substr);

int main()
{
	string str;		cout << "Enter str "; cin >> str;
	string substr;  cout << "Enter substr "; cin >> substr;
	if (str.size() < substr.size()) { cout << "Error"; return 0; }
	cout << "Search return  " << Search(str, substr) << '\n';
	if (Search(str, substr)) {
		cout << "Index of the first occurrence  " << FindPositionFirst(str, substr) << '\n';
		cout << "Index of the last occurrence   " << FindPositionLast(str, substr) << '\n';
		cout << "All occurrences   ";
		vector<int> vec = Allpositions(str, substr);
		for (size_t i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << '\n';
	}
	system("pause");
	return 0;
}

bool Search(string str, string substr) {
	for (int i = 0; (i < ((int)str.size() - substr.size() + 1));i++) {
		bool check = true;
		for (int j = 0; j < substr.size(); j++)
		{
			if (str[i + j] != substr[j]) check = false;
		}
		if (check)return true;
	}
	return false;
}
int FindPositionFirst(string str, string substr) {
	for (int i = 0; (i < ((int)str.size() - substr.size() + 1));i++) {
		bool check = true;
		for (int j = 0; j < substr.size(); j++)
		{
			if (str[i + j] != substr[j])
			{
				check = false;
				break;
			}
		}
		if (check)return i + 1;
	}
	return -1;
}
int FindPositionLast(string str, string substr) {
	for (int i = str.size() - 1; (i > 0 + substr.size() - 1);i--) {
		bool check = true;
		for (int j = substr.size() - 1; j >= 0; j--)
		{
			if (str[i - substr.size() + 1 + j] != substr[j]) { check = false; break; }
		}
		if (check)return i - substr.size() + 2;
	}
	return -1;
}
vector<int> Allpositions(string str, string substr) {
	vector<int> vec;
	for (int i = 0; (i < ((int)str.size() - substr.size() + 1));i++) {
		bool check = true;
		for (int j = 0; j < substr.size(); j++)
		{
			if (str[i + j] != substr[j]) { check = false; break; }
		}
		if (check)vec.push_back(i + 1);
	}
	return vec;
}

