#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>
#include <array>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    size_t n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    vector<int> c(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> l[i];
    }

    for (size_t i = 0; i < n; ++i) {
        cin >> r[i];
    }

    for (size_t i = 0; i < n; ++i) {
        c[i] = n - l[i] - r[i];
    }

    for (size_t i = 0; i < n; ++i) {
        size_t leftBigger = 0;
        size_t rightBigger = 0;

        for (size_t j = 0; j < i; ++j) {
            if (c[j] > c[i]) {
                ++leftBigger;
            }
        }

        for (size_t j = i + 1; j < n; ++j) {
            if (c[j] > c[i]) {
                ++rightBigger;
            }
        }

        if (leftBigger != l[i] || rightBigger != r[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    for (auto v: c) {
        cout << v << ' ';
    }

    cout << endl;

    return 0;
}
