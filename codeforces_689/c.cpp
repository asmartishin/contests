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
#include <iomanip>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int t, n, m, idx;
    double prob;

    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n >> m;

        vector<int> input(n);

        for (int j = 0; j < n; ++j) {
            cin >> input[j];
        }

        vector<int> sorted = input;

        sort(begin(sorted), end(sorted));

        size_t badIdx = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (input[j] != sorted[j]) {
                badIdx = j;
                break;
            }
        }

        double resultProbFail = 1;
        for (int j = 0; j < m; ++j) {
            cin >> idx >> prob;
            --idx;
            if (idx >= badIdx) {
                resultProbFail *= (1 - prob);
            }
        }

        if (badIdx == 0) {
            cout << setprecision(6) << fixed << (double)1 << endl;
        } else {
            cout << setprecision(6) << fixed << 1 - resultProbFail << endl;
        }
    }

    return 0;

}
