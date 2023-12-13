#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

const int ALPHABET_SIZE = 26;


struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
    }
};


TrieNode* createNode() {
    TrieNode* newNode = new TrieNode;
    newNode->isEndOfWord = false;
    return newNode;
}


int charToIndex(char c) {
    return c - 'a';
}


void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = charToIndex(c);
        if (node->children[index] == nullptr) {
            node->children[index] = createNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}


void traverseTrie(TrieNode* node, const string& prefix, vector<string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->children[i] != nullptr) {
            char c = i + 'a';
            traverseTrie(node->children[i], prefix + c, suggestions);
        }
    }
}

void search(TrieNode* root, const string& prefix, vector<string>& suggestions) {
    TrieNode* node = root;
    for (char c : prefix) {
        int index = charToIndex(c);
        if (node->children[index] == nullptr) {
            return;
        }
        node = node->children[index];
    }
    
    traverseTrie(node, prefix, suggestions);
}

int main() {
    TrieNode* root = createNode();

    
    ifstream file("G:/Study Material/Sem4/ASSIGNMENTS/DSA/MiniProject/TRIE/wordlist.txt");
    if (!file) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string word;
    while (getline(file, word)) {
        insert(root, word);
    }

    cout << "Welcome to Auto Suggest Program!" << endl;
    cout << "-------------------------------" << endl;

    while (true) {
        cout << "Enter a prefix (or 'q' to quit): ";
        string prefix;
        cin >> prefix;

        if (prefix == "q") {
            break;
        }

        cout << endl << "Searching for suggestions..." << endl;
        vector<string> suggestions;
        search(root, prefix, suggestions);

        if (suggestions.empty()) {
            cout << "No words found with the given prefix." << endl;
        } else {
            cout << setw(15) << left << "Word" << endl;
            cout << "--------------" << endl;
            for (const string& word : suggestions) {
                cout << setw(15) << left << word << endl;
            }
        }

        cout << endl;
    }

    cout << "Thank you for using Auto Suggest Program! Goodbye!" << endl;

    return 0;
}
