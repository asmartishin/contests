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
    cin >> n;
    vector<int> a(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (size_t i = 0; i < 101; ++i) {
        int p = a[0] + i;
        bool failed = false;

        for (size_t j = 1; j < n; ++j) {
            if (a[j] != p && a[j] + i != p && a[j] - i != p) {
                failed = true;
            }
        }

        if (!failed) {
            cout << i << endl;
            return 0;
        }

        int m = a[0] - i;
        failed = false;

        for (size_t j = 1; j < n; ++j) {
            if (a[j] != m && a[j] + i != m && a[j] - i != m) {
                failed = true;
            }
        }

        if (!failed) {
            cout << i << endl;
            return 0;
        }

        int d = a[0];
        failed = false;

        for (size_t j = 1; j < n; ++j) {
            if (a[j] != d && a[j] + i != d && a[j] - i != d) {
                failed = true;
            }
        }

        if (!failed) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
