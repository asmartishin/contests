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

vector<int> delta_encode(vector<int> array) {
    if (array.empty()) {
        return {};
    }

    int currentNumber = array.front();
    vector<int> result{currentNumber};
    int diff;

    for (size_t i = 1; i < array.size(); ++i) {
        diff = array[i] - currentNumber;
        if (diff > 127 || diff < -127) {
            result.push_back(-128);
        }
        result.push_back(diff);
        currentNumber = array[i];
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;
    vector<int> v(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
    }

    auto result = delta_encode(v);

    for (auto i : result) {
        cout << i << endl;
    }
    cout << endl;

    return 0;
}
