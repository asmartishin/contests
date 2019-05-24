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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, m;
    cin >> n >> m;
    bool right = true;

    vector<vector<char>> matrix(n, vector<char>(m, '.'));

    for (size_t i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (size_t j = 0; j < m; ++j) {
                matrix[i][j] = '#';
            }
        } else {
            if (right) {
                matrix[i][m - 1] = '#';
                right = false;
            } else {
                matrix[i][0] = '#';
                right = true;
            }
        }
    }

    for (const auto& row : matrix) {
        for (const auto& el: row) {
            cout << el;
        }
        cout << endl;
    }

    return 0;
}
