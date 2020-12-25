#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int search(string& text, string& pattern, int q)
{
	int lenp = pattern.length();		
	int lent = text.length();	
	int hashp = 0;					//hash value of the pattern
	int hasht = 0;					// hash value for checking the text hash value
	for (int i = 0;i < lenp;i++)
	{
		hashp = hashp + int(pattern[i]) * pow(q, lenp - i - 1);
	}
	for (int i = 0;i < lent - lenp + 1;i++)
	{
		for (int j = i;j < i + lenp;j++)
		{
			hasht = hasht + int(text[j]) * pow(q, lenp - j - 1 + i);
		}
		if (hashp == hasht)
		{
			string check;
			check.assign(text, i, lenp);
			if (check == pattern)
				return i;
		}
		hasht = 0;
	}
	return -1;
}
int main()
{
	string text;	cout << " text   is : "; getline(cin, text);
	string pattern; cout << "pattern is : "; getline(cin, pattern);
	int q = 10;
	int pos = search(text, pattern, q);
	if (pos==-1) cout << "Not found" << '\n';
	else cout << "pattern found at position " << pos << '\n';
	system("pause");
	return 0;
}