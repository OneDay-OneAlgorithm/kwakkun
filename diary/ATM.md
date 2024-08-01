---
DONE_DATE: 2024/08/01
---
https://www.acmicpc.net/problem/11399

```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int accum_sum = 0;
    int real_sum = 0;
    for (int i = 0; i < n; i++) {
        accum_sum += a[i];
        real_sum += accum_sum;
    }

    cout << real_sum << endl;
}


```

굉장히 간단한 그리디 문제



