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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(begin(a), end(a));

    int currentSum = 0;
    int i = 0;

    vector<int> result;

    for (size_t i = 0; i < n; ++i) {
        int diff = max(a[i] - currentSum, 0);

        if (diff == 0) {
            continue;
        }

        currentSum += diff;
        result.push_back(diff);
    }

    for (size_t i = 0; i < k; ++i) {
        if (i < result.size()) {
            cout << result[i] << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
