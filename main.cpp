#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int k;
    cin >> k;

    vector<int> v;

    for (int i = 0; i < k; ++i) {
        int y, c1, c2;
        cin >> y >> c1 >> c2;
        v.push_back(y + lcm(c1, c2));
    }

    int min = *min_element(v.begin(), v.end());

    cout << min << endl;

    return 0;
}