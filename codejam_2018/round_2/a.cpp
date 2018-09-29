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

    int t;
    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        int n, p, v, result = 0;
        cin >> n >> p;
        unordered_map<int, int> remainderCount;

        for (size_t j = 0; j < n; ++j) {
            cin >> v;
            auto rem = v % p;

            if (rem == 0) {
                ++result;
            } else {
                if (remainderCount.find(p - rem) != remainderCount.end() && remainderCount[p - rem] > 0) {
                    --remainderCount[p - rem];
                    ++result;
                } else {
                    ++remainderCount[rem];
                }
            }
        }

        cout << "Case #" << i + 1 << ": ";

        if (p == 2) {
            if (remainderCount[1] > 0) {
                ++result;
            }
        } else if (p == 3) {
            result += ceil((double)remainderCount[1] / 3) + ceil((double)remainderCount[2] / 3);
        } else if (p == 4) {
            if (remainderCount[2] == 1) {
                ++result;
                if (remainderCount[1] >= 2 || remainderCount[3] >= 2) {
                    remainderCount[1] = max(remainderCount[1] - 2, 0);
                    remainderCount[3] = max(remainderCount[3] - 2, 0);
                    result += ceil((double)remainderCount[1] / 4) + ceil((double)remainderCount[3] / 4);
                }
            } else {
                result += ceil((double)remainderCount[1] / 4) + ceil((double)remainderCount[3] / 4);
            }
        }

        cout << result << endl;
    }

    return 0;
}
