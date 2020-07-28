#include <iostream>
#include <vector>
#include <algorithm>

int max(int x, int y) {
    int res;
    x > y? res = x: res = y;
    return res;
}

int min(int x, int y) {
    int res;
    x < y? res = x: res = y;
    return res;
}

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max1, max2;

    max1 = max(numbers[0], numbers[1]);
    max2 = min(numbers[0], numbers[1]);

    for (int i = 2; i < numbers.size(); ++i) {
        if (numbers[i] > max1) {
            max2 = max1;
            max1 = numbers[i];
            continue;
        }
        if (i > max2) {
            max2 = numbers[i];
        }
    }

    return max2*max1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
