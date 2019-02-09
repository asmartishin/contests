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

vector<pair<int, int>> findAllDivisors(int n, int k) {
    vector<pair<int, int>> divisors;

    for (size_t i = 1; i < sqrt(n) + 1; ++i) {
        if (n % i == 0) {
            if (n / i <= k) {
                divisors.emplace_back(i, n / i);
            }

            if (i <= k) {
                divisors.emplace_back(n / i, i);
            }
        }
    }

    sort(begin(divisors), end(divisors));

    return divisors;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, k;
    cin >> n >> k;

    size_t maxDivCount = 0;

    auto divisors = findAllDivisors(n, k);
    size_t result = numeric_limits<int>::max();

    for (const auto & d : divisors) {
        for (size_t i = d.first * k; i < (d.first + 1) * k; ++i) {
            if ((i / k) == d.first && ((i % k) == d.second)) {
                result = min(i, result);
            }
        }
    }

    cout << result << endl;

    return 0;
}
