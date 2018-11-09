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

    int n, x, y;
    char command;
    vector<pair<int, int>> commands;

    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> command;
        if (command == 'U') {
            commands.emplace_back(0, 1);
        } else if (command == 'D') {
            commands.emplace_back(0, -1);
        } else if (command == 'L') {
            commands.emplace_back(-1, 0);
        } else {
            commands.emplace_back(1, 0);
        }
    }

    cin >> x >> y;

    int d = abs(x) + abs(y);

    if (d > n) {
        cout << -1 << endl;
        return 0;
    } else if (d % 2 != n % 2) {
        cout << -1 << endl;
        return 0;
    }

    int l = 0, r = n;

    while (l < r) {
        int len = (l + r) / 2;

        pair<int, int> pos{0, 0};

        for (size_t i = len; i < n; ++i) {
            pos.first += commands[i].first;
            pos.second += commands[i].second;
        }

        int li = 0, ri = len;
        bool success = false;

        while (true) {
            int dist = abs(pos.first - x) + abs(pos.second - y);

            if (dist % 2 == len % 2 && len >= dist) {
                success = true;
                break;
            }

            if (ri == n) {
                break;
            }

            pos.first += commands[li].first;
            pos.second += commands[li++].second;

            pos.first -= commands[ri].first;
            pos.second -= commands[ri++].second;
        }

        if (success) {
            r = len;
        } else {
            l = len + 1;
        }
    }

    cout << r << endl;

    return 0;
}
