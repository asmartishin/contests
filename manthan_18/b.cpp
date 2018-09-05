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

    int n, s;
    cin >> n >> s;
    vector<int> values(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> values[i];
    }

    sort(begin(values), end(values));

    size_t l = 0;
    size_t r = values.size() - 1;
    long long leftDecreased = 0;
    long long rightIncreased = 0;

    while (l < r) {
        if (values[l] > s) {
            leftDecreased += values[l] - s;
        }

        if (values[r] < s) {
            rightIncreased += s - values[r];
        }
        ++l;
        --r;
    }

    cout << leftDecreased + rightIncreased + abs(values[n / 2] - s) << endl;

    return 0;
}
