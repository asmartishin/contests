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

    long long n, a, sp = 0, dp = 0, s = 0, result = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> bakeries;

    cin >> n;

    for (size_t i = 0; i < 2 * n; ++i) {
        cin >> a;
        bakeries.emplace(a, i);
    }

    while (!bakeries.empty()) {
        auto b = bakeries.top();
        bakeries.pop();

        if (s % 2 == 0) {
            result += abs(sp - b.second);
            sp = b.second;
        } else {
            result += abs(dp - b.second);
            dp = b.second;
        }

        ++s;
    }

    cout << result << endl;

    return 0;
}
