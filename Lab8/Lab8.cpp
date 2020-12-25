#include <iostream>
#include <set>
using namespace std;

struct Bor
{
    char ch = '\0';
        bool isTerminal = false;
    set<Bor*> children;
    int wordId = 0;

    Bor* findChild(char _ch) {
        if (this->children.empty())
            return nullptr;
        for (auto x : this->children)
            if (x->ch == _ch)
                return x;
        return nullptr;
    }
    Bor* insert(char _ch) 
    {
        Bor* tmp = new Bor;
        tmp->ch = _ch;
        this->children.insert(tmp);
        return tmp;
    }

    void addVertexTotrie(Bor& root, const string& str, int id)
    {
        Bor* currentVertex = &root;
        for (auto ch : str) 
        {
            Bor* tmp = currentVertex->findChild(ch);
            if (tmp)
                currentVertex = tmp;
            else
            currentVertex = currentVertex->insert(ch);
        }
        currentVertex->isTerminal = true;
        currentVertex->wordId = id;
    }
    int findWord(Bor& root, const string& word)
    {
        Bor* currentVertex = &root;
        for (auto ch : word) {
            currentVertex = currentVertex->findChild(ch);
            if (!currentVertex)
                return -1;
        }
        if (currentVertex->isTerminal)
            return currentVertex->wordId;
        else
            return -1;
    }
};

int main()
{
    cout << "Enter a set of words. Use // to stop entry\n";
    string tmp; cin >> tmp;
    set<string> wordSet;
    while (tmp != "//") 
        wordSet.insert(tmp), cin >> tmp;
    
    Bor trie;
    int i = 0;
    for (auto x : wordSet)
        trie.addVertexTotrie(trie, x, i), i++;
    
    string word;
    cout << "Input the word to search for in the trie: "; cin >> word;

    int pos = trie.findWord(trie, word);
    if (pos == -1)  cout << "The word is not in the trie\n";
    else            cout << "Word was found, his wordId "<<pos<<'\n';
    system("pause");
    return 0;
}