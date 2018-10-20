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

    size_t n, failedStep = 0;
    long long a;
    unordered_set<long long> nums;

    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        ++failedStep;
        cin >> a;

        if (a != 0 && nums.find(a - 1) == nums.end()) {
            cout << failedStep << endl;
            return 0;
        }

        nums.insert(a);
    }

    cout << -1 << endl;

    return 0;
}
