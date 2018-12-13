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

    int n;
    long long s;

    cin >> n >> s;
    vector<int> v(n);

    long long sum = 0;

    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }

    if (sum < s) {
        cout << -1 << endl;
        return 0;
    }

    auto minValue = *min_element(begin(v), end(v));

    long long sumToMinValue = 0;

    for (size_t i = 0; i < n; ++i) {
        if (v[i] > minValue) {
            sumToMinValue += v[i] - minValue;
        }
    }

    if (sumToMinValue >= s) {
        cout << minValue << endl;
    } else {
        cout << minValue - ceil((s - sumToMinValue) / (double)n) << endl;
    }

    return 0;
}
