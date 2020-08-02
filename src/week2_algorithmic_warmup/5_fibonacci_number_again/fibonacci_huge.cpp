#include <iostream>

long long get_pisano(long long m) {
    long a = 0, b = 1;
    for (int i = 0; i < m*m; ++i) {
        long temp = a;
        a = b;
        b = (temp+b)%m;
        if (a == 0 && b == 1) {
            return i + 1;
        }
    }
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    long long pis_num = get_pisano(m);

    n = n % pis_num;
    if (n == 0 || n ==1) {
        return n;
    }

    int prev = 0, cur = 1, res = prev+cur;
    for (int i = 1; i < n-1; ++i) {
        res = prev + cur;
        prev = cur;
        cur = res;
    }


}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
