#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int counter = 0;
    n = 1000 - n;
    int arr[] = {500, 100, 50, 10, 5, 1};
    for (int i = 0; i < 6; i++) {
        counter += n / arr[i];
        n %= arr[i];
    }
    cout << counter << endl;
}