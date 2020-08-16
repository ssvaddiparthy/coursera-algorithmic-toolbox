#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int combine(string X, string Y) {
    string XY, YX;

    XY = X.append(Y);
    YX = Y.append(X);

    return XY.compare(YX) > 0 ? 1 : 0;
}

string largest_number(vector<string> a) {
    string result;

    sort(a.begin(), a.end(), combine);
    for (auto x: a){
        result += x;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (auto & i : a) {
        std::cin >> i;
    }
    std::cout << largest_number(a);
}
