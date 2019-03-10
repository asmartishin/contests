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

    vector<long long> b(n);
    vector<long long> s;

    for (size_t i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (size_t i = 0; i < n - 1; ++i) {
        s.push_back(b[i + 1] - b[i] - 1);
    }

    sort(begin(s), end(s));

    long long result = n;

    for (size_t i = 0; i < n - k; ++i) {
        result += s[i];
    }

    cout << result << endl;

    return 0;
}
