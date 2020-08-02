#include <iostream>
#include <vector>
#include <numeric>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
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

int fibonacci_sum_squares_fast(long long n) {
    int a = 0,  b = 1, fib = a+b;
    std::vector<int> pisano_series;

    pisano_series.push_back(0);
    pisano_series.push_back(1);
    for (int i = 2; i < 60; ++i) {
        fib = (a + b) % 10;
        a = b;
        b = fib;
        pisano_series.push_back((fib*fib)%10);
    }

    int r = n%60;
    int rem_sum = 0;
    for (int i = 0; i < 60; ++i) {
        if (i <= r){
            rem_sum += pisano_series.at(i);
        }
    }
    return (rem_sum) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
