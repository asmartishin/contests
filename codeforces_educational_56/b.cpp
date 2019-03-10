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
    string s;

    for (size_t i = 0; i < t; ++i) {
        map<char, size_t> charToCount;

        string s;
        cin >> s;

        for (const auto & c : s) {
            ++charToCount[c];
        }

        if (charToCount.size() <= 1) {
            cout << -1 << endl;
        } else {
            vector<char> result(s.size());

            auto it = charToCount.begin();
            auto rit = charToCount.rbegin();

            size_t l = 0;
            size_t r = s.size() - 1;

            while (l < r + 1) {
                result[l++] = it->first;
                result[r--] = rit->first;

                --it->second;
                --rit->second;

                if (it->second == 0) {
                    ++it;
                }

                if (rit->second == 0) {
                    ++rit;
                }
            }

            for (const auto & c : result) {
                cout << c;
            }
            cout << endl;
        }
    }

    return 0;
}
