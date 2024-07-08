---
DONE_DATE: 2024/07/08
걸린시간: 45분
---
https://www.acmicpc.net/problem/9252


```c++
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
```

DP문제인데 단순히 길이를 구하는 것이 아닌 LCS 문자열 이 뭔지 알아야한다.
while 문이 중요한데, 거꾸로 올라오면서 역 과정을 반복하며 문자열에 삽입하면 된다.