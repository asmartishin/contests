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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> powers(n);
    vector<int> schools(n);
    map<int, set<pair<int, int>, greater<pair<int, int>>>> schoolToStudents;
    vector<int> winners(k);

    for (size_t i = 0; i < n; ++i) {
        cin >> powers[i];
    }

    for (size_t i = 0; i < n; ++i) {
        cin >> schools[i];
        schoolToStudents[schools[i]].emplace(powers[i], i);
    }

    for (size_t i = 0; i < k; ++i) {
        cin >> winners[i];
        --winners[i];
    }

    set<int> defaultWinners;

    for (const auto& [school, students]: schoolToStudents) {
        defaultWinners.insert(students.begin()->second);
    }

    int result = k;

    for (auto w: winners) {
        if (defaultWinners.find(w) != defaultWinners.end()) {
            --result;
        }
    }

    cout << result << endl;

    return 0;
}
