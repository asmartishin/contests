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


bool dfsIsCycle(vector<unordered_set<int> > &graph, set<int> &remainingVertices, int startVertex) {
    unordered_set<int> processedVertices;
    stack<pair<int, int>> vertices;
    bool cycle = false;

    vertices.push(make_pair(startVertex, startVertex));
    processedVertices.insert(startVertex);

    while (!vertices.empty()) {
        auto currentVertex = vertices.top();
        vertices.pop();
        remainingVertices.erase(currentVertex.first);

        for (const auto &neighbourVertex: graph[currentVertex.first]) {
            if (neighbourVertex == currentVertex.second) {
                continue;
            }

            if (processedVertices.find(neighbourVertex) != processedVertices.end()) {
                cycle = true;
            } else {
                vertices.push(make_pair(neighbourVertex, currentVertex.first));
                processedVertices.insert(neighbourVertex);
            }
        }

    }

    return cycle;
}


int countCycleComponents(vector<unordered_set<int> > &graph) {
    set<int> remainingVertices;
    int result = 0;

    for (size_t i = 0; i < graph.size(); ++i)
        remainingVertices.insert(i);

    while (!remainingVertices.empty()) {
        int startVertex = *remainingVertices.begin();
        if (dfsIsCycle(graph, remainingVertices, startVertex)) {
            ++result;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, m, v, u;

    cin >> n >> m;

    vector<unordered_set<int> > graph(n);

    for (size_t i = 0; i < m; ++i) {
        cin >> v >> u;
        --v;
        --u;
        graph[v].insert(u);
        graph[u].insert(v);
    }

    cout << countCycleComponents(graph) << endl;

    return 0;
}
