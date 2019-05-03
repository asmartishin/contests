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

    long long n, z;
    cin >> n >> z;

    vector<long long> x(n);

    unordered_map<int, int> pointsCount;

    for (size_t i = 0; i < n; ++i) {
        cin >> x[i];
        ++pointsCount[x[i]];
    }

    sort(begin(x), end(x));

    long long result = 0;

    size_t l = 0;
    size_t r = n / 2;

    while (r < n && l < n / 2) {
        while (r < n - 1 && x[r] - x[l] < z) {
            ++r;
        }

        if (x[r] - x[l] >= z) {
            ++result;
        }

        ++l;
        ++r;
    }

    cout << result << endl;

    return 0;
}
