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

using Matrix = vector<vector<char>>;

int n, m;

bool checkVertical(const Matrix& matrix) {
    if (m % 3 != 0) {
        return false;
    }

    size_t fb = m / 3;
    size_t sb = fb + m / 3;

    char fc = matrix[0][0];
    char sc = matrix[0][fb];
    char tc = matrix[0][sb];

    if (fc == sc || sc == tc || fc == tc) {
        return false;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (j >= 0 && j < fb && matrix[i][j] != fc) {
                return false;
            } else if (j >= fb && j < sb && matrix[i][j] != sc) {
                return false;
            } else if (j >= sb && j < m && matrix[i][j] != tc) {
                return false;
            }
        }
    }

    return true;
}

bool checkHorizontal(const Matrix& matrix) {
    if (n % 3 != 0) {
        return false;
    }

    size_t fb = n / 3;
    size_t sb = fb + n / 3;

    char fc = matrix[0][0];
    char sc = matrix[fb][0];
    char tc = matrix[sb][0];

    if (fc == sc || sc == tc || fc == tc) {
        return false;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (i >= 0 && i < fb && matrix[i][j] != fc) {
                return false;
            } else if (i >= fb && i < sb && matrix[i][j] != sc) {
                return false;
            } else if (i >= sb && i < n && matrix[i][j] != tc) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    cin >> n >> m;

    Matrix matrix(n, vector<char>(m));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

//    for (const auto& row: matrix) {
//        for (const auto& el: row) {
//            cout << el << ' ';
//        }
//        cout << endl;
//    }

    if (checkVertical(matrix) || checkHorizontal(matrix)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
