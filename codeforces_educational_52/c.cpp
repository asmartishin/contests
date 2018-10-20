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

    int n, k, height;
    cin >> n >> k;

    vector<long long> heights(2e5);

    int minHeight = numeric_limits<int>::max();
    int maxHeight = numeric_limits<int>::min();

    for (size_t i = 0; i < n; ++i) {
        cin >> height;
        minHeight = min(minHeight, height);
        maxHeight = max(maxHeight, height);
        ++heights[height];
    }

    int sliceHeight = maxHeight + 1;
    int slicesCount = 0;
    long long towersHeightSum = 0;
    long long towersCount = 0;

    while (true) {
        long long slice = towersHeightSum - towersCount * (sliceHeight - 1);

        if (slice > k) {
            ++slicesCount;
            maxHeight = sliceHeight;
            towersHeightSum = sliceHeight * towersCount;
        }

        --sliceHeight;

        if (sliceHeight == minHeight) {
            break;
        }

        towersCount += heights[sliceHeight];
        towersHeightSum += heights[sliceHeight] * sliceHeight;
    }

    if (maxHeight != minHeight) {
        ++slicesCount;
    }

    cout << slicesCount << endl;

    return 0;
}
