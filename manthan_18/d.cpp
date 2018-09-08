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

    size_t n;
    cin >> n;

    int v1, v2;
    vector<unordered_set<int>> tree(n);
    vector<int> theirTraversal;
    unordered_map<int, int> parents;
    unordered_map<int, int> childrenCount;

    for (size_t i = 0; i < n - 1; ++i) {
        cin >> v1 >> v2;
        tree[v1 - 1].insert(v2 - 1);

    }

    for (size_t i = 0; i < n; ++i) {
        cin >> v1;
        theirTraversal.push_back(v1 - 1);
    }

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        childrenCount[v] = tree[v].size();

        for (const auto& c: tree[v]) {
            parents[c] = v;
            q.push(c);
        }
    }

    parents[0] = 0;
    ++childrenCount[0];

    size_t cp = 0, pp = 0;

    while (cp < theirTraversal.size()) {
        auto v = theirTraversal[cp++];

        if (parents[v] != theirTraversal[pp]) {
            if (childrenCount[theirTraversal[pp]] > 0) {
                cout << "No" << endl;
                return 0;
            } else {
                while (childrenCount[theirTraversal[pp]] == 0 && pp < theirTraversal.size()) {
                    ++pp;
                }

                --childrenCount[theirTraversal[pp]];

                if (theirTraversal[pp] != parents[v]) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        } else {
            --childrenCount[theirTraversal[pp]];
        }
    }

    cout << "Yes" << endl;

    return 0;
}
