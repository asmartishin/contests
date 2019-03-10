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

    int x, y;
    vector<pair<int,int>> points;
    vector<int> xc;
    vector<int> yc;

    for (size_t i = 0; i < 3; ++i) {
        cin >> x >> y;
        xc.push_back(x);
        yc.push_back(y);
        points.emplace_back(y, x);
    }

    sort(begin(xc), end(xc));
    sort(begin(yc), end(yc));

    int result = (xc.back() - xc.front()) + (yc.back() - yc.front()) + 1;
    pair<int, int> cm{yc[1], xc[1]};

    set<pair<int, int>> removedCells{{cm.first, cm.second}};

    for (auto& p: points) {
        removedCells.emplace(p.first, p.second);

        while (p.first < cm.first) {
            removedCells.emplace(p.first++, p.second);
        }

        while (p.first > cm.first) {
            removedCells.emplace(p.first--, p.second);
        }

        while (p.second < cm.second) {
            removedCells.emplace(p.first, p.second++);
        }

        while (p.second > cm.second) {
            removedCells.emplace(p.first, p.second--);
        }
    }

    cout << result << endl;

    for (const auto& c: removedCells) {
        cout << c.second << ' ' << c.first << endl;
    }

    return 0;
}
