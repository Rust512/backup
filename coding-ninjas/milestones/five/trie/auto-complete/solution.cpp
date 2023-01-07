#include <iostream>
#include <vector>
#include <string>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    explicit TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }

    bool hasNoChildren() const {
        for (int i = 0; i < 26; i++) {
            if (this->children[i] != nullptr) {
                return false;
            }
        }
        return true;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    void printAllWordsWithGivenPrefix(TrieNode *root, string prefix, string word) {
        if (root->isTerminal) {
            cout << prefix << word << endl;
        }

        if (root->hasNoChildren()) {
            return;
        }

        for (int i = 0; i < 26; i++) {
            char letter = char(i + 'a');
            if (root->children[i] != nullptr) {
                printAllWordsWithGivenPrefix(root->children[i], prefix, word + letter);
            }
        }
    }

    void autoComplete(vector<string> input, string pattern) {
        for (const string& word: input) {
            this->insertWord(word);
        }

        TrieNode* current = this->root;

        for (const char& letter: pattern) {
            if (current->children[letter - 'a'] == nullptr) {
                return;
            }
            current = current->children[letter - 'a'];
        }

        printAllWordsWithGivenPrefix(current, pattern, "");
    }
};


int main() {
    initIO();
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}