#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> v;

    for (int i = 0; i < n + 1; i++) {
        vector<int> temp;
        temp.push_back(1);
        for (int j = 1; j <= i; j++) {
            temp.push_back((v[i - 1][j - 1] + v[i - 1][j]) % 10007);
        }
        temp.push_back(0);
        v.push_back(temp);
    }

//    for (auto i: v) {
//        for (auto j: i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }

    cout << v[n][k] % 10007 << endl;

    return 0;
}