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

const int Mod = 998244353;

int newComponents(int mask, int newMask) {
    switch (newMask) {
        case 0: switch(mask) {
            case 0: return 0;
            case 1: return 1;
            case 2: return 1;
            case 3: return 1;
        }
        case 1: switch(mask) {
            case 0: return 0;
            case 1: return 0;
            case 2: return 2;
            case 3: return 0;
        }
        case 2: switch(mask) {
            case 0: return 0;
            case 1: return 2;
            case 2: return 0;
            case 3: return 0;
        }
        case 3: switch(mask) {
            case 0: return 1;
            case 1: return 1;
            case 2: return 1;
            case 3: return 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, k;
    cin >> n >> k;

    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(2 * (n + 1), vector<long long>(4)));

    for (size_t i = 0; i < 4; ++i) {
        dp[1][0][i] = 1;
    }

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < k; ++j) {
            for (size_t m = 0; m < 4; ++m) {
                for (size_t nm = 0; nm < 4; ++nm) {
                    dp[i + 1][j + newComponents(m, nm)][nm] += dp[i][j][m];
                    dp[i + 1][j + newComponents(m, nm)][nm] %= Mod;
                }
            }
        }
    }

    long long result = 0;

    for (size_t m = 0; m < 4; ++m) {
        auto nm = newComponents(m, m ^ 3);

        if (k >= nm) {
            result += dp[n][k - nm][m];
            result %= Mod;
        }
    }

    cout << result << endl;

    return 0;
}
