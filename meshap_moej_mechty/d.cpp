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

using namespace std;

#define endl '\n'

set<long long> computeDivisors(long long number) {
    set<long long> divisors;

    for (size_t i = 1; i <= std::sqrt(number); ++i) {
        if (number % i == 0) {
            if (number / i == i) {
                divisors.insert(i);
            } else {
                divisors.insert(i);
                divisors.insert(number / i);
            }
        }
    }

    return divisors;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long t, n, d;
    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        cin >> n;
        set<long long> divisors;

        for (size_t i = 0; i < n; ++i) {
            cin >> d;
            divisors.insert(d);
        }

        long long result = *divisors.begin() * *divisors.rbegin();

        auto resultDivisors = computeDivisors(result);

        divisors.insert(1);
        divisors.insert(result);

        if (divisors == resultDivisors) {
            cout << result << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
