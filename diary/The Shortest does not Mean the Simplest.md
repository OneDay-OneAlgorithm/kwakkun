---
DONE_DATE: 2024/07/05
---
https://www.acmicpc.net/problem/11819


```c++
#include <iostream>

#define ll long long
using lll = __int128;
using namespace std;

ll fpow(lll a, lll b, lll c) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % c;
        }
        a = (a * a) % c;
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << fpow(a, b, c) << '\n';
}
```

# 분할정복을 이용한 거듭제곱

- C**n연산은 x를 n번 곱하므로 O(N)이지만, 이 방법을 사용하면 O(logN)에 거듭제곱 값을 구할 수 있다.

- 아래 코드에서 fpow함수가 그 방법이다.

- n이 1이면 그냥 C의 1제곱이므로 return C를 해준다.

- n이 2이상일 때, C의 n제곱은 다음과 같다.

    - n이 짝수일 때, C^n = C^(n/2) * C^(n/2)

    - n이 홀수일 때, C^n = C^(n/2) * C^(n/2) * C
- 잘 숙지하자



- `__int128`를 사용하여 `long long` 범위를 넘어가는 연산을 처리할 수 있다.
- `fpow` 함수를 이용하여 분할 정복을 통해 거듭제곱을 구할 수 있다.
- `a^b % c`를 구하는 문제이다.
- `b`가 매우 크기 때문에 분할 정복을 통해 풀어야 한다.
- `b`가 홀수일 때는 `res = (res * a) % c`를 해준다
- `a = (a * a) % c`를 해준다.


