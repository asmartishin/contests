#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    long long m;
    cin >> n >> m;
    vector<int> coffees(n);
    long long dsum = 0;

    for (size_t i = 0; i < n; ++i) {
        cin >> coffees[i];
        dsum += coffees[i];
    }

    sort(begin(coffees), end(coffees), greater<int>());

    int l = 1;
    int r = n + 1;
    bool found = false;

    while (l < r) {
        int d = (l + r) / 2;

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            auto coffee = max(coffees[i] - i / d, 0);
            sum += coffee;
        }

        if (sum >= m) {
            r = d;
            found = true;
        } else {
            l = d + 1;
        }
    }

    if (!found) {
        cout << -1 << endl;
    } else {
        cout << l << endl;
    }

    return 0;
}
