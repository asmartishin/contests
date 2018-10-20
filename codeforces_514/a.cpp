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

    int n, L, a, t, l;
    cin >> n >> L >> a;
    vector<pair<int, int>> work;

    for (size_t i = 0; i < n; ++i) {
        cin >> t >> l;
        work.push_back({t, t + l});
    }

    sort(begin(work), end(work));

    int freeTimeStart = 0;
    int breaks = 0;

    for (const auto& w: work) {
        breaks += (w.first - freeTimeStart) / a;
        freeTimeStart = w.second;
    }

    breaks += (L - freeTimeStart) / a;

    cout << breaks << endl;

    return 0;
}
