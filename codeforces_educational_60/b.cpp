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

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(begin(a), end(a));

    long long big = a[n - 1];
    long long low = a[n - 2];

    long long lowCount = m / (k + 1);

    cout << lowCount * low + (m - lowCount) * big << endl;

    return 0;
}
