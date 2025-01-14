#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    Node *children[10]{};
    bool isEnd;

    Node() {
        for (auto &i: children) {
            i = nullptr;
        }
        isEnd = false;
    }

    ~Node() {
        for (auto &i: children) {
            delete i;
        }
    }
};

class Trie {
public:
    Node *root;

    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }

    bool insert(string &s) const {
        Node *cur = root;
        for (char &c: s) {
            int digit = c - '0';
            if (cur->children[digit] == nullptr) {
                cur->children[digit] = new Node();
            }
            if (cur->isEnd) {
                return false;
            }
            cur = cur->children[digit];
        }

        for (auto & i : cur->children) {
            if (i != nullptr) {
                return false;
            }
        }

        cur->isEnd = true;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (string &s: v) {
            cin >> s;
        }
        Trie trie;
        bool ok = true;
        for (string &s: v) {
            if (!trie.insert(s)) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}