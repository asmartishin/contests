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

using namespace std;

#define endl '\n'

void dfs(char v, int& timer, unordered_map<char, set<char>>& graph, unordered_map<char, bool>& visited, unordered_map<char, int>& exitTime, vector<char>& result) {
    visited[v] = true;

    if (graph.find(v) != graph.end()) {
        for (auto nb: graph[v]) {
            if (!visited[nb]) {
                dfs(nb, timer, graph, visited, exitTime, result);
            }
        }
    }

    exitTime[v] = timer++;
    result.push_back(v);
}

bool topSort(unordered_map<char, set<char>>& graph, const vector<pair<char, char>>& edges, vector<char>& result) {
    unordered_map<char, bool> visited;
    unordered_map<char, int> exitTime;

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

    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;

    vector<string> strings(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    vector<pair<char, char>> edges;

    for (size_t i = 0; i < n - 1; ++i) {
        auto& s1 = strings[i];
        auto& s2 = strings[i + 1];

        size_t i1 = 0;
        size_t i2 = 0;

        while (i1 < s1.size() && i2 < s2.size()) {
            if (s1[i1] == s2[i2]) {
                ++i1;
                ++i2;
            } else {
                edges.emplace_back(s2[i2], s1[i1]);
                break;
            }
        }

        if (i1 < s1.size() && i2 == s2.size()) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

//    for (const auto & [s, e]: edges) {
//        cout << s << ' ' << e << endl;
//    }

    unordered_map<char, set<char>> graph;

    for (size_t i = 0; i < 26; ++i) {
        graph['a' + i];
    }

    for (const auto & [s, e]: edges) {
        graph[s].insert(e);
    }

    vector<char> result;

    auto success = topSort(graph, edges, result);

//    cout << success << endl;

    if (success) {
        for (auto c : result) {
            cout << c;
        }
    } else {
        cout << "Impossible" << endl;
    }

//    for (const auto & s: strings) {
//        cout << s << endl;
//    }

    return 0;
}
