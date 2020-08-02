#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    if ( n == 0 || n == 1){
        return n;
    }

    int pisano_10 = 60;
    long long divider = 0;
    long long end = n;
    if (n > pisano_10){
        divider = n/pisano_10;
        end = end % pisano_10;
    }
    if ( end == 0 || end == 1){
        return (int) end;
    }

    int a = 0, b = 1, res = 1;
    int sum_till_60 = 1, remaining_sum = 1;
    for (int i = 2; i <= 60; ++i) {
        if (i > n and n < 60)
            return remaining_sum;
        res = (a+b)%10;
        a = b;
        b = res;

        if (i <= end)
            remaining_sum = (remaining_sum+res)%10;
        sum_till_60  = (sum_till_60+res)%10;
    }

    return (int)(((divider*sum_till_60)%10) + remaining_sum)%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
