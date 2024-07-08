---
DONE_DATE: 2024/07/08
---
https://www.acmicpc.net/problem/15965


```c++
#include <iostream>  
#include <vector>  
  
using namespace std;  
  
int main() {  
    ios::sync_with_stdio(false);  
    std::cin.tie(nullptr);  
  
    int k;  
    cin >> k;  
    int max_num = k * 20;  
    std::vector<bool> is_prime(max_num + 1, true);  
  
    is_prime[0] = is_prime[1] = false;  
    for (int i = 2; i * i <= max_num; i++) {  
        if (is_prime[i]) {  
            for (int j = i * i; j <= max_num; j += i) {  
                is_prime[j] = false;  
            }  
        }  
    }  
  
    int count = 0;  
    for (int i = 2; i <= max_num; i++) {  
        if (is_prime[i]) {  
            count++;  
            if (count == k) {  
                std::cout << i << std::endl;  
                break;  
            }  
        }  
    }  
  
    return 0;  
}
```

에라토스테네스의 체를 사용하면 된다. 재미니한테 물어보니 

`std::vector<bool>`

가 내부적으로 비트배열을 사용해서 메모리를 절약한다고 함.