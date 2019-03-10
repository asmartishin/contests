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

    int n, k;
    string s;
    cin >> n >> k;
    vector<int> a(n);

//    unordered_map<char, vector<int>> punches;

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> s;

    multiset<int, greater<int>> currentPunches{a[0]};
    char currentLetter = s[0];

    long long result = 0;

    for (size_t i = 1; i < n; ++i) {
        if (s[i] != currentLetter) {
            currentLetter = s[i];

            auto it = currentPunches.begin();
            for (size_t j = 0; j < k && it != currentPunches.end(); ++j, ++it) {
                result += *it;
            }

            currentPunches.clear();
        }

        currentPunches.insert(a[i]);
    }

    auto it = currentPunches.begin();
    for (size_t j = 0; j < k && it != currentPunches.end(); ++j, ++it) {
        result += *it;
    }

    cout << result << endl;

    return 0;
}
