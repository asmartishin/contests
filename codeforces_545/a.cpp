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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    size_t n;
    cin >> n;
    vector<pair<int, int>> sushi;
    pair<int, int> currentSushi{0, 0};

    int t;

    for (size_t i = 0; i < n; ++i) {
        cin >> t;
        if (t != currentSushi.first) {
            sushi.push_back(currentSushi);
            currentSushi = {t, 1};
        } else {
            ++currentSushi.second;
        }
    }

    sushi.push_back(currentSushi);

    int result = 0;

    for (size_t i = 1; i < sushi.size() - 1; ++i) {
        result = max(result, min(sushi[i].second, sushi[i + 1].second) * 2);
    }

    cout << result << endl;

    return 0;
}
