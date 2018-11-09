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

    int n, m, s, e;

    cin >> n >> m;

    map<int, vector<int>> colors;

    for (size_t i = 0; i < m; ++i) {
        cin >> s >> e;
        colors[s - 1].push_back(e - 1);
    }

    vector<vector<int>> matrix(n, vector<int>(n + m, -1));
    vector<vector<pair<int, int>>> result(n);

    for (size_t i = 0; i < n; ++i) {
        matrix[i][i] = i;
        result[i].emplace_back(i, i);
    }

    size_t col = n;

    for (const auto& c: colors) {
        for (auto p: c.second) {
            matrix[c.first][col] = c.first;
            matrix[p][col] = p;
            result[c.first].emplace_back(c.first, col);
            result[p].emplace_back(p, col);
            ++col;
        }
    }

//    for (const auto& row: matrix) {
//        for (auto el: row) {
//            cout << el + 1 << ' ';
//        }
//        cout << endl;
//    }

    for (size_t i = 0; i < n; ++i) {
        cout << result[i].size() << endl;
        for (const auto& p: result[i]) {
            cout << p.second + 1 << ' ' << n - p.first << endl;
        }
    }

    return 0;
}
