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

    int w, h, k;

    cin >> w >> h >> k;
    int result = 0;

    for (size_t i = 1; i <= k; ++i) {
        result += 2 * (w - 4 * (i - 1)) + 2 * (h - 4 * (i - 1)) - 4;
    }

    cout << result << endl;

    return 0;
}
