---
DONE_DATE: 2024/07/22
---
https://www.acmicpc.net/problem/20360


```c++
#include <bits/stdc++.h>

using namespace std;

void nToBinary(int n, int count = 0) {
    if (n == 0) {
        return;
    }
    if (n % 2 == 1) {
        cout << count << " ";
    }
    nToBinary(n / 2, count + 1);
}

int main() {
    int n;
    cin >> n;

    nToBinary(n);

    return 0;
}

```
잠깐 쉬어가는 코너...



