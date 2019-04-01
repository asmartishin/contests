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

int charToIdx(char c) {
    return (int)c - 97;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;
    string s;
    cin.ignore(1);

    for (size_t i = 0; i < n; ++i) {
        getline(cin, s);
        sort(begin(s), end(s));

        bool success = true;

        for (size_t j = 0; j < s.size() - 1; ++j) {
            if (charToIdx(s[j]) + 1 != charToIdx(s[j + 1])) {
                success = false;
            }
        }

        cout << (success ? "Yes" : "No") << endl;
    }


    return 0;
}
