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
    cin >> n;
    vector<int> v(n);
    vector<int> result(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(begin(v), end(v));

    for (size_t i = 0; i < n; ++i) {
        int resultIdx = (i % 2 == 0) ? i / 2 : n - 1 - i / 2;
        result[resultIdx] = v[i];
    }

    for (auto i: result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
