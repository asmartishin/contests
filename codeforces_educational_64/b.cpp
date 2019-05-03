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

    int T;
    cin >> T;

    for (size_t t = 0; t < T; ++t) {
        string s;
        cin >> s;

        string sOdd;
        string sEven;

        for (const auto & c: s) {
            if ((c - 'a') % 2 == 0) {
                sEven += c;
            } else {
                sOdd += c;
            }
        }

        sort(begin(sEven), end(sEven));
        sort(begin(sOdd), end(sOdd));

        if (abs((sEven.back() - 'a') - (sOdd.front() - 'a')) > 1) {
            cout << sEven + sOdd << endl;
        } else if (abs((sEven.front() - 'a') - (sOdd.back() - 'a')) > 1) {
            cout << sOdd + sEven << endl;
        } else {
            cout << "No answer" << endl;
        }
    }

    return 0;
}
