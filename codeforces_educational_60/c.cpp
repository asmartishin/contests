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

#define X first
#define Y second

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int x1, y1;
    cin >> x1 >> y1;

    int x2, y2;
    cin >> x2 >> y2;

    x2 -= x1;
    y2 -= y1;

    int n;
    cin >> n;

    char c;

    map<char, pair<long long, long long>> windShifts;

    windShifts['U'] = {0, 1};
    windShifts['D'] = {0, -1};
    windShifts['L'] = {-1, 0};
    windShifts['R'] = {1, 0};

    vector<pair<long long, long long>> wind(n + 1);

    for (size_t i = 1; i <= n; ++i) {
        cin >> c;
        auto windShift = windShifts[c];

        wind[i].X = wind[i - 1].X + windShift.X;
        wind[i].Y = wind[i - 1].Y + windShift.Y;
    }

    long long l = 0, r = 1e18;
    long long m;

    while (l < r) {
        m = (l + r) / 2;
        auto mn = m;

        pair<long long, long long> windShift;

        if (mn > n) {
            long long shiftsCount = mn / n;
            windShift.X += shiftsCount * wind[n].X;
            windShift.Y += shiftsCount * wind[n].Y;

            mn %= n;
        }

        windShift.X += wind[mn].X;
        windShift.Y += wind[mn].Y;

        long long dist = abs(windShift.X - x2) + abs(windShift.Y - y2);

        if (dist <= m) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    if (l == 1e18) {
        cout << -1 << endl;
        return 0;
    }

    cout << l << endl;

    return 0;
}
