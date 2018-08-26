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
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'

int getResult(int id, vector<int>& cycles, vector<int>& outgoingEdges) {
    if (cycles[id] == id) {
        return id;
    } else {
        cycles[id] = getResult(outgoingEdges[id], cycles, outgoingEdges);
        return cycles[id];
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, outgoingEdge;
    cin >> n;

    vector<int> outgoingEdges(n);
    vector<int> incomingEdgesCount(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> outgoingEdge;
        --outgoingEdge;
        outgoingEdges[i] = outgoingEdge;
        ++incomingEdgesCount[outgoingEdge];
    }

    vector<int> cycles(n);
    for (size_t i = 0; i < n; ++i) {
        cycles[i] = i;
    }

    queue<int> q;
    for (size_t i = 0; i < n; ++i) {
        if (incomingEdgesCount[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        cycles[v] = outgoingEdges[v];
        --incomingEdgesCount[outgoingEdges[v]];

        if (incomingEdgesCount[outgoingEdges[v]] == 0) {
            q.push(outgoingEdges[v]);
        }
    }

    for (size_t i = 0; i < n; ++i) {
        cout << getResult(i, cycles, outgoingEdges) + 1 << endl;
    }

    return 0;
}
