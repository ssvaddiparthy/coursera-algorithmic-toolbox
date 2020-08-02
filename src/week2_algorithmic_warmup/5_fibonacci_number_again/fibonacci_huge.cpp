#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int get_pisano(long long m){
    if (m == 0 || m == 1){
        return m;
    }

    int a = 0,  b = 1, fib = a+b;
    for (int i = 0; i < m*m; ++i) {
        fib = (a+b)%m;
        a = b;
        b = fib;
        if ( a % m == 0 && b % m == 1)
            return i+1;

    }
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    int pisano_len = get_pisano(m);
    n = n % pisano_len;

    if (n == 0 || n == 1){
        return n;
    }

    long a = 0,  b = 1, fib = a+b;
    for (int i = 2; i <= n; ++i) {
        fib = (a+b)%m;
        a = b;
        b = fib;
    }
    return fib%m;
}

int main() {
    long long n, m;
        std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}

// N more than 92 means the range is breached