#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int counter = 0;
    cin >> n;
    string s;
    cin >> s;
    for (char i : s) {
        if (i == '1') {
            counter++;
        }
    }

    cout << counter << endl;
}