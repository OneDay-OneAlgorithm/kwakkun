#include <bits/stdc++.h>

using namespace std;
#define MAX_VALUE 5000001

int Prime[MAX_VALUE];

void erathostenes() {
    Prime[0] = Prime[1] = -1;

    for (int i = 2; i < MAX_VALUE; i++) {
        Prime[i] = i;
    }
    int sqrtn = int(sqrt(MAX_VALUE));

    for (int i = 2; i <= sqrtn; i++) {
        for (int j = i * i; j < MAX_VALUE; j += i) {
            if (Prime[j] == j) {
                Prime[j] = i;
            }
        }
    }
}

void factor(int num) {

    while (num > 1) {
        cout << Prime[num] << ' ';
        num /= Prime[num];
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    erathostenes();

    for (int T = 0; T < t; T++) {
        int num;
        cin >> num;
        factor(num);
    }


    return 0;
}