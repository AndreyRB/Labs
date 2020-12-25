// Lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> U(string P, const int n, char ch);
void BitShift(vector<bool>& F, const int n);
void CreateMatrix(string P, string T, const int n, const int m, vector<bool>& occurences);

vector<int> shiftOr(const string& str, const string& pattern);

int main()
{
    string T, P;
    cout << "Enter str    : "; cin >> T;
    cout << "Enter substr : ";cin >> P;
    const int m = T.length();
    const int n = P.length();

    /*bool** matrix = new bool* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new bool[m];*/
    vector<bool> occurences(m);
    cout << "ShiftAnd\n";
    CreateMatrix(P,T,n,m,occurences);
    int check = 0;
    for (int i = 0; i < m; i++)
    {
        if (occurences[i] == 1) { check++; cout << "occurence on " << (i) - (n-1)<< " position\n"; }
    }
    if (check == 0)cout << "occurences not exist\n";
    check = 0;
    cout << "\nShiftOr\n";
    vector<int> res = shiftOr(T, P);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "occurence on " << res[i] << " position\n";
    }
    if (res.size()==0)cout << "occurences not exist\n";
    cout << '\n';
    system("pause");
    return 0;
}

vector<bool> U(string P,const int n,char ch) {
    vector<bool> U(n);
    for (int i = 0; i < n; i++)
    {
        if (P[i] == ch)U[i] = 1;
    }
    return U;
}
void BitShift(vector<bool> &F,const int n) { 
    for (int i = n-1; i > 0 ; i--)
    {
        F[i] = F[i - 1];
    }
    F[0] = 1;
}
vector<bool> AND(vector<bool>U,vector<bool>F,const int n) {
    vector<bool> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = (U[i] & F[i]);
    }
    return result;
}
void CreateMatrix(string P,string T,const int n,const int m, vector<bool>& occurences) {
    vector<bool> F(n);
    vector<bool> result(n);
    for (int j = 0; j < m; j++)
    {   
        BitShift(F, n);
        result = AND( U(P,n,T[j]), F , n); 
        occurences[j] = result[n-1];
        F = result;     
    }
    for (int i = 0; i < m; i++)
    {
        cout << occurences[i] << " ";
    }
    cout << '\n';
}
//Более компактная реализация
vector<int> shiftOr(const string& str, const string& pattern)
{
    vector<int> res,
        charNumbers(256, 0);
    for (int i = 0; i < pattern.length(); i++)
        charNumbers[pattern[i]] = charNumbers[pattern[i]] | (1 << (pattern.length() - 1 - i));
    unsigned int first = 1 << (pattern.length() - 1);
    unsigned int M = ~0;
    for (int i = 0; i < str.length()-pattern.length()+1; i++) {
        unsigned int bitShift = ~M >> 1;
        M = bitShift | ~charNumbers[str[i]];
        if ((M & first) == 0)
            res.push_back(i);
    }
    return res;
}