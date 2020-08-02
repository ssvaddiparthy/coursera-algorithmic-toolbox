#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
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

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    return (get_fibonacci_huge_fast(to+2, 10) + 10 - get_fibonacci_huge_fast(from+1, 10)) %10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
