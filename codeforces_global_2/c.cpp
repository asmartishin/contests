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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    int ap = 0;
    int bp = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                ++ap;
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> b[i][j];
            if (b[i][j] == 1) {
                ++bp;
            }
        }
    }

    if (ap % 2 != bp % 2) {
        cout << "No" << endl;
        return 0;
    }

    for (size_t i = 0; i < n; ++i) {
        ap = 0;
        bp = 0;
        for (size_t j = 0; j < m; ++j) {
            if (a[i][j] == 1) {
                ++ap;
            }

            if (b[i][j] == 1) {
                ++bp;
            }
        }

        if (ap % 2 != bp % 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (size_t j = 0; j < m; ++j) {
        ap = 0;
        bp = 0;
        for (size_t i = 0; i < n; ++i) {
            if (a[i][j] == 1) {
                ++ap;
            }

            if (b[i][j] == 1) {
                ++bp;
            }
        }

        if (ap % 2 != bp % 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
