#include <bits/stdc++.h>

using namespace std;

string remove(string &input, string &bomb) {
    string result;
    for (char i : input) {
        result.push_back(i);
        if (result.size() >= bomb.size() && result.substr(result.size() - bomb.size()) == bomb) {
            result.erase(result.size() - bomb.size());
        }
    }
    return result.empty() ? "FRULA" : result;
}

int main() {
    string input;
    cin >> input;
    string bomb;
    cin >> bomb;
    cout << remove(input, bomb);
}