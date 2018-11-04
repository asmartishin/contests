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
    string s;
    char c1, c2;

    cin >> n >> s;
    c1 = c2 = s[0];

    for (size_t i = 0; i < n; ++i) {
        if (s[i] != c1) {
            c2 = s[i];
            break;
        }
    }

    if (c1 == c2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << c1 << c2 << endl;
    }

    return 0;
}
