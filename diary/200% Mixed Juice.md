---
DONE_DATE: 2024/07/31
---
https://www.acmicpc.net/problem/25312


```c++
def gcd(x: int, y: int) -> int:
    while y:
        x, y = y, x % y
    return x


n, m = map(int, input().split())
drinks = [list(map(int, input().split())) for _ in range(n)]
drinks.sort(key=lambda x: -(x[1] / x[0]))

total_volume = 0
total_sugar = 0
idx = 0

while total_volume + drinks[idx][0] < m:
    total_volume += drinks[idx][0]
    total_sugar += drinks[idx][1]
    idx += 1

remaining_volume = m - total_volume
total_sugar = total_sugar * drinks[idx][0] + drinks[idx][1] * remaining_volume
denominator = drinks[idx][0]

gcd_value = gcd(total_sugar, denominator)
numerator = total_sugar // gcd_value
denominator = denominator // gcd_value

print(f"{numerator}/{denominator}")

```



