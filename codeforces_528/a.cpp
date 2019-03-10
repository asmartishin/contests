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

    string s;
    cin >> s;

    size_t m;

    if (s.size() == 0) {
        m = 0;
    } else if (s.size() % 2 == 0) {
        m = s.size() / 2 - 1;
    } else {
        m = s.size() / 2;
    }

    size_t l = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            cout << s[m - l];
            ++l;
        } else {
            cout << s[m + l];
        }
    }

    cout << endl;

    return 0;
}
