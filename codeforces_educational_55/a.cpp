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

    int t;

    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        int n, x, y, d;

        cin >> n >> x >> y >> d;

        int result = numeric_limits<int>::max();

        if (x % d == y % d) {
            result = min((abs(x - y) / d), result);
        }

        if (n % d == y % d) {
            result = min((int)ceil((n - x) / (double)d) + (n - y) / d, result);
        }

        if (y % d == 1) {
            result = min((int)ceil((x - 1) / (double)d) + (y - 1) / d, result);
        }

        if (result == numeric_limits<int>::max()) {
            cout << -1 << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
