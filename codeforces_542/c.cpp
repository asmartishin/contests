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

array<pair<int, int>, 4> neighbours{{{0, -1}, {-1, 0}, {0, 1}, {1, 0}}};
int n;

set<pair<int, int>> dfs(vector<vector<int>>& matrix, pair<int, int>& start) {
    int n = matrix.size();
    set<pair<int, int>> component{start};

    vector<vector<bool>> visited(n, vector<bool>(n));
    stack<pair<int, int>> s;
    s.push(start);

    while (!s.empty()) {
        auto v = s.top();
        s.pop();

        for (const auto& nb: neighbours) {
            auto neighbour = make_pair(v.first + nb.first, v.second + nb.second);

            if (neighbour.first < 0 || neighbour.first > n - 1 || neighbour.second < 0 || neighbour.second > n - 1) {
                continue;
            }

            if (!visited[neighbour.first][neighbour.second] && matrix[neighbour.first][neighbour.second] == 0) {
                component.insert(neighbour);
                s.push(neighbour);
                visited[neighbour.first][neighbour.second] = true;
            }
        }
    }

    return component;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int r1, c1, r2, c2;
    pair<int, int> s, e;
    string row;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    --r1;
    --c1;
    --r2;
    --c2;

    s = make_pair(r1, c1);
    e = make_pair(r2, c2);
    getline(cin, row);

    for (size_t i = 0; i < n; ++i) {
        getline(cin, row);
        for (size_t j = 0; j < n; ++j) {
            matrix[i][j] = row[j] - '0';
        }
    }

    auto startComponent = dfs(matrix, s);

    if (startComponent.find(e) != startComponent.end()) {
        cout << 0 << endl;
        return 0;
    }

    auto endComponent = dfs(matrix, e);

    int result = numeric_limits<int>::max();

    for (const auto& [y1, x1]: startComponent) {
        for (const auto& [y2, x2]: endComponent) {
            result = min(result, (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        }
    }

    cout << result << endl;

    return 0;
}
