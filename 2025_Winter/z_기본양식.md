---
DONE_DATE: 2024/10/09
---

# Animal Farm

## 난이도

- 골드 5

## 문제

https://www.acmicpc.net/problem/32449

## 알고리즘 분류

- 구현

## 오답코드

```c++
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int max_pig_v = 0;
    for (auto x: a) {
        if (x.first == "pig") max_pig_v = max(max_pig_v, x.second);
    }

    int result = 0;
    for(auto x : a) {
        if (x.first != "pig" && x.second < max_pig_v) {
            result += x.second;
        }
    }

    cout << result + max_pig_v << endl;
}
```

## 정답코드

```c++
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int max_pig_v = 0;
    for (auto x: a) {
        if (x.first == "pig") max_pig_v = max(max_pig_v, x.second);
    }

    ll result = 0;
    for(auto x : a) {
        if (x.first != "pig" && x.second < max_pig_v) {
            result += x.second;
        }
    }

    cout << result + max_pig_v << endl;
}

```

## 회고

icpc 예선을 준비하면서 처음으로 푼 문제다. 어제 풀었는데,
틀렸다고 나와서 다시 풀었다.
보니까 n이 10^5고 influence가 10^8이라서 int로는 부족했다.
그래서 long long으로 바꿔주니까 맞았다. 이 문제는 간단하게 풀 수 있었다.



