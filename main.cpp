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