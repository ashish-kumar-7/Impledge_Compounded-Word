#include<bits/stdc++.h>
#include <chrono>
using namespace std;


class TrieNode {
        public:
        bool isTerminal;
        vector<TrieNode *> children;
        TrieNode(int cap) {
                isTerminal=false;
                for (int i=0; i<cap; i++) {
                        children.push_back(nullptr);
                }
        }
        
        ~TrieNode() {
        for (auto it=children.begin(); it!=children.end(); it++)
                if (*it != nullptr)
                        delete(*it);
}
};

class Trie {
        TrieNode *root;
        int cap;
        public:
        Trie(int value) {
                cap = value;
                root = new TrieNode(cap);
        }

        ~Trie(){
                delete(root);
        }

        void insertWord(string word) {
                TrieNode *temp = root;
                for (int i=0;i<word.length();i++) {
                        char ch = word[i];
                        int ind = ch-'a';
                        if (temp->children[ind] == nullptr) {
                                temp->children[ind] = new TrieNode(cap);
                        }
                        temp = temp->children[ind];
                }
                if (!temp->isTerminal)
                        temp->isTerminal = true;
        }

        bool check(string word, int len) {
                TrieNode *temp = root;
                if (word.empty()) return true;
                int count = 0;
                for (int i=0;i<word.length();i++) {
                        char ch = word[i];
                        int ind = ch-'a';
                        temp = temp->children[ind];
                        if (temp != nullptr) {
                                if (temp->isTerminal) {
                                        string copy = string(word, count + 1);
                                        if (check(copy, len)) {
                                                if (word.length() != len) return true;
                                                else if (copy.length() == 0) return false;
                                                else return true;
                                        }
                                }
                        }
                        else return false;
                        count++;
                }
                if (!(temp->isTerminal)) return false;
                return false;
        }
};

void solve(Trie &T, char *data) {
        int firstL=0, secondL=0;
        string word, first, second;
        ifstream file;
        file.open(data);
        while(getline(file, word)) {
                if (T.check(word, word.length())) {
                        if (firstL < word.length()) {
                                secondL = firstL;
                                second = first;
                                firstL = word.length();
                                first = word;
                        }
                        else {
                                if (secondL <= word.length()) {
                                        secondL = word.length();
                                        second = word;
                                }
                        }
                }
        }
        file.close();
        cout << "Longest compounded word: " << first << endl;
        cout << "Second Longest compounded word: " << second << endl;
}

void load(Trie &T, char *data) {
        string word;
        ifstream file;
        file.open(data);
        while(getline(file, word)){
                T.insertWord(word);
        }
}

void getFile(char *data) {
        ifstream file;
        cout<<"Enter file name: ";
        cin>>data;
        file.open(data);
        while(!file) {
                cout << "Enter file name: ";
                cin >> data;
                file.open(data);
        }
        file.close();
}

int main() {
        
        Trie T(26);
        char data[32];

        auto start = chrono::steady_clock::now();
        getFile(data);
        load(T, data);
        solve(T, data);
        auto end = chrono::steady_clock::now();

        cout << "Time taken in seconds: "<< chrono::duration_cast<chrono::seconds>(end - start).count()<< " sec";

        return 0;
}
