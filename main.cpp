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