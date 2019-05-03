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
    cin >> n;

    vector<int> a(n);

    map<pair<int, int>, int> figuresToPoints {
        {{1, 2}, 3},
        {{1, 3}, 4},
        {{2, 1}, 3},
        {{2, 3}, -1},
        {{3, 1}, 4},
        {{3, 2}, -1}
    };

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int result = 0;

    for (size_t i = 0; i < n - 1; ++i) {
        auto pointsCount = figuresToPoints[make_pair(a[i], a[i + 1])];

        if (pointsCount == -1) {
            cout << "Infinite" << endl;
            exit(0);
        }

        result += pointsCount;

        if (i >= 1 && a[i - 1] == 3 && a[i] == 1 && a[i + 1] == 2) {
            result -= 1;
        }
    }

    cout << "Finite" << endl << result << endl;


    return 0;
}
