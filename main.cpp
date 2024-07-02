#include <iostream>

using namespace std;

int factorial(int k) {
    int sum = 1;
    while (k != 0) {
        sum *= k;
        k--;
    }
    return sum;
}

int choice(int n, int k) {
    return factorial(n) / factorial(n - k) / factorial(k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    cout << choice(n, k);
}