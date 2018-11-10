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

    int n, s;

    cin >> n >> s;
    --s;

    vector<int> firstLane(n);
    vector<int> secondLane(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> firstLane[i];
    }

    for (size_t i = 0; i < n; ++i) {
        cin >> secondLane[i];
    }

    bool success = false;

    if (firstLane[0] == 1 && firstLane[s] == 1) {
        success = true;
    } else if (firstLane[0] == 1 && secondLane[s] == 1) {
        for (size_t i = s; i < n; ++i) {
            if (firstLane[i] == 1 && secondLane[i] == 1) {
                success = true;
            }
        }
    }

    if (success) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
