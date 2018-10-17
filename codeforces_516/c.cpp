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

    int n;
    cin >> n;
    vector<char> s(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> s[i];
    }

    sort(begin(s), end(s));

    for (const auto& v: s) {
        cout << v;
    }

    cout << endl;

    return 0;
}
