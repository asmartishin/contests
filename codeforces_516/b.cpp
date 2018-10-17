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

vector<int> toBinary(long long value) {
    vector<int> result;

    while (value) {
        result.push_back(value % 2);
        value /= 2;
    }

    reverse(begin(result), end(result));

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int t;
    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        int ones = 0;
        long long a;
        cin >> a;

        for (const auto& v: toBinary(a)) {
            if (v == 1) {
                ++ones;
            }
        }

        if (ones == 0) {
            cout << 1 << endl;
        } else {
            cout << (2 << (ones - 1)) << endl;
        }
    }

    return 0;
}
