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
#include <optional>

using namespace std;

#define endl '\n'

using Possibilities = unordered_set<pair<int, int>>;

namespace std {
    template<>
    struct hash<std::pair<int, int> > {
        size_t operator()(const std::pair<int, int> &p) const {
            return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
        }
    };
}

optional<vector<pair<int, int>>> setIntersection(const Possibilities& firstSet, const Possibilities& secondSet) {
    vector<pair<int, int>> result;
    for (const auto& el: firstSet) {
        if (secondSet.find(el) != secondSet.end()) {
            result.push_back(el);
        }
    }

    if (!result.empty()) {
        return result;
    }

    return {};
}

void hardSolution() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    vector<int> b(n - 1);
    vector<int> t(n);

    array<Possibilities, 4> orPossibility = {{
        {{0, 0}},
        {{0, 1}, {1, 1}},
        {{0, 2}, {2, 2}},
        {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {1, 2}}
    }};

    array<Possibilities, 4> andPossibility = {{
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 2}},
        {{1, 1}, {1, 3}},
        {{2, 2}, {2, 3}},
        {{3, 3}}
    }};

    for (size_t i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }

    for (size_t i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    bool found = false;

    auto possibility = setIntersection(orPossibility[a[0]], andPossibility[b[0]]);

    if (possibility) {
        for (auto p: *possibility) {
            for (auto ti: {p.first, p.second}) {
                found = true;
                t[0] = ti;

                for (size_t i = 0; i < n - 1; ++i) {
                    auto possibility  = setIntersection(orPossibility[a[i]], andPossibility[b[i]]);
                    if (possibility) {
                        found = false;
                        for (auto p: *possibility) {
                            if (t[i] == p.first) {
                                t[i + 1] = p.second;
                                found = true;
                                break;
                            } else if (t[i] == p.second) {
                                t[i + 1] = p.first;
                                found = true;
                                break;
                            }
                        }

                        if (!found) {
                            break;
                        }
                    } else {
                        found = false;
                        break;
                    }
                }

                if (found) {
                    cout << "YES" << endl;
                    for (const auto& v: t) {
                        cout << v  << ' ';
                    }
                    cout << endl;
                    return;
                }
            }
        }
    }

    cout << "NO" << endl;
}

void easySolution() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    vector<int> b(n - 1);
    vector<int> t(n);

    for (size_t i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }

    for (size_t i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    for (size_t i = 0; i <= 3; ++i) {
        t[0] = i;

        bool found;

        for (size_t j = 0; j < n - 1; ++j) {
            found = false;
            for (int k = 0; k <= 3; ++k) {
                if (a[j] == (t[j]|k) && b[j] == (t[j]&k)) {
                    t[j + 1] = k;
                    found = true;
                }
            }

            if (!found) {
                break;
            }
        }

        if (found) {
            cout << "YES" << endl;
            for (const auto& v: t) {
                cout << v  << ' ';
            }
            cout << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    easySolution();

    return 0;
}
