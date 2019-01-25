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

    vector<long long> result(n + 2);

    size_t l = 1;
    size_t r = n;
    result[0] = 0;
    result[n + 1] = numeric_limits<long long>::max();

    for (size_t i = 0; i < n / 2; ++i) {
        long long b;
        cin >> b;

        if (b <= result[r + 1]) {
            result[r] = b - result[l - 1];
            result[l] = result[l - 1];
        } else if (b - result[r + 1] < result[l - 1]) {
            result[r] = b - result[l - 1];
            result[l] = result[l - 1];
        } else {
            result[l] = b - result[r + 1];
            result[r] = result[r + 1];
        }

        --r;
        ++l;
    }

    for (size_t i = 1; i < n + 1; ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}
