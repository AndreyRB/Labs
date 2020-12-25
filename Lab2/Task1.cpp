#include <iostream>
#include <string>
#include <vector>
#include <clocale>
#include <ctime>
#include <algorithm>

using namespace std;

//string StrRand();
int SearchMinLength(string& s) 
{
	string s1, s2;
	int j = 0;
	for (int i = 0; i < (s.length()/2); i++)
	{
		s1 += s[i];		
		
		while (j < s.length() - s1.length())
		{
			s2.assign(s, j+s1.length(), s1.length());
			if ((s1 != s2) && (s1.length() <= s2.length()))break;
			else {
				j += s1.size();
			}
		}
		if (j >= s.length() - s1.length())return s1.length();
		else j = 0;
	}
	return -1;
}

int main()
{
	srand(time(0));
	string str;	  cout << "Enter str     "; cin >> str;
	int b = rand() % (str.length()) + 1;
	string substr;
	substr.assign(str, 0,b); // assign - присваивание b первых символов строки str с позиции 0, строке substr
	cout << "Random substr "; cout<<substr<<'\n';
	cout << "";
	int result = SearchMinLength(substr);
	if (result > 0)
		cout << "Min possible length of the string S = " << SearchMinLength(substr) << '\n';
	else cout << "It is impossible to understand the minimum length of S from this substring" << '\n';
	system("pause");
	return 0;
}
//string StrRand() {
//	int AmountChar = rand() % 25000 + 1;
//	int AmountRepeat = rand() % (50000 / AmountChar) + 1; //Чтобы не превышало 50000 букв
//	string str;
//	for (int i = 0; i < AmountChar; i++)
//	{
//		char a = rand() % 122 + 97; // по таблице ascii
//		str += a;
//	}
//	for (int i = 0; i < AmountRepeat; i++)
//		str += str;
//	return str; // После этого случайным образом выбрать цифру от 1 до длины строки получившейся и это будет размер подстроки.
//}
