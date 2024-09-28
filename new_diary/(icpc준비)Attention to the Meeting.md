---
DONE_DATE: 2024/09/28
---
https://www.acmicpc.net/problem/32432


정답코드
```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int K;
    cin >> K;

    cout << (K - (N - 1)) / N << endl;
}

```

A번 문제고 난 난이도는 브론즈다.
문제는 간단하다. 사람이 N명이고 총 가능한 시간은 K분이다.
근데 각 사람들이 말할때마다 1분씩 소요된다.
각 사람이 말할 수 있는 최대 시간을 구하면 된다.

풀어서 기분이 좋았지만 이것은 그냥 시작이었을 뿐이었으니...

