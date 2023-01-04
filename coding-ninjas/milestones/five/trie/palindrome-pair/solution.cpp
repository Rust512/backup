#include <iostream>
#include <string>
#include <vector>

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
    bool isPalindrome;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        isPalindrome = false;
        childCount = 0;
    }
};

bool isPalindrome(string word) {
    int start = 0;
    int end = word.length() - 1;

    while (start <= end) {
        if (word.at(start) != word.at(end)) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
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
        int index = word.at(0) - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word.at(0));
            root->children[index] = child;
            root->childCount++;
        }

        root->isPalindrome = isPalindrome(word);

        // Recursive call
        return add(child, word.substr(1));
    }

    bool customSearch(TrieNode* root, string word) {
        if (word.length() == 0) {
            return (root->isTerminal || root->isPalindrome);
        }

        int index = word.at(0) - 'a';
        TrieNode* child = root->children[index];

        if (child == nullptr) {
            if (root->isTerminal) {
                return isPalindrome(word);
            } else {
                return false;
            }
        }

        return customSearch(child, word.substr(1));
    }

    bool customSearch(string word) {
        return customSearch(this->root, word);
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        for (string word : words) {
            this->add(string(word.rbegin(), word.rend()));
        }

        for (string word : words) {
            if (this->customSearch(word)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    initIO();
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}
