---
DONE_DATE: 2024/07/25
---

https://www.acmicpc.net/problem/26003

```c++
import math


# 두 점 사이의 유클리드 거리를 계산하는 함수
def euclidean_distance(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2 + (p1[2] - p2[2]) ** 2)


# 분할정복 알고리즘을 재귀적으로 수행하는 함수
def closest_pair_recursive(sorted_x, sorted_y, sorted_z):
    n = len(sorted_x)

    # 점의 수가 3개 이하이면 브루트 포스로 처리
    if n <= 3:
        return brute_force(sorted_x)

    mid = n // 2  # 중간 인덱스를 계산
    Qx = sorted_x[:mid]  # 왼쪽 절반
    Rx = sorted_x[mid:]  # 오른쪽 절반

    midpoint = sorted_x[mid][0]  # 중간점의 x좌표
    Qy = list(filter(lambda x: x[0] <= midpoint, sorted_y))  # y기준으로 왼쪽 절반
    Ry = list(filter(lambda x: x[0] > midpoint, sorted_y))  # y기준으로 오른쪽 절반
    Qz = list(filter(lambda x: x[0] <= midpoint, sorted_z))  # z기준으로 왼쪽 절반
    Rz = list(filter(lambda x: x[0] > midpoint, sorted_z))  # z기준으로 오른쪽 절반

    # 재귀적으로 왼쪽과 오른쪽 부분의 최단 거리와 그 쌍을 찾음
    (d1, pair1) = closest_pair_recursive(Qx, Qy, Qz)
    (d2, pair2) = closest_pair_recursive(Rx, Ry, Rz)

    # 두 쌍 중 최소 거리를 선택
    d = min(d1, d2)
    if d == d1:
        min_pair = pair1
    else:
        min_pair = pair2

    # 중간 부분에서의 최단 거리 쌍을 찾음
    (d3, pair3) = closest_split_pair(sorted_x, sorted_y, sorted_z, d, min_pair)

    # 전체 최단 거리 쌍을 반환
    if d3 < d:
        return d3, pair3
    else:
        return d, min_pair


# 브루트 포스 방식으로 최단 거리 쌍을 찾는 함수
def brute_force(points):
    min_dist = float('inf')  # 초기 최단 거리를 무한대로 설정
    min_pair = None
    n = len(points)

    # 모든 점 쌍을 비교하여 최단 거리 쌍을 찾음
    for i in range(n):
        for j in range(i + 1, n):
            dist = euclidean_distance(points[i], points[j])
            if dist < min_dist:
                min_dist = dist
                min_pair = (points[i], points[j])
    return min_dist, min_pair


# 분할된 영역에서 최단 거리 쌍을 찾는 함수
def closest_split_pair(p_x, p_y, p_z, delta, best_pair):
    n = len(p_x)
    mid_x = p_x[n // 2][0]

    # 중간 부분에서 delta 범위 내의 점들을 찾음
    sy = [point for point in p_y if mid_x - delta <= point[0] <= mid_x + delta]
    sz = [point for point in p_z if mid_x - delta <= point[0] <= mid_x + delta]
    best = delta
    ln_sy = len(sy)

    # 중간 부분에서의 최단 거리 쌍을 찾음
    for i in range(ln_sy - 1):
        for j in range(i + 1, min(i + 7, ln_sy)):
            p, q = sy[i], sy[j]
            dist = euclidean_distance(p, q)
            if dist < best:
                best = dist
                best_pair = (p, q)

    return best, best_pair


# 입력된 점들에 대해 최단 거리 쌍을 찾는 함수
def closest_pair(points):
    points_sorted_by_x = sorted(points, key=lambda x: x[0])
    points_sorted_by_y = sorted(points, key=lambda x: x[1])
    points_sorted_by_z = sorted(points, key=lambda x: x[2])
    return closest_pair_recursive(points_sorted_by_x, points_sorted_by_y, points_sorted_by_z)


# 입력을 받아서 점들을 저장
n = int(input().strip())
points = [tuple(map(int, input().strip().split())) for _ in range(n)]

# 최단 거리와 그 거리를 출력
distance, _ = closest_pair(points)
print(f"{distance:.6f}")

```

체점하는데 18분 걸리는 놀라운 문제다.
3차원 공간에 점이 여러개 있는데 그 중에서 제일 가까운 두 점의 거리를 구하는 문제다.
분할정복을 이용해서 풀었는데, 3차원 공간에서의 거리를 구하는 함수를 만들어서 사용했다.

https://husk321.tistory.com/225
가장 가까운 두 점 분할정복 문제 에 대해서 찾아보면 많이 나온다. 사실 이 문제는 2차원 평면에서의 가장 가까운 두 점을 찾는 문제를 3차원으로 확장한 것이다.
그래서 사실상 내가 풀었다고 말하기가 힘들다.. 기존에 있는 아이디어.



