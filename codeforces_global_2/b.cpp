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
    long long h;
    cin >> n >> h;

    vector<long long> a(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int l = 0;
    int r = n;
    int result = 0;

    while (l <= r) {
        auto m = (l + r) / 2;

        vector<long long> an(m);
        for (size_t i = 0; i < m; ++i) {
            an[i] = a[i];
        }
        sort(begin(an), end(an));
        long long height = 0;

        for (int i = m - 1; i >= 0; i -= 2) {
            height += an[i];
        }

        if (height <= h) {
            result = max(result, m);
        }

        if (l == r) {
            break;
        }

        if (height > h) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << result << endl;

    return 0;
}
