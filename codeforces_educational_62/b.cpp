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

    int t, n;
    string s;

    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        cin >> n;
        cin.ignore(1);
        getline(cin, s);
        if (s.size() == 1) {
            cout << 0 << endl;
        } else if (s.front() == '<' && s.back() == '>') {
            size_t result = n - 1;
            for (size_t i = 0; i < n - 1; ++i) {
                if (s[i] != s[i + 1]) {
                    result = min({result, i + 1, n - (i + 1)});
                }
            }
            cout << result << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
