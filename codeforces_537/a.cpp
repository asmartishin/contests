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

    string s, t;

    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

    cin >> s >> t;

    if (s.size() != t.size()) {
        cout << "No" << endl;
        return 0;
    }

    for (size_t i = 0; i < s.size(); ++i) {
        bool sv = (vowels.find(s[i]) != vowels.end());
        bool tv = (vowels.find(t[i]) != vowels.end());

        if (sv != tv) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
