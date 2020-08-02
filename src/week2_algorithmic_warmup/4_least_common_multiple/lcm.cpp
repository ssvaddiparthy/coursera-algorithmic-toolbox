#include <iostream>

long long max(long long a, long long b) {
    long long res = 0;
    a > b ? res = a : res = b;
    return res;
}

long long min(long long a, long long b) {
    long long res = 0;
    a < b ? res = a : res = b;
    return res;
}

long long gcd_naive(long long a, long long b) {
    if (b == 0){
        return a;
    }

    return gcd_naive(b, a%b);
}

long long lcm_naive_1(long long a, long long b) {
    for (long l = a; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long) a * b;
}

long long lcm_naive(long long a, long long b) {
  return (a*b)/gcd_naive(a, b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(max(a, b), min(a, b)) << std::endl;
  return 0;
}
