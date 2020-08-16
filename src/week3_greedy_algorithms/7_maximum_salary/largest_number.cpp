#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int combine(string s1, string s2) {
    string s1s2, s2s1;

    s1s2 = s1 + s2;
    s2s1 = s2 + s1;

    return s1s2 >= s2s1 ? 0 : 1;
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
