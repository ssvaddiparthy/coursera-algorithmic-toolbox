#include <iostream>

int gcd_naive(int a, int b) {
    if (b == 0){
        return a;
    }

    return gcd_naive(b, a%b);
}

int max(int a, int b){
    int res = a;
    a > b ? res = a : res = b;
    return res;
}

int min(int a, int b){
    int res = a;
    a < b ? res = a : res = b;
    return res;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(max(a, b), min(a, b)) << std::endl;
  return 0;
}
