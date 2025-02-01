---
DONE_DATE: 2025/02/01
---

# AC

## 난이도

- 골드 5

## 문제

https://www.acmicpc.net/problem/5430

## 알고리즘 분류

- 구현
- 자료 구조
- 문자열
- 파싱
- 덱

## 회고
- 어렵지 않다. 구현 문제답다.
- 배열 형태의 문자열을 배열로 만드는 게 어려웠다. substr을 사용하면 쉽게 해결할 수 있다.`arrayString.substr(1, arrayString.size() - 2);` 맨 앞문자열과 맨 뒤 문자열을 날린다.
- 혹은 `s.erase(s.begin()); s.pop_back();` 으로도 가능하다.
```c++
        istringstream iss(arrayString);
        string temp;
        while (getline(iss, temp, ',')) {
            dq.push_back(stoi(temp));
        }
```
- 이건 , 를 기준으로 문자열을 나누는 방법이다. `getline(iss, temp, ',')` 를 사용하면 된다. 
- 그리고 명령어를 해석하는 부분은 간단하다. D면 pop_front, R이면 뒤집는다.
- 뒤집는 것도 실제로 뒤집지 않고 방향을 바꾸는 것으로 해결했다. `isForward = !isForward;`
- isForward에 따라서 pop_front, pop_back을 해주면 된다.
- 출력할 때는 isForward에 따라 출력을 다르게 해주면 된다.
```c++
for(auto i : dq) {
    if(!first) {
        cout << ",";
    }
    cout << i;
    first = false;
}
```
- 처음에는 그냥 출력한 후 백스페이스(\b) 를 통해서 지우는 걸로 했는데 그러면 `1
D
1
[42]`
- 같은 상황에서 문제가 생긴다. first를 사용해서 출력을 제어하자.

## 전체코드

```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    string cmd;
    int n;
    string arrayString;
    deque<int> dq;

    while (T--) {
        cin >> cmd;
        cin >> n;
        cin >> arrayString;
        bool isForward = true; // right or left
        bool errorFlag = false;

        arrayString = arrayString.substr(1, arrayString.size() - 2);
        istringstream iss(arrayString);
        string temp;
        while (getline(iss, temp, ',')) {
            dq.push_back(stoi(temp));
        }

        for (auto c: cmd) {
            if (c == 'D') {
                if (dq.empty()) {
                    cout << "error" << '\n';
                    errorFlag = true;
                    break;
                }

                if (isForward) {
                    dq.pop_front();
                } else {
                    dq.pop_back();
                }
            } else { // c == 'R'
                isForward = !isForward;
            }
        }

        if (!errorFlag) {
            cout << "[";
            bool first = true;
            if(isForward) {
                for(auto i : dq) {
                    if(!first) {
                        cout << ",";
                    }
                    cout << i;
                    first = false;
                }
            } else {
                reverse(dq.begin(), dq.end());
                for(auto i : dq) {
                    if(!first) {
                        cout << ",";
                    }
                    cout << i;
                    first = false;
                }
            }
            cout << "]\n";
        }
        dq.clear();
    }
}
```


