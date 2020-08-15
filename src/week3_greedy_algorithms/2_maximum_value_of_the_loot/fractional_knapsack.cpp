#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    std::map<double, int, std::greater<double>> perUnit;

    for (int i = 0; i < weights.size(); ++i) {
        perUnit[(double) values[i] / weights[i]] = i;
    }

    for (auto ele: perUnit) {
        if (capacity == 0)
            return value;
        if (capacity >= weights[ele.second]){
            capacity -= weights[ele.second];
            weights[ele.second] = 0;
            value += values[ele.second];
        } else {
            value += ele.first*capacity;
            capacity = 0;
        }
    }

    return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
