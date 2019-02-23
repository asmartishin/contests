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

    int n, m;
    cin >> n >> m;
    vector<int> coffees(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> coffees[i];
    }

    sort(begin(coffees), end(coffees), greater<int>());

    for (int d = 1; d <= n; ++d) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            auto coffee = max(coffees[i] - i / d, 0);
            sum += coffee;
        }

        if (sum >= m) {
            cout << d << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
