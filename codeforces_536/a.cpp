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

    size_t n;
    cin >> n;

    vector<vector<bool>> matrix(n, vector<bool>(n));

    string s;

    for (size_t i = 0; i < n; ++i) {
        cin >> s;
        for (size_t j = 0; j < n; ++j) {
            matrix[i][j] = s[j] == 'X';
        }
    }

    int result = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i > 0 && i < n - 1 && j > 0 && j < n - 1) {
                if (matrix[i][j] && matrix[i - 1][j - 1] && matrix[i - 1][j + 1] && matrix[i + 1][j - 1] && matrix[i + 1][j + 1]) {
                    ++result;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}
