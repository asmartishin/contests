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

void maxIncreasingSubarray(vector<int> a, int l, int r, int& result) {
    if (l < r - 1) {
        bool success = true;
        for (size_t i = l; i < r - 1; ++i) {
            if (a[i] > a[i + 1]) {
                success = false;
            }
        }

        if (success) {
            result = max(result, r - l);
        }

        int m = (l + r) / 2;

        maxIncreasingSubarray(a, l, m, result);
        maxIncreasingSubarray(a, m, r, result);
    }

}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;
    vector<int> a(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int result = numeric_limits<int>::min();
    maxIncreasingSubarray(a, 0, n, result);

    if (result == numeric_limits<int>::min()) {
        result = 1;
    }

    cout << result << endl;

    return 0;
}
