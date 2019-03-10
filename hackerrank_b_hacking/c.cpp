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

int howManyAgentsToAdd(int noOfCurrentAgents, vector<vector<int>> callsTimes) {
    if (callsTimes.empty()) {
        return 0;
    }

    vector<pair<int, bool>> calls;

    for (const auto& v : callsTimes) {
        calls.emplace_back(v[0], true);
        calls.emplace_back(v[1], false);
    }

    sort(begin(calls), end(calls));

    int currentNumberOfRequiredAgents = 0;
    int maxNumberOfRequiredAgents = numeric_limits<int>::min();

    for (const auto& p : calls) {
        if (p.second == true) {
            ++currentNumberOfRequiredAgents;
        } else {
            --currentNumberOfRequiredAgents;
        }
        maxNumberOfRequiredAgents = max(maxNumberOfRequiredAgents, currentNumberOfRequiredAgents);
    }

    if (noOfCurrentAgents >= maxNumberOfRequiredAgents) {
        return 0;
    }

    return maxNumberOfRequiredAgents - noOfCurrentAgents;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int x, n, m;
    int start, end;

    cin >> x >> n >> m;
    vector<vector<int>> calls(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> start >> end;
        calls[i].push_back(start);
        calls[i].push_back(end);
    }

    cout << howManyAgentsToAdd(x, calls) << endl;

    return 0;
}
