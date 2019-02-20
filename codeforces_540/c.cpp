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

    int n, a;
    cin >> n;

    map<int, int> numbersCount;

    vector<vector<int>> result(n, vector<int>(n));

    int allowedPairsCount;
    int allowedOnesCount;

    if (n % 2 == 1) {
        allowedPairsCount = n - 1;
        allowedOnesCount = 1;
    } else {
        allowedPairsCount = 0;
        allowedOnesCount = 0;
    }

    for (size_t i = 0; i < n * n; ++i) {
        cin >> a;
        ++numbersCount[a];
    }

    for (auto [number, c] : numbersCount) {
        if (c % 2 == 1) {
            --allowedOnesCount;

            if (allowedOnesCount < 0) {
                cout << "NO" << endl;
                return 0;
            }

            result[n / 2][n / 2] = number;
            --c;
        }

        if (c % 4 == 2) {
            --allowedPairsCount;

            if (allowedPairsCount < 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    auto it = numbersCount.begin();

    for (size_t i = 0; i < n / 2; ++i) {
        for (size_t j = 0; j < n / 2; ++j) {
            while (it->second < 4) {
                ++it;
            }

            result[i][j] = it->first;
            result[i][n - 1 - j] = it->first;
            result[n - 1 - i][j] = it->first;
            result[n - 1 - i][n - 1 - j] = it->first;

            it->second -= 4;
        }
    }

    if (n % 2 == 1) {
        it = numbersCount.begin();

        for (size_t j = 0; j < n / 2; ++j) {
            while (it->second < 2) {
                ++it;
            }

            result[n / 2][j] = it->first;
            result[n / 2][n - 1 - j] = it->first;

            it->second -= 2;
        }

        for (size_t i = 0; i < n / 2; ++i) {
            while (it->second < 2) {
                ++it;
            }

            result[i][n / 2] = it->first;
            result[n - 1 - i][n / 2] = it->first;

            it->second -= 2;
        }
    }

    cout << "YES" << endl;

    for (const auto& row : result) {
        for (auto el: row) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
