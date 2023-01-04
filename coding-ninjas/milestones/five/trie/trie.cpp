#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}

class TrieNode {
public:
    TrieNode** children;
    bool isTerminal;

    TrieNode() {
        this->children = new TrieNode* [26];
        for (int i = 0; i < 26; i++) {
            this->children[i] = nullptr;
        }
        this->isTerminal = false;
    }

    bool hasNoChildren() {
        for (int i = 0; i < 26; i++) {
            if (this->children[i] != nullptr) {
                return false;
            }
        }
        return true;
    }

    ~TrieNode() {
        delete [] this->children;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        this->root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* currentNode = this->root, temp;
        for (char letter : word) {
            if (currentNode->children[letter - 'a'] == nullptr) {
                currentNode->children[letter - 'a'] = new TrieNode();
            }
            currentNode = currentNode->children[letter - 'a'];
        }
        currentNode->isTerminal = true;
    }

    bool search(string word) {
        TrieNode* currentNode = this->root;
        for (char letter : word) {
            if (currentNode->children[letter - 'a'] == nullptr) {
                return false;
            }
            currentNode = currentNode->children[letter - 'a'];
        }
        return true;
    }

    void deleteWord(TrieNode* root, string word) {
        int index = word[0] - 'a';

        //base case...
        if (word.size() == 0) {
            root->isTerminal = false;
            return;
        }

        //when the word is not present in the Trie...
        if (root->children[index] == nullptr) { return; }

        //recursive call...
        TrieNode* child = root->children[index];
        deleteWord(child, word.substr(1));

        //delete the child if it is useless, i.e. when it is not a terminal and has no children.
        if (!child->isTerminal && child->hasNoChildren()) {
            delete child;
            root->children[index] = nullptr;
        }
    }

    void deleteWord(string word) {
        deleteWord(this->root, word); 
    }
};

int main() {
    Trie *trie = new Trie();
    vector<string> listOfFruits{"apple", "orange", "banana", "guava", "avocado", "mango"};
    for_each(listOfFruits.begin(), listOfFruits.end(), bind1st(mem_fun(&Trie::insert), trie));
    cout << trie->search("guava") << endl;
    trie->deleteWord("guava");
    cout << trie->search("guava") << endl;
    return 0;
}