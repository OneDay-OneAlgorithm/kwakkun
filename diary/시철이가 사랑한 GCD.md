---
DONE_DATE: 2024/07/19
---
https://www.acmicpc.net/problem/21870


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

## 문제 풀이
- 뭔가 어려워 보였는데 단순하다.
- 배열을 두개로 나누어서 각각의 최대 GCD를 구하고 더 큰 값을 리턴하면 된다.
- 배열을 두개로 나누는 방법은 재귀로 구현하면 된다.




