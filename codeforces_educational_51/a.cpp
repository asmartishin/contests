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

    size_t t;
    cin >> t;

    for (size_t i = 0; i  < t; ++i) {
        string s;
        cin >> s;

        vector<size_t> upper;
        vector<size_t> lower;
        vector<size_t> number;

        for (size_t j = 0; j < s.size(); ++j) {
            if (isupper(s[j])) {
                upper.push_back(j);
            } else if (islower(s[j])) {
                lower.push_back(j);
            } else {
                number.push_back(j);
            }
        }

        size_t li = 0, ui = 0, ni = 0;

        if (upper.empty()) {
            if (lower.size() > 1) {
                s[lower[li++]] = 'A';
            } else {
                s[number[ni++]] = 'A';
            }
        }

        if (lower.empty()) {
            if (upper.size() > 1) {
                s[upper[ui++]] = 'a';
            } else {
                s[number[ni++]] = 'a';
            }
        }

        if (number.empty()) {
            if (upper.size() > 1) {
                s[upper[ui++]] = '1';
            } else {
                s[lower[li++]] = '1';
            }
        }

        cout << s << endl;
    }

    return 0;
}
