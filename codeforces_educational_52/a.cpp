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

    size_t t;
    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        long long s, a, b, c;
        cin >> s >> a >> b >> c;

        long long chocolatesCount = s / c;
        long long giftsCount = chocolatesCount / a;
        chocolatesCount += giftsCount * b;

        cout << chocolatesCount << endl;
    }

    return 0;
}
