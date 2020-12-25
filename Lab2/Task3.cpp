#include <iostream>
#include <string>
#include <vector>

using namespace std;

int AmountShifts(string str, string str2);
void Shift(string& str);

int main()
{
	string str;		cout << "Enter str    ";	 cin >> str;
	string substr;  cout << "Enter substr "; cin >> substr;
	cout << "Amount shift's  " << AmountShifts(str, substr) << '\n';
	system("pause");
	return 0;
}
int AmountShifts(string str, string str2) {
	int k = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str == str2)return i;
		Shift(str2);
	}
	return -1;
}
void Shift(string& str) {
	char ch = str[str.size() - 1];
	for (int i = str.size() - 1; i > 0; i--)
	{
		str[i] = str[i - 1];
	}
	str[0] = ch;
}




