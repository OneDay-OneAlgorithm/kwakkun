---
DONE_DATE: 2024/07/11
---
https://codeforces.com/gym/104670/problem/L


```c++
#include <bits/stdc++.h>  
  
using namespace std;  
  
int gcd(int a, int b) {  
    return b == 0 ? a : gcd(b, a % b);  
}  
  
int lcm(int a, int b) {  
    return a / gcd(a, b) * b;  
}  
  
int main() {  
    int k;  
    cin >> k;  
  
    vector<int> v;  
  
    for (int i = 0; i < k; ++i) {  
        int y, c1, c2;  
        cin >> y >> c1 >> c2;  
        v.push_back(y + lcm(c1, c2));  
    }  
  
    int min = *min_element(v.begin(), v.end());  
  
    cout << min << endl;  
  
    return 0;  
}
```

첫 코드포스 시작이었다! [2021-2022 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2021)](https://codeforces.com/gym/104670) 
에 있는 문제들을 오늘 학교에서 풀어보는 시간을 가졌고 이것이 내가 첫번째로 맞춘 문제이다.

input;
3
1992 13 17
1992 14 18
2001 5 7

output;
2036

대강 문제는 뭔 매미가 한 쌍 씩 주기별로 태어나는데 예제로 보면 3개 쌍중에서 제일먼저 나오는게 뭔가를 묻는 문제이다. 얼마전에 최대공약수랑 최소공배수를 풀어둔게 도움이 되었다. 
최소공배수 구해서 최댓값 찾아주면 된다.