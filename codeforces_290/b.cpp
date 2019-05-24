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

using namespace std;

#define endl '\n'

int n, m;

array<pair<int, int>, 4> neighbours{{{0, -1}, {-1, 0}, {0, 1}, {1, 0}}};

bool hasCycle(pair<int, int> v, pair<int, int> parent, set<pair<int, int>>& visited, vector<vector<char>>& matrix) {
    visited.insert(v);

    for (const auto& p : neighbours) {
        pair<int, int> nb{v.first + p.first, v.second + p.second};

        if (nb.first < 0 || nb.first > n - 1 || nb.second < 0 || nb.second > m - 1) {
            continue;
        }

        if (matrix[nb.first][nb.second] != matrix[v.first][v.second]) {
            continue;
        }

        if (visited.find(nb) == visited.end()) {
            if (hasCycle(nb, v, visited, matrix)) {
                return true;
            }
        } else if (nb != parent) {
            return true;
        }
    }

    return false;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    set<pair<int, int>> visited;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            pair<int, int> v{i, j};
            if (visited.find(v) == visited.end()) {
                if (hasCycle(v, {-1, -1}, visited, matrix)) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;

//    for (const auto& row : matrix) {
//        for (const auto& el: row) {
//            cout << el;
//        }
//        cout << endl;
//    }

    return 0;
}
