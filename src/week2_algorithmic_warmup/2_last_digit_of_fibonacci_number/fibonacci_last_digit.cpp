#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current % 10;
        current = (tmp_previous + current) % 10;
    }

    return (current % 10);
}

int get_fibonacci_last_digit_naive_60(int n) {
    // last digits of fibonacci numbers are in a pattern with length 60.
    // so compute the last digits of 60 numbers and then repeat the same.

    return get_fibonacci_last_digit_naive(n % 60);
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive_60(n);
    std::cout << c << '\n';
}
