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

    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n);

    double sum = 0;
    double sumWithOverhead = 0;
    int c = n;
    int d = 0;

    int overhread = min({c * k, m}) / c;

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        a[i] += overhread;
        sumWithOverhead += a[i];
    }

    for (size_t i = 0; i < n; ++i) {
        if (c == 1) {
            continue;
        }
        if ((sumWithOverhead - a[i] + sumWithOverhead - sum * c - 1) / (c - 1) > sumWithOverhead / c) {
            cout << overhread << endl;
            sumWithOverhead = sumWithOverhea - a[i] + min(overhread - 1, k * c - overhread * c);
            --c;
            ++d;
            overhread = min({c * k, m - d}) / c;
        }
    }

    cout << sum / c << endl;

    return 0;
}
