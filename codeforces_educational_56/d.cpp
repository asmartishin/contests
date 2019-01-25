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

static const long long MOD = 998244353;

using Graph = vector<vector<int>>;

enum class Type {
    Odd,
    Even,
    Unknown
};

void Clear(Graph& graph) {
    for (auto& v: graph) {
        v.clear();
    }
}

template <typename T>
T modpow(T n, T p, T mod) {
    n %= mod;
    T result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * n) % mod;
        }
        n = (n * n) % mod;
        p >>= 1;
  }

  return result;
}

bool Dfs(Graph& graph, size_t startVertex, set<size_t>& nodes, long long& result) {
    long long oddCount = 1;
    long long evenCount = 0;
    unordered_map<size_t, Type> visited;
    stack<size_t> vertexStack;
    vertexStack.push(startVertex);

    visited[startVertex] = Type::Odd;

    while (!vertexStack.empty()) {
        auto vertex = vertexStack.top();
        vertexStack.pop();

        auto newType = (visited[vertex] == Type::Odd ? Type::Even : Type::Odd);

        for (size_t i = 0; i < graph[vertex].size(); ++i) {
            if (visited.find(graph[vertex][i]) == visited.end()) {
                if (newType == Type::Odd) {
                    ++oddCount;
                } else {
                    ++evenCount;
                }
                vertexStack.push(graph[vertex][i]);
                visited[graph[vertex][i]] = newType;
            } else if (visited[graph[vertex][i]] == visited[vertex]) {
                return false;
            }
        }
        nodes.erase(vertex);
    }

    result = (result * ((modpow(2LL, oddCount, MOD) + modpow(2LL, evenCount, MOD)) % MOD)) % MOD;

    return true;
}

int Solve(Graph& graph) {
    long long result = 1;
    set<size_t> nodes;
    for (size_t i = 0; i < graph.size(); ++i) {
        nodes.insert(i);
    }
    while (!nodes.empty()) {
        auto v = *nodes.begin();

        if (!Dfs(graph, v, nodes, result)) {
            return 0;
        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    size_t t;
    cin >> t;

    int n, m;
    size_t u, v;

    Graph graph;

    for (size_t i = 0; i < t; ++i) {
        cin >> n >> m;
        graph.resize(n);

        for (size_t j = 0; j < m; ++j) {
            cin >> u >> v;
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }

        cout << Solve(graph) << endl;
        Clear(graph);
    }

    return 0;
}
