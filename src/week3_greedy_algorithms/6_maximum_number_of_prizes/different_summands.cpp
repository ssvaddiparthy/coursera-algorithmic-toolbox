#include <iostream>
#include <vector>
#include <assert.h>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;

    if (n <=2){
        summands.push_back(n);
        return summands;
    }

    int i = 1;
    summands.push_back(i);
    n -= i;
    while (n > summands[i-1]) {
        i+=1;
        summands.push_back(i);
        n -= i;
    }

    if (n!=0){
        if (n <= summands[i-1]) {
            summands[i - 1] += n;
        } else {
            summands.push_back(n);
        }
    }

    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
