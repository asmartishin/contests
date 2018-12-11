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

    int n;
    cin >> n;

    vector<int> a(n);
    int result = numeric_limits<int>::max();

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int x = 0; x < n; ++x) {
        int nresult = 0;

        for (int i = 0; i < n; ++i) {
            nresult += a[i] * 2 * (abs(i - x) + i + x);
        }

        result = min(result, nresult);
    }

    if (result == numeric_limits<int>::max()) {
        cout << 0 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
