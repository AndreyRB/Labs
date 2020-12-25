#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

vector<int> prefixFunction(const string& str);
int KMP(const string& str, const string& pattern);

int RK(string& text, string& pattern, int q);

void to_determine_the_shifts(int a[], string pattern);
int BMH(string& text, string& pattern, int shifts[], int& amountShifts);

void SystemRandomTests(string& text, string& pattern);

int main()
{
    srand(time(0));
    string str, pattern;
    /*cout << "Input the string: "; cin >> str;
    cout << "Input the pattern: "; cin >> pattern;*/
    
    int n;
    cout << "Number of measurements = "; cin >> n;
    ofstream fout("output.txt", ios::out);
    
    fout << "KMP  "; fout << "RK  ";   fout << "BMH " << '\n';
    while(n--)
    {   
        SystemRandomTests(str, pattern);
        cout << n <<'\n';
        fout.width(3);
        {
            int amountShifts = 0;
            unsigned int start_time = clock();
            int posKMP = KMP(str, pattern);
            unsigned int end_time = clock();
            cout << "Pattern found on " << posKMP << " position. "
                << "Time KMP : " << end_time - start_time << " ms. AmountShifts = " << amountShifts << '\n';
            fout << end_time-start_time << "  ";
        }
        fout.width(3);
        {
            unsigned int start_time = clock();
            int posRK = RK(str, pattern, 10);
            unsigned int end_time = clock();
            cout << "Pattern found on " << posRK << " position. "
                << "Time RK : " << end_time - start_time << " ms. AmountShifts = 0" << '\n';
            fout << end_time - start_time << "  ";
        }
        fout.width(3);
        {
            int amountShifts = 0;
            int shifts[127] = { 0 };
            unsigned int start_time = clock();
            int posBMH = BMH(str, pattern, shifts, amountShifts);
            unsigned int end_time = clock();
            cout << "Pattern found on " << posBMH << " position. "
                << "Time BMH : " << end_time - start_time << " ms. AmountShifts = " << amountShifts << '\n';
            fout << end_time - start_time << "  ";
        }
        fout.width(10);
        fout <<"Pattern length "<<pattern.length()<< '\n';
    }
    fout.close();
    system("pause");
    return 0;
}
int KMP(const string& str, const string& pattern)
{
    vector<int> res,
        prefixes = prefixFunction(pattern + "#" + str);
    for (int i = pattern.length()+1; i < prefixes.size(); i++)
        if (prefixes[i] == pattern.length())
            return i - 2*pattern.length();
    return -1;
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

int RK(string& text, string& pattern, int q) //rabin-karp
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

void to_determine_the_shifts(int a[], string pattern) {
    int k = 1;
    for (int i = pattern.length() - 2; i >= 0; i--)
    {
        if (a[int(pattern[i])] == 0)
            a[int(pattern[i])] = k;
        k++;
    }
}
int BMH(string& text, string& pattern, int shifts[],int& amountShifts) {
    to_determine_the_shifts(shifts, pattern);
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
            j = m - 1;
            int sh = shifts[int(text[i + j])];
            if (sh == 0)
                i = i + m; //если элемент в векторе равен 0, значит этой буквы не было в pattern'e и прибавляем длину pattern'a
            else
                i = i + sh;           
            amountShifts++;
        }
    }
    return -1;
}

void SystemRandomTests(string& text, string& pattern) 
{
    ifstream in;
    in.open("inputBigText.txt", ios::in | ios::binary);
    //in.open("inputMiddleText.txt", ios::in | ios::binary);
    //in.open("inputSmallText.txt", ios::in | ios::binary);
    if(in.is_open()){
        getline(in, text, '\0');
    }
    in.close();
    int a = rand() % text.length() + 0; // количество символов
    int b = rand() % (text.length() - a) + 0; // индекс начала паттерна
    pattern.assign(text,b,a);
}