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

    int n, m, x, x1, x2, y;
    size_t result = numeric_limits<size_t>::max();

    cin >> n >> m;
    vector<long long> vertical;
    vector<long long> horisontal;

    for (size_t i = 0; i < n; ++i) {
        cin >> x;
        vertical.push_back(x);
    }

    vertical.push_back(0);

    sort(begin(vertical), end(vertical));

    int offset = 0;

    for (size_t i = 0; i < m; ++i) {
        cin >> x1 >> x2 >> y;
        if (x1 == 1 && x2 < 1e9) {
            horisontal.push_back(x2);
        } else if (x1 == 1) {
            ++offset;
        }
    }

    horisontal.push_back(0);

    sort(begin(horisontal), end(horisontal));

    size_t p = 0;

    for (size_t i = 0; i < horisontal.size(); ++i) {
        while (p < vertical.size() && vertical[p] <= horisontal[i]) {
            ++p;
        }

        result = min(result, horisontal.size() - i - 1 + p - 1);
    }

    cout << result + offset << endl;

    return 0;
}
