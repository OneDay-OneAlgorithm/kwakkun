---
DONE_DATE: 2024/07/19, 2025/01/23
---

https://www.acmicpc.net/problem/21870

2024/07/19

```c++
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> arr;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int sectionGcd(int start, int end) {
    int result = 0;
    for (int i = start; i <= end; i++) {
        result = gcd(result, arr[i]);
    }
//    cout << "sectionGCD ::: start: " << start << " end: " << end << " result: " << result << endl;
    return result;
}

int divide(int start, int end) {
    if (start == end) return arr[start];

    int mid = (start + end - 1) / 2;
//    cout << "start: " << start << " end: " << end << " mid: " << mid << endl;

    int left_side = sectionGcd(start, mid) + divide(mid + 1, end);
    int right_side = divide(start, mid) + sectionGcd(mid + 1, end);

    return max(left_side, right_side);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

//    for (auto i: arr) {
//        cout << i << " ";
//    }
//    cout << endl;

    cout << divide(0, N - 1) << endl;
}
```

2025/01/23

```c++
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int sectionGcd(vector<int> A) {
    int res = A[0];
    for (int i = 1; i < A.size(); i++) {
        res = gcd(res, A[i]);
    }
    return res;
}

int divide(vector<int> A) {
    if (A.size() == 1) {
        return A[0];
    }
    int m = A.size() / 2;
    int left = sectionGcd(vector<int>(A.begin(), A.begin() + m)) + divide(vector<int>(A.begin() + m, A.end()));
    int right = sectionGcd(vector<int>(A.begin() + m, A.end())) + divide(vector<int>(A.begin(), A.begin() + m));
    return max(left, right);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << divide(A);
}
```

## 문제 풀이

- 뭔가 어려워 보였는데 단순하다.
- 배열을 두개로 나누어서 각각의 최대 GCD를 구하고 더 큰 값을 리턴하면 된다.
- 배열을 두개로 나누는 방법은 재귀로 구현하면 된다.

## 2025/01/23 풀이

- 다시 풀어보았다.
- 왠지 모르게 첫 방법보다는 두번째 방법이 더 나은거 같다.
- gcd 함수를 잘 기억을 해야겠다. 코파일럿이 만들어버려서 놀랐다.
  `int gcd(int a, int b) {
      if (b == 0) {
          return a;
      }
      return gcd(b, a % b);
  }`
- sectionGcd 함수는 배열을 받아서 GCD를 구하는 함수이다.
- divide 함수는 배열을 받아서 나누어서 최대 GCD를 구하는 함수이다.
- 한번 틀렸는데 최댓값이라는거를 못봐가지고...
- 이터레이터를 사용해서 벡터를 나누는 방법을 사용했다.




