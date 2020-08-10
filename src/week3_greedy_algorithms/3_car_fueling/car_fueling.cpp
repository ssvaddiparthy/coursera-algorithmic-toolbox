#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int fuel_left = tank, refuel_count = 0;

    for (int i = 0; i < stops.size(); i++) {
        if (fuel_left - (stops[i+1] - stops[i]) < 0) {
            refuel_count ++;
            fuel_left = tank;
            if (tank < (stops[i+1] - stops[i]))
                return -1;
        }
        fuel_left -= (stops[i+1] - stops[i]);
    }

    return refuel_count;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops;
    stops.push_back(0);
    for (size_t i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        stops.push_back(temp);
    }

    stops.push_back(d);
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
