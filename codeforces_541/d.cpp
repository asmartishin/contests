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

class UnionSet {
public:
    UnionSet(const size_t size) {
        Parent.resize(size);
        Rank.resize(size);
    }

    void MakeSet(const int element) {
        Parent[element] = element;
        Rank[element] = 0;
    }

    int Find(int element) {
        while (element != Parent[element]) {
            element = Parent[element];
        }
        return element;
    }

    void Union(const int firstElement, const int secondElement) {
        auto firstElementParent = Find(firstElement);
        auto secondElementParent = Find(secondElement);

        if (firstElementParent == secondElementParent) {
            return;
        }

        if (Rank[firstElementParent] > Rank[secondElementParent]) {
            Parent[secondElementParent] = firstElementParent;
        } else {
            Parent[firstElementParent] = secondElementParent;
            if (Rank[firstElementParent] == Rank[secondElementParent]) {
                ++Rank[secondElementParent];
            }
        }
    }
private:
    vector<int> Parent;
    vector<int> Rank;
};


void dfs(int v, int& timer, unordered_map<int, vector<int>>& graph, unordered_map<int, bool>& visited, unordered_map<int, int>& exitTime, vector<int>& result) {
    visited[v] = true;

    if (graph.find(v) != graph.end()) {
        for (auto nb: graph[v]) {
            if (!visited[nb]) {
                dfs(nb, timer, graph, visited, exitTime, result);
            }
        }
    }

    exitTime[v] = timer++;
}

void bfs(unordered_map<int, vector<int>>& graph, vector<int>& degree, vector<int>& result) {
    queue<int> q;
    for (size_t i = 0; i < degree.size(); ++i) {
        if (degree[i] == 0) {
            q.push(i);
            result[i] = 1;
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (graph.find(v) != graph.end()) {
            for (auto nb: graph[v]) {
                if (--degree[nb] == 0) {
                    result[nb] = result[v] + 1;
                    q.push(nb);
                }
            }
        }
    }
}

bool topSort(unordered_map<int, vector<int>>& graph, const vector<pair<int, int>>& edges, vector<int>& degree, vector<int>& result) {
    unordered_map<int, bool> visited;
    unordered_map<int, int> exitTime;

    for (const auto& [v, neighbours]: graph) {
        visited[v]= false;
        exitTime[v] = 0;
    }

    int timer = 0;

    for (const auto& [v, neighbours]: graph) {
        if (!visited[v]) {
            dfs(v, timer, graph, visited, exitTime, result);
        }
    }

    for (const auto & [start, end]: edges) {
        if (exitTime[start] <= exitTime[end]) {
            return false;
        }
    }

    bfs(graph, degree, result);

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, m;
    cin >> n >> m;

    UnionSet unionSet(n + m);
    for (size_t i = 0; i < n + m; ++i) {
        unionSet.MakeSet(i);
    }

    vector<vector<char>> matrix(n, vector<char>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == '=') {
                unionSet.Union(i, n + j);
            }
        }
    }

    vector<pair<int, int>> edges;
    vector<int> result(n + m);
    vector<int> degree(n + m);
    unordered_map<int, vector<int>> graph;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            int ip = unionSet.Find(i);
            int jp = unionSet.Find(n + j);

//            if (ip == jp) {
//                cout << "No" << endl;
//                return 0;
//            }

            if (matrix[i][j] == '<') {
                graph[ip].push_back(jp);
                edges.emplace_back(ip, jp);
                ++degree[jp];
            } else if (matrix[i][j] == '>') {
                graph[jp].push_back(ip);
                edges.emplace_back(jp, ip);
                ++degree[ip];
            }
        }
    }

    auto success = topSort(graph, edges, degree, result);

    if (!success) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for (size_t i = 0; i < n + m; ++i) {
        cout << result[unionSet.Find(i)] << ' ';
        if (i == n - 1) {
            cout << endl;
        }
    }

    cout << endl;

    return 0;
}
