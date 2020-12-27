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

    int t, n, m;

    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n >> m;
        vector<vector<char>> matrix(n, vector<char>(m));
        vector<vector<int>> dpMatrix(n, vector<int>(m));

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '*') {
                    if (j == 0 || j == m - 1 || i == n - 1) {
                        dpMatrix[i][j] = 1;
                    } else {
                        if (dpMatrix[i + 1][j - 1] > 0 && dpMatrix[i + 1][j] > 0 && dpMatrix[i + 1][j + 1] > 0) {
                            dpMatrix[i][j] = min({dpMatrix[i + 1][j - 1], dpMatrix[i + 1][j], dpMatrix[i + 1][j + 1]}) + 1;
                        } else {
                            dpMatrix[i][j] = 1;
                        }
                    }
                }
            }
        }

        int result = 0;

//        for (const auto& row: dpMatrix) {
//            for (const auto& el : row) {
//                cout << el << ' ';
//            }
//            cout << endl;
//        }
        for (const auto& row: dpMatrix) {
            for (const auto el : row) {
                result += el;
            }
        }

        cout << result << endl;
    }

    return 0;
}
