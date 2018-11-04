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

    int n, a, b;

    cin >> n;

    vector<int> prefixes(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a;
        prefixes[a] = i + 1;
    }

    int currentPrefix = 0;
    for (size_t i = 0; i < n; ++i) {
        cin >> b;
        if (prefixes[b] > currentPrefix) {
            cout << prefixes[b] - currentPrefix << ' ';
            currentPrefix = prefixes[b];
        } else {
            cout << 0 << ' ';
        }
    }

    return 0;
}
