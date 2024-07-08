#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string first, second;

    cin >> first;
    cin >> second;

    first.insert(0, " ");
    second.insert(0, " ");

    int dp[first.size()][second.size()];

    for (int i = 0; i < first.size(); ++i) {
        for (int j = 0; j < second.size(); ++j) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i < first.size(); i++) {
        for (int j = 1; j < second.size(); j++) {
            if (first[i] == second[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[first.size() - 1][second.size() - 1] << endl;

    int i = first.size() - 1;
    int j = second.size() - 1;

    string result = "";

//    cout << i << " " << j << endl;
//    cout << dp[i][j] << endl;

    while (dp[i][j] != 0) {
        if (dp[i][j] != dp[i - 1][j] && dp[i][j] != dp[i][j - 1]) {
            result.insert(0, 1, first[i]);
            i--;
            j--;
        } else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        }
    }

    cout << result << endl;
}