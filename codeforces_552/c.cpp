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

    int a, b, c;
    int result = numeric_limits<int>::min();
    cin >> a >> b >> c;

    vector<vector<int>> suffixTable {
        {3, 2, 2, 2, 1, 1, 1, 0},
        {2, 2, 1, 1, 1, 1, 0, 0},
        {2, 2, 2, 1, 1, 0, 0, 0}
    };

    vector<vector<int>> prefixTable {
        {0, 1, 1, 1, 2, 2, 2, 3},
        {0, 0, 1, 1, 1, 1, 2, 2},
        {0, 0, 0, 1, 1, 2, 2, 2}
    };

    for (size_t i = 0; i <= 7; ++i) {
        int an = a;
        int bn = b;
        int cn = c;

        if (suffixTable[0][i] <= an && suffixTable[1][i] <= bn && suffixTable[2][i] <= cn) {


            an -= suffixTable[0][i];
            bn -= suffixTable[1][i];
            cn -= suffixTable[2][i];

            int numberOfCycles = min({an / 3, bn / 2, cn / 2});

            an -= numberOfCycles * 3;
            bn -= numberOfCycles * 2;
            cn -= numberOfCycles * 2;

            int pr = 0;

            for (size_t j = 0; j <= 7; ++j) {
                if (prefixTable[0][j] <= an && prefixTable[1][j] <= bn && prefixTable[2][j] <= cn) {
                    pr = j;
                }
            }

            int newResult = 7 - i + numberOfCycles * 7 + pr;

//            if (newResult >= result) {
//                cout << i << ' ' << numberOfCycles << ' ' << pr << endl;
//            }

            result = max(newResult, result);
        }
    }

    for (size_t i = 0; i < 7; ++i) {
        int an = a;
        int bn = b;
        int cn = c;

        int newResult = 0;

        for (size_t j = i; j < 7; ++j) {
            if (j == 0 || j == 3 || j == 6) {
                --an;
            } else if (j == 1 || j == 5) {
                --bn;
            } else {
                --cn;
            }

            if (an >= 0 && bn >= 0 && cn >= 0) {
                ++newResult;
            }
        }

        result = max(newResult, result);
    }

    cout << result << endl;

    return 0;
}
