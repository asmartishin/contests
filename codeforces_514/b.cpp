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
    array<pair<int, int>, 8> neighbours = {
        {{-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}}
    };

    int n, m;

    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));
    vector<vector<char>> reversedMatrix(n, vector<char>(m, '.'));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (size_t i = 1; i < n - 1; ++i) {
        for (size_t j = 1; j < m - 1; ++j) {
            bool surrounded = true;

            for (const auto& nb: neighbours) {
                if (matrix[i + nb.first][j + nb.second] != '#') {
                    surrounded = false;
                }
            }

            if (surrounded) {
                for (const auto& nb: neighbours) {
                    reversedMatrix[i + nb.first][j + nb.second] = '#';
                }
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (matrix[i][j] != reversedMatrix[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}
