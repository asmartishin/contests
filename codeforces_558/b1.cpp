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

bool checkRibbons(unordered_map<int, int>& ribbonsCount) {
    map<int, int> mc;

    for (const auto& [k, v]: ribbonsCount) {
        ++mc[v];
    }

    if (
            (mc.size() == 2 && (
                (mc.rbegin()->first == 1 + mc.begin()->first && mc.rbegin()->second == 1) ||
                (mc.begin()->first == 1 && mc.begin()->second == 1)
            )) ||
            (mc.size() == 1 && (
                (mc.begin()->first == 1) ||
                (mc.begin()->second == 1)
            ))
    ) {
        return true;
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, u;
    cin >> n;

    unordered_map<int, int> ribbonsCount;

    int result = 0;

    for (size_t i = 0; i < n; ++i) {
        if (checkRibbons(ribbonsCount)) {
            result = i;
        }

        cin >> u;

        ++ribbonsCount[u];
    }

    if (checkRibbons(ribbonsCount)) {
        result = n;
    }

    cout << result << endl;

    return 0;
}
