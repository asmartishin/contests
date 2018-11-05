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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long n, t;
    cin >> n >> t;

    long long result = 0;

    vector<long long> a(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long minCost = *min_element(begin(a), end(a));

    while (true) {
        long long moneySpend = 0;
        long long candyCount = 0;

        for (size_t i = 0; i < n; ++i) {
            if (t >= a[i]) {
                t -= a[i];
                moneySpend += a[i];
                ++candyCount;
                ++result;
            }
        }

        if (moneySpend == 0) {
            break;
        }

        long long rounds = t / moneySpend;

        result += candyCount * rounds;
        t -= moneySpend * rounds;
    }

    cout << result << endl;

    return 0;
}
