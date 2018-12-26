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

    int n;
    string s;

    cin >> n >> s;

    vector<int> l(n, 0);
    vector<int> r(n, 0);
    int countGold = 0;

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == 'G') {
            ++countGold;
            l[i] = 1;

            if (i > 0) {
                l[i] += l[i - 1];
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'G') {
            r[i] = 1;

            if (i < n - 1) {
                r[i] += r[i + 1];
            }
        }
    }

//    for (auto v: l) {
//        cout << v << ' ';
//    }
//    cout << endl;
//
//    for (auto v: r) {
//        cout << v << ' ';
//    }
//    cout << endl;

    int result = 0;

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == 'G') {
            continue;
        }

        int nresult = 1;

        if (i > 0) {
            nresult += l[i - 1];
        }

        if (i < n - 1) {
            nresult += r[i + 1];
        }

        result = max(result, nresult);
    }

    result = min(result, countGold);

    if (countGold == n) {
        result = countGold;
    }

    cout << result << endl;

    return 0;
}
