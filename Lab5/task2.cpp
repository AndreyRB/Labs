#include <iostream>
#include <vector>
#include <string>

using namespace std;

void to_determine_the_shifts(int a[], string pattern) {
    int k = 1;
    for (int i = pattern.length()-2; i>=0; i--)
    {
        if (a[int(pattern[i])] == 0) 
                a[int(pattern[i])] = k;
        k++;
    }
}

int search(string& text, string& pattern, int shifts[]) {
    to_determine_the_shifts(shifts,pattern);
    int n = text.length();
    int m = pattern.length();
    int i = 0, j = m - 1;
    while (i < n - m + 1) 
    {
        if (pattern[j] == text[j + i]) {
            j--;
            if (j <= 0) {
                return i;
            }
        }
        else {
            int sh = shifts[int(text[i + j])];
            if (sh == 0)
                i = i + m; //если элемент в векторе равен 0, значит этой буквы не было в pattern'e и прибавляем длину pattern'a
            else
                i = i + sh;
            j = m - 1; 
        } 
        
    }
    return -1;
}
int main()
{
    string text;    cout << "Enter text : ";getline(cin, text);
    string pattern; cout << "Enter pattern : ";getline(cin, pattern);
    int Vshifts[127] = { 0 };
    int pos = search(text, pattern, Vshifts);
    if (pos == -1) cout << "Not found" << '\n';
    else cout << "The pattern was found on " << pos << " position" << '\n';
    system("pause");
    return 0;
}